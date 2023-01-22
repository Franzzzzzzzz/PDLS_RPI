///
/// @file Common_Colours.ino
/// @brief Example of features for basic edition
///
/// @details Project Pervasive Displays Library Suite
/// @n Based on highView technology
///
/// @author Rei Vilo
/// @date 21 Nov 2022
/// @version 602
///
/// @copyright (c) Rei Vilo, 2010-2023
/// @copyright Creative Commons Attribution-ShareAlike 4.0 International (CC BY-SA 4.0)
///
/// @see ReadMe.txt for references
/// @n
///

// Set parameters
// Include application, user and local libraries
// SDK

#include <cstdlib>
#include <cstdio>
#include <unistd.h>
#include <algorithm>
#include <SDL2/SDL.h>

#include "PDLS_EXT3_Basic.h"
// Define structures and classes

// Define variables and constants
// Screen_EPD_EXT3 myScreen(eScreen_EPD_EXT3_154, boardRaspberryPiPico_RP2040);
// Screen_EPD_EXT3 myScreen(eScreen_EPD_EXT3_213, boardRaspberryPiPico_RP2040);
// Screen_EPD_EXT3 myScreen(eScreen_EPD_EXT3_266, boardRaspberryPiPico_RP2040);
// Screen_EPD_EXT3 myScreen(eScreen_EPD_EXT3_271, boardRaspberryPiPico_RP2040);
// Screen_EPD_EXT3 myScreen(eScreen_EPD_EXT3_287, boardRaspberryPiPico_RP2040);
//Screen_EPD_EXT3 myScreen(eScreen_EPD_EXT3_370, boardRaspberryPiPico_RP2040);
// Screen_EPD_EXT3 myScreen(eScreen_EPD_EXT3_417, boardRaspberryPiPico_RP2040);
Screen_EPD_EXT3 myScreen(eScreen_EPD_EXT3_437, boardRaspberryPi3B);
// Screen_EPD_EXT3 myScreen(eScreen_EPD_EXT3_565, boardRaspberryPiPico_RP2040);
// Screen_EPD_EXT3 myScreen(eScreen_EPD_EXT3_581, boardRaspberryPiPico_RP2040);
// Screen_EPD_EXT3 myScreen(eScreen_EPD_EXT3_741, boardRaspberryPiPico_RP2040);
// Screen_EPD_EXT3 myScreen(eScreen_EPD_EXT3_969, boardRaspberryPiPico_RP2040);
// Screen_EPD_EXT3 myScreen(eScreen_EPD_EXT3_B98, boardRaspberryPiPico_RP2040);


