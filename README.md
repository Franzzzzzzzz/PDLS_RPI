

# Modification and extension of the Pervasive Displays Library Suite Basic Edition

This repository modifies the [Pervasive Displays API](https://github.com/rei-vilo/PDLS_EXT3_Basic) (basic edition, CC-BY-SA) to include several new features:
- Use with Raspberry Pi 3B single board computer
- Display to standard video output using [Simple DirectMedia Layer 2](https://www.libsdl.org/), for immediate visualisation of the expected display. 
- Additional quality of life functions. 

## Compilation
For compilation for standard computer (without eInk display), use:
`g++ -o Demo *.cpp -lSDL2`.

For compilation on Raspberry Pi (with eInk display), the additional define `RPI` must be set:
`g++ -o Demo *.cpp -DRPI -lSDL2 -lspidev-lib++ -lwiringPi`

All compilation requires the libsdl2 (eg. : `sudo apt install libsdl2-dev`).
Running on Raspberry Pi requires in addition the [wiringPi](http://wiringpi.com/) library and the [spidev-lib](https://github.com/milekium/spidev-lib) library. 

## Hardware
** The software has only been tested on a Raspberry Pi 3B with a [4.37" E-ink display Three colours](https://www.pervasivedisplays.com/product/4-37-e-ink-display-spectra-r2-0/) **. Any other screen requires modification of the code to work, as the screen size is hardcoded. Any other computer than RPI3B likely requires adjustments of the pinout and spi setup to work properly.

#### Running on RPI3B
1. Enable the SPI communication in the `raspi-config` utility and reboot.
2. The pins are (wire colours corresponds to the ones when using the [EXT3](https://www.pervasivedisplays.com/product/epd-extension-kit-gen-3-ext3/) kit:
  - 3.3V: pin 1. BLACK
  - MOSI: pin 19. BLUE
  - MISO: pin 21. GREEN 
  - SCLK: pin 23. BROWN
  - Busy: GPIO5, pin 29. RED
  - D/C: GPIO6, pin 31. ORANGE
  - RST: GPIO13, pin 33. YELLOW
  - Flash CS: GPIO26, pin 37. PURPLE
  - Panel CS: GPIO19, pin 35. GRAY
  - GND: pin 6. WHITE
  NB: the pins defined in the c++ code are *NEITHER* the GPIO number *NOR* the pin numbers. `wiringPi` uses different numbers (not sure where they come from), which can be found [there](https://pinout.xyz/pinout/wiringpi#) if you want to change the pins. The SPI connection use is `/dev/spidev0.0`.
3. Compile with the `-DRPI` flag and the other required libraries (cf. above).
4. If you are connected to a headless RPI, you probably need an display connection of SDL may have issues. In ssh, you can use `ssh -X ...`. Check how to set up a X display through ssh to see how that can be achieved. 
5. The compiled program needs to be run as root to have access to SPI communication and GPIO: `sudo ./Demo`. There are probably ways to give the appropriate rights to avoid running as root...









