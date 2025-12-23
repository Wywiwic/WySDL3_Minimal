# WySDL3_Minimal
A mininal skeleton for a SDL3 application which allow you an easy testing

Support : Codeblocks / emscripten

in .cbp file, change C:/devSDK/SDL3-3.2.6/i686-w64-mingw32 to your own SDL3 folder

emscripten command-line: emcc main.cpp .\src\wyrotatedsquare.cpp -o WySDL3_Minimal.js -s USE_SDL=3 -O2
