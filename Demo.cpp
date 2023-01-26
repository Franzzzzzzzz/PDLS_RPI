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


// Add setup code
///
/// @brief Setup
///
unsigned char black[W*H/8] ; 
unsigned char red[W*H/8] ; 
Uint32 display[W*H] ; 
uint8_t img[W][H] ;

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
  //Paragraph(57,11, "Lorem ipsum dolor sit amet, consectetur\nadipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea\n\ncommodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum. abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz", myColours.black, myColours.red) ; 
  Paragraph_freetype (10, 10, 30, W-10, H-10, "It was natural to form a pyramide - well, a cone, anyway. He'd _experimented_ this morning. Grain, salt, sand ... not water, though, that'd been a mistake. But a pyramid was only a neat cone, wasn't it, a cone which had decided to be a bit tidier.\n\nPyramids, Terry Pratchett", myColours.red) ; 
  
  
  //myScreen.clear();
  #ifdef RPI
      myScreen.flush();
  #endif
    
  eInk2display(display, myScreen.blackimg(), myScreen.redimg()) ; 
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
