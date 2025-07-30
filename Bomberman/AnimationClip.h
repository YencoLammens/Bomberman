#pragma once
#include <vector>
#include <SDL.h>

namespace dae 
{
    struct AnimationClip
    {
        std::vector<SDL_Rect> frames;
        float frameDuration{};
        bool loop = true;
    };
}


