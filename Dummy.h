#include <cstdint>
#include <cstring>
#include <string>
#include<unistd.h>
#include <cmath>
#include <SDL2/SDL.h>

#define HIGH 1
#define LOW 0 
#define OUTPUT 1
#define INPUT 0
#define PI M_PI

using String=std::string ; 

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
void eInk2display (Uint32 *display, uint8_t *black, uint8_t *red, int W, int H);
void display2eInk (uint8_t *img, uint8_t *black, uint8_t *red, int W, int H) ;
