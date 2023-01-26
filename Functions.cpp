#include "Functions.h"

#ifndef RPI
void delay (unsigned long int v) {usleep(v*1000);}
void delayMicroseconds (unsigned long int v) {usleep(v) ; }
void digitalWrite(const uint8_t p, bool v) {}
uint8_t digitalRead(const uint8_t p) {return HIGH;}
void pinMode (const uint8_t p, bool type) {}
#endif
void delay_ms (unsigned long int v) {usleep(v*1000);}

uint8_t bitRead  (uint8_t buffer, int bit) {return (buffer>>bit)&1 ; }
void bitSet   (uint8_t & buffer, int bit) {buffer |= (1<<bit); }
void bitClear (uint8_t & buffer, int bit) {buffer &= ~(1<<bit) ; }

int map(int v, int m1, int M1, int m2, int M2)
{
  float ratio = (v - m1)/(float)(M1-m1) ;
  return ( m2 + ratio * (M2-m2) ) ; 
}
//-----------------------------------------------------------------------------
void eInk2display (Uint32 *display, uint8_t *black, uint8_t *red)
{
  for (int i=0 ; i<W ; i++)
    for (int j=0 ; j<H ; j++)
    {
      bool b, r ; 
      int id = j*W+(W-(i+1)) ; 
      int idink = i*H+j ; 
      b = black[idink/8]>>(7-idink%8) & 1 ; 
      r = red  [idink/8]>>(7-idink%8) & 1 ;
      if (r) display[id] = 0x80<<16 ; 
      else if (b) display[id] = 0 ;  
      else        display[id] = 0xff<<24 | 0xcc<<16 | 0xcc<<8 | 0xcc ; 
    }
}
//------------------------------------------------------------------------------
void display2eInk (uint8_t *img, uint8_t *black, uint8_t *red)
{
  for (int i=0 ; i<W*H/8 ; i++)
  {
    black[i]=0 ; red[i]=0;
  }
  for (int i=0 ;i<W ; i++)
  {
    for (int j=0 ; j<H ; j++)
    {
      if (img[(W-i+1)*H+j]==1)
      {
        bitSet(black[(i*H+j)/8], 7-(i*H+j)%8) ;  
        bitClear(red[(i*H+j)/8], 7-(i*H+j)%8) ;  
      }
      else if (img[(W-i+1)*H+j]==2)
        bitSet(red[(i*H+j)/8], 7-(i*H+j)%8) ;  
      else
      { 
        bitClear(black[(i*H+j)/8], 7-(i*H+j)%8) ; 
        bitClear(red[(i*H+j)/8], 7-(i*H+j)%8) ;  
      }
    }
  }
}
//------------------------------------------------------------------------------
void Sierpinski ()
{
    for (int i=0 ; i<W*H ; i++) img[i/H][i%H]=0 ; 
    img[0][H/2]=1 ; 
    for (int i=1 ; i<W ; i++) 
    {
        for (int j=0 ; j<H ; j++) 
        {
            int n = (img[i-1][(j+H-1)%H]>0?1:0) + (img[i-1][(j%H)]>0?1:0) + (img[i-1][(j+1)%H]>0?1:0) ;  
            if (n==1 || n==2) 
                img[i][j]=1 ; 
            else if (n==3)
                img[i][j]=0 ; 
            else 
                img[i][j]=0 ; 
        }
    }
    display2eInk (&(img[0][0]), myScreen.blackimg(), myScreen.redimg()) ; 
}
//------------------------------------------------------------------------------
void Paragraph (int x, int y, String s, uint16_t colour, uint16_t bgcolour)
{
    myScreen.selectFont(Font_Terminal8x12);
    int beg=0 ;
    int charwidth = 8; int charheight = 12 ; 
    int avail = (W-x)/charwidth ;
    
    while (beg<s.length() && y<H-charheight)
    {
        for ( ; beg<s.length() && s[beg]==' ' ; beg++) ; if (beg>= s.length()) break ; 
        
        String str = s.substr(beg, min(s.length(), avail)) ;
        
        auto newline = std::find (str.begin(), str.end(), '\n') ; 
        if (newline==str.end()) // No newline
        {
            if (s.length()-beg > str.length())
            {
                int i ; 
                for (i=str.length()-1; i>=avail/3 && str[i]!=' ' ; i--) ; 
                if (i>=avail/3) str=str.substr(0, i) ;
            }
        }
        else
        {
            str=str.substr(0, newline-str.begin()) ; 
            beg++ ; 
        }
        
        myScreen.gText(x, y, str, colour, bgcolour) ;
        y += charheight ;  
        beg += str.length() ; 
    }   
}
//------------------------------------------------------------------------------
void Paragraph_freetype (int fontsize, int x0, int y0, int line_end_x, int ymax, String s, uint16_t color, uint16_t bgcolor)
{ 
  if (color==myColours.white) color=0 ; 
  else if (color==myColours.black) color=1 ; 
  else if (color==myColours.red) color=2 ; 
  if (bgcolor==myColours.white) bgcolor=0 ; 
  else if (bgcolor==myColours.black) bgcolor=1 ; 
  else if (bgcolor==myColours.red) bgcolor=2 ; 
  
  FT_Library  library;
  FT_Face     face_reg, face_it, face_bold ;
  FT_Face * face ; 
  auto error = FT_Init_FreeType( &library );
  if ( error ) {printf("Error initialising FreeType") ; }
  error = FT_New_Face(library, "/usr/share/fonts/truetype/liberation/LiberationSerif-Regular.ttf", 0, &face_reg );
  if ( error ){ printf("Problem loading the font\n") ; }  
  error = FT_Set_Char_Size(face_reg, 0, fontsize*64, DPI, DPI); 
  error = FT_New_Face(library, "/usr/share/fonts/truetype/liberation/LiberationSerif-Italic.ttf", 0, &face_it );
  if ( error ){ printf("Problem loading the italic font\n") ; }  
  error = FT_Set_Char_Size(face_it, 0, fontsize*64, DPI, DPI); 
  error = FT_New_Face(library, "/usr/share/fonts/truetype/liberation/LiberationSerif-Bold.ttf", 0, &face_bold );
  if ( error ){ printf("Problem loading the bold font\n") ; }  
  error = FT_Set_Char_Size(face_bold, 0, fontsize*64, DPI, DPI); 
      
  int line_beginning_x=x0 ; 
  int cursor_x=line_beginning_x, cursor_y=y0 ;
  int beg=0, lastspace=-1, lastspace_x=cursor_x ; 
  int lineheight= face_reg->size->metrics.height >>6; 
  bool isbold=false, isitalic=false ; 
  bool lastspace_bold = isbold, lastspace_it=isitalic ; 
  
  face = &face_reg ; 
  
  for (int i=0 ; i<s.length() ; i++)
  {
    if (s[i]=='\n') 
    {
        cursor_x = line_beginning_x ; 
        cursor_y+= lineheight ;
        lastspace = -1 ; 
    }
    else if (s[i]=='*' || s[i]=='_')
    {
        if (s[i+1]==s[i])
        {
            if (isbold) {face = &face_reg ; isbold=false ; }
            else {face = &face_bold ; isbold=true ; }
            i++ ; 
        }
        else
        {
            if (isitalic) {face = &face_reg ; isitalic=false ; }
            else {face = &face_it ; isitalic=true ; }
        }
            
    }
    else
    {
        if (s[i]==' ') {lastspace = i ; lastspace_x = cursor_x ; lastspace_bold = isbold ; lastspace_it=isitalic ; }
        FT_UInt glyph_index = FT_Get_Char_Index( *face, s[i]) ; 
        error = FT_Load_Glyph( *face, glyph_index, FT_LOAD_DEFAULT );
        error=FT_Render_Glyph( (*face)->glyph, FT_RENDER_MODE_MONO ); 
        if (cursor_x + (*face)->glyph->bitmap_left + (*face)->glyph->bitmap.width >= line_end_x) // Need to backtrack
        {
            if (lastspace != -1)
            {
                for (int i=lastspace_x ; i<line_end_x ; i++)
                    for (int j=-((*face)->size->metrics.ascender>>6) ; j<-((*face)->size->metrics.descender>>6) ; j++)
                    {
                        if (cursor_y+j < 0 || cursor_y+j>=H) continue ; 
                        img[i][cursor_y+j]=bgcolor ; 
                    }
                i=lastspace ; 
                lastspace=-1 ;
                isbold=false; isitalic=false ;
                if (lastspace_bold)    {face = &face_bold ; isbold=true ; }
                else if (lastspace_it) {face = &face_it ; isitalic=true ; } 
                else {face = &face_reg ;} 
                
            }
            else
                i-- ; 
            cursor_x = line_beginning_x ; 
            cursor_y += lineheight ;
        }
        else
        { 
          for (int i=0 ; i<(*face)->glyph->bitmap.rows ; i++)
            for (int j=0 ; j<(*face)->glyph->bitmap.width ; j++)
            {
                if (cursor_x+(*face)->glyph->bitmap_left+j<0 || cursor_x+(*face)->glyph->bitmap_left>=W 
                    || cursor_y-(*face)->glyph->bitmap_top+i<0 || cursor_y-(*face)->glyph->bitmap_top+i>=H) continue ; 
                img[cursor_x+(*face)->glyph->bitmap_left+j][cursor_y-(*face)->glyph->bitmap_top+i] = bitRead((*face)->glyph->bitmap.buffer[(*face)->glyph->bitmap.pitch*i+j/8], 7-j%8) ? color : bgcolor ; 
            }
          cursor_x += (*face)->glyph->advance.x>>6 ; 
        }
    }
  }
  display2eInk (&(img[0][0]), myScreen.blackimg(), myScreen.redimg()) ; 
}
