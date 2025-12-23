#include "../include/wyrotatedsquare.h"

WyRotatedSquare::WyRotatedSquare() :
    squareAngle(0.0f)
{
}

void WyRotatedSquare::initSquare()
{
    squarePoints.clear();
    squarePoints.push_back({-100, 100});
    squarePoints.push_back({100, 100});
    squarePoints.push_back({100, 100});
    squarePoints.push_back({100, -100});
    squarePoints.push_back({100, -100});
    squarePoints.push_back({-100, -100});
    squarePoints.push_back({-100, -100});
    squarePoints.push_back({-100, 100});

    updateSquare(screenCenter);
}

SDL_FPoint WyRotatedSquare::rotatePoint(const SDL_FPoint& point, const SDL_FPoint& center, float angle)
{
    float sinus = sin(angle);
    float cosinus = cos(angle);

    float distanceX = point.x - center.x;
    float distanceY = point.y - center.y;

    return
    {
        center.x + (distanceX * cosinus) - (distanceY * sinus),
        center.y + (distanceX * sinus) + (distanceY * cosinus)
    };
}

void WyRotatedSquare::updateSquare(const SDL_FPoint& center)
{
    for (auto& point : squarePoints)
    {
        point.x += center.x;
        point.y += center.y;
    }
}

void WyRotatedSquare::animateSquare()
{
    #ifdef __EMSCRIPTEN__
        squareAngle += 0.01f;
    #else
        squareAngle += 0.0001f;
    #endif

    if (squareAngle >= 360.0f)
        squareAngle -= 360.0f;

    computedPoints.clear();
    for (const auto& point : squarePoints)
    {
        SDL_FPoint r = rotatePoint(point, screenCenter, squareAngle);
        SDL_FPoint tmpPoint = {r.x, r.y};
        computedPoints.push_back(tmpPoint);
    }
}

void WyRotatedSquare::drawSquare(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    for (unsigned int counter = 0; counter < computedPoints.size(); )
    {
        SDL_RenderLine(renderer, computedPoints.at(counter).x, computedPoints.at(counter).y, computedPoints.at(counter+1).x, computedPoints.at(counter+1).y);
        counter+=2;
    }

    SDL_RenderPresent(renderer);
}
