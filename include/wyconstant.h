#ifndef __WYCONSTANT__
#define __WYCONSTANT__

#include <SDL3/SDL.h>

const double SCREEN_WIDTH           = 800;
const double SCREEN_HEIGHT          = 800;
const double SCREEN_WIDTH_CENTER    = (SCREEN_WIDTH/2);
const double SCREEN_HEIGHT_CENTER   = (SCREEN_HEIGHT/2);

const SDL_FPoint screenCenter = {static_cast<float>(SCREEN_WIDTH_CENTER), static_cast<float>(SCREEN_HEIGHT_CENTER)};

#endif
