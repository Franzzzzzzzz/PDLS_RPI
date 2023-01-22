#include "Dummy.h"

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



void eInk2display (Uint32 *display, uint8_t *black, uint8_t *red, int W, int H)
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

void display2eInk (uint8_t *img, uint8_t *black, uint8_t *red, int W, int H)
{
  for (int i=0 ; i<W*H/8 ; i++)
  {
    black[i]=0 ; red[i]=0;
  }
  for (int i=0 ;i<W ; i++)
  {
    for (int j=0 ; j<H ; j++)
    {
      if (img[i*H+j]==1)
      {
        bitSet(black[(i*H+j)/8], 7-(i*H+j)%8) ;  
        bitClear(red[(i*H+j)/8], 7-(i*H+j)%8) ;  
      }
      else if (img[i*H+j]==2)
        bitSet(red[(i*H+j)/8], 7-(i*H+j)%8) ;  
      else
      { 
        bitClear(black[(i*H+j)/8], 7-(i*H+j)%8) ; 
        bitClear(red[(i*H+j)/8], 7-(i*H+j)%8) ;  
      }
    }
  }
}
