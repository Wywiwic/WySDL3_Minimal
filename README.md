# WySDL3_Minimal
A mininal skeleton for a libSDL3 application which allow you an easy testing for GCC on Windows & WebAssembly

## Support :
  - Codeblocks
  - CMake
  -  Emscripten

## Requirements
  - LibSDL -> https://www.libsdl.org/
  - Codeblocks -> https://www.codeblocks.org/
  - CMake -> https://cmake.org/
  - Emscripten -> https://emscripten.org/

## Compilation 

### Compilation with Codeblocks : 
  - Change the file WySDL3_Minimal.cbp to replace:
          C:/devSDK/SDL3-3.2.6/i686-w64-mingw32
    by your own SDL3 root folder

### Compilation with CMake : 
  - cmake -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release
  - cmake --build .

### Compilation with Emscripten:
  - emcc main.cpp .\src\wyrotatedsquare.cpp -o WySDL3_Minimal.js -s USE_SDL=3 -O2

## Example
  Emscripten demo -> https://www.wywiwic.com/github/wysdl3_minimal/

  ![WySDL3_Minimal](https://www.wywiwic.com/github/wysdl3_minimal/wysdl3_minimal.png)