// Functions
///
/// @brief Palette test screen
/// @param flag true = default = perform flush, otherwise no
///
/// @image html T2_PALET.jpg
/// @image latex T2_PALET.PDF width=10cm
///
void displayPalette(bool flag = true)
{

    /*uint16_t x0, y0, dx, dy, maxSize, colour;
    maxSize = min((myScreen.screenSizeX() * 10 / 50), (myScreen.screenSizeY() * 10 / 35));
    dx = (myScreen.screenSizeX() - maxSize * 50 / 10) / 2;
    dy = (myScreen.screenSizeY() - maxSize * 35 / 10) / 2;

    y0 = dy + maxSize / 2;
    x0 = dx + maxSize / 2;
    myScreen.dRectangle(x0 - 2, y0 - 2, maxSize + 4, maxSize + 4, myColours.red);
    x0 = dx + maxSize * 4 / 2;
    myScreen.dRectangle(x0 - 2, y0 - 2, maxSize + 4, maxSize + 4, myColours.red);
    x0 = dx + maxSize * 7 / 2;
    myScreen.dRectangle(x0 - 2, y0 - 2, maxSize + 4, maxSize + 4, myColours.red);

    y0 = dy + maxSize * 4 / 2;
    x0 = dx + maxSize / 2;
    myScreen.dRectangle(x0 - 2, y0 - 2, maxSize + 4, maxSize + 4, myColours.black);
    x0 = dx + maxSize * 4 / 2;
    myScreen.dRectangle(x0 - 2, y0 - 2, maxSize + 4, maxSize + 4, myColours.black);
    x0 = dx + maxSize * 7 / 2;
    myScreen.dRectangle(x0 - 2, y0 - 2, maxSize + 4, maxSize + 4, myColours.black);

    myScreen.setPenSolid();
    myScreen.selectFont(Font_Terminal6x8);

    x0 = dx + maxSize / 2;
    y0 = dy + maxSize / 2;
    // Light red
    myScreen.dRectangle(x0, y0, maxSize, maxSize, myColours.lightRed);
    myScreen.gText(x0, y0 + maxSize + 6, "light", myColours.red);

    x0 = dx + maxSize * 4 / 2;
    y0 = dy + maxSize / 2;
    // Red
    myScreen.dRectangle(x0, y0, maxSize, maxSize, myColours.red);
    myScreen.gText(x0, y0 + maxSize + 6, "red", myColours.red);

    x0 = dx + maxSize * 7 / 2;
    y0 = dy + maxSize / 2;
    // Dark-red
    myScreen.dRectangle(x0, y0, maxSize, maxSize, myColours.darkRed);
    myScreen.gText(x0, y0 + maxSize + 6, "dark", myColours.red);

    x0 = dx + maxSize / 2;
    y0 = dy + maxSize * 4 / 2;
    // White
    myScreen.dRectangle(x0, y0, maxSize, maxSize, myColours.white);
    myScreen.gText(x0, y0 + maxSize + 6, "white", myColours.black);

    x0 = dx + maxSize * 4 / 2;
    y0 = dy + maxSize * 4 / 2;
    // Grey
    myScreen.dRectangle(x0, y0, maxSize, maxSize, myColours.grey);
    myScreen.gText(x0, y0 + maxSize + 6, "grey", myColours.black);

    x0 = dx + maxSize * 7 / 2;
    y0 = dy + maxSize * 4 / 2;
    // Black
    myScreen.dRectangle(x0, y0, maxSize, maxSize, myColours.black);
    myScreen.gText(x0, y0 + maxSize + 6, "black", myColours.black);*/

    myScreen.selectFont(Font_Terminal8x12);
    //myScreen.gText(0, 0, "21/01/2022            It was natural to form a pyramide – well, a cone, anyway. He’d experimented this morning. Grain, salt, sand … not water, though, that’d been a mistake. But a pyramid was only a neat cone, wasn’t it, a cone which had decided to be a bit tidier. Pyramids, Terry Pratchett" , myColours.black);
    myScreen.gText(10, 0, "It was natural to form a pyramide", myColours.red) ; 
    myScreen.gText(10, 12, "- well, a cone, anyway. He'd experimented this morning.", myColours.red) ;
    myScreen.gText(10, 24, "Grain, salt, sand ... not water, though,", myColours.red) ;
    myScreen.gText(10, 36, "that'd been a mistake.", myColours.red) ;
    myScreen.gText(10, 48, "But a pyramid was only a neat cone, wasn't it,", myColours.red) ;
    myScreen.gText(10, 60, "a cone which had decided to be a bit tidier.", myColours.red) ;
    myScreen.gText(10, 84, "Pyramids, Terry Pratchett", myColours.black) ;
    
    
    myScreen.flush();
}


// Add setup code
///
/// @brief Setup
///
#define W 480 
#define H 176
unsigned char black[W*H/8] ; 
unsigned char red[W*H/8] ; 
Uint32 display[W*H] ; 

uint8_t img[W][H] ;
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
    display2eInk (&(img[0][0]), myScreen.blackimg(), myScreen.redimg(), W, H) ; 
}

void Paragraph (int x, int y, String s, uint16_t colour, uint16_t bgcolour=myColours.white)
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



// void paragraph (Screen_EPD_EXT3 & scr, uint16_t x, uint16_t y, String s, uint16_t colour)
// {
//     length=(W-x)/scr._f_characterSizeX() ; 
//     
//     
// }

//=======================================
int main (int argc, char * argv[])
{
  if( SDL_Init(SDL_INIT_VIDEO) < 0 ) { fprintf(stderr, "Couldn't initialize SDL: %s\n", SDL_GetError()); exit(1);}
  atexit(SDL_Quit);
  SDL_Window *sdlWindow = SDL_CreateWindow("eInk Display", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, W, H, 0x00);
  SDL_SetWindowBordered(sdlWindow, SDL_TRUE );
  SDL_Renderer *sdlRenderer = SDL_CreateRenderer(sdlWindow, -1, 0);
  SDL_Texture *sdlTexture = SDL_CreateTexture(sdlRenderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, W, H);
      
  myScreen.begin();
  myScreen.clear();
  myScreen.setOrientation(3);
  //displayPalette();
  //Sierpinski() ; 
  Paragraph(57,11, "Lorem ipsum dolor sit amet, consectetur\nadipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea\n\ncommodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum. abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz", myColours.black, myColours.red) ; 
  
  //myScreen.clear();
  #ifdef RPI
      myScreen.flush();
  #endif
    
  eInk2display(display, myScreen.blackimg(), myScreen.redimg(), W, H) ; 
  SDL_UpdateTexture(sdlTexture, NULL, display, W * sizeof (Uint32));
  SDL_RenderClear(sdlRenderer);
  SDL_RenderCopy(sdlRenderer, sdlTexture, NULL, NULL);
  SDL_RenderPresent(sdlRenderer);
    
  SDL_Event e;
  for (;;) {
    SDL_PollEvent(&e);
    if (e.type == SDL_QUIT) {
        break;
    }
  }
  
}
