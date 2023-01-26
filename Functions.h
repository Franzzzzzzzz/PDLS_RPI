#include <cstdint>
#include <cstring>
#include <string>
#include <unistd.h>
#include <cmath>
#include <SDL2/SDL.h>
#include <freetype2/ft2build.h>
#include <algorithm>

using String=std::string ; 

#ifndef DUMMY
#define DUMMY

#include "Screen_EPD_EXT3.h"
#include "hV_Colours565.h"
#include FT_FREETYPE_H

#define HIGH 1
#define LOW 0 
#define OUTPUT 1
#define INPUT 0
#define PI M_PI

#define W 480 
#define H 176
#define DPI 117

extern unsigned char black[W*H/8] ; 
extern unsigned char red[W*H/8] ; 
extern Uint32 display[W*H] ; 
extern class Screen_EPD_EXT3 myScreen ;
extern class hV_Colours565 myColours;

extern uint8_t img[W][H] ;

#ifndef RPI
void delay (unsigned long int v) ;
void delayMicroseconds (unsigned long int v) ;
void digitalWrite(const uint8_t p, bool v) ;
uint8_t digitalRead(const uint8_t p) ;
void pinMode (const uint8_t p, bool type) ;
#endif
void delay_ms (unsigned long int v) ;

uint8_t bitRead  (uint8_t buffer, int bit) ;
void bitSet   (uint8_t & buffer, int bit) ;
void bitClear (uint8_t & buffer, int bit) ;

int map(int v, int m1, int M1, int m2, int M2) ; 
void eInk2display (Uint32 *display, uint8_t *black, uint8_t *red);
void display2eInk (uint8_t *img, uint8_t *black, uint8_t *red) ;

void Sierpinski () ;
void Paragraph_freetype (int fontsize, int x0, int y0, int line_end_x, int ymax, String s, uint16_t colour, uint16_t bgcolor=myColours.white) ;
void Paragraph (int x, int y, String s, uint16_t colour, uint16_t bgcolour=myColours.white) ;

#endif
