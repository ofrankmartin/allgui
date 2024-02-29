#pragma once

#include <Window.h>

typedef struct SDL_Window SDL_Window;

namespace AG {

class WindowSDL2 : public Window {
public:
    WindowSDL2();
    ~WindowSDL2();

    SDL_Window *window() const;
};

} // namespace AG
