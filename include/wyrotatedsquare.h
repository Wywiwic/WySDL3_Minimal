#ifndef __WYROTATESQUARE__
#define __WYROTATESQUARE__

#include <cmath>
#include <vector>

#include "wyconstant.h"

// Simple rotated square class
class WyRotatedSquare
{
    public:
        ///@remarks Constructor
        WyRotatedSquare();

        ///@remarks Destructor
        ~WyRotatedSquare() {};

        void initSquare();
        void updateSquare(const SDL_FPoint& c);
        void animateSquare();
        void drawSquare(SDL_Renderer* renderer);

        SDL_FPoint rotatePoint(const SDL_FPoint& p, const SDL_FPoint& c, float angle);

    protected:
        float squareAngle;

        std::vector<SDL_FPoint> computedPoints;
        std::vector<SDL_FPoint> squarePoints;
};
#endif
