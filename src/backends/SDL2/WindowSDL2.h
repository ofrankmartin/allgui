#ifndef __WINDOWSDL2_H__
#define __WINDOWSDL2_H__

#include <Window.h>

typedef struct SDL_Window SDL_Window;

namespace AG {

class WindowSDL2 : public Window {
public:
    WindowSDL2(const std::string &title, int width, int height);
    ~WindowSDL2();

    SDL_Window *window() const;
};

} // namespace AG

#endif // __WINDOWSDL2_H__
