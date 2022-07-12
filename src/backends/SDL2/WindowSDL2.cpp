#include "WindowSDL2.h"

#include <SDL2/SDL.h>

#include <WindowImpl.h>

namespace AG {

using std::string;

class WindowImplSDL2 : public WindowImpl {
public:
    ~WindowImplSDL2();
    SDL_Window *m_sdlWindow = nullptr;

    int width() const override;
    void setWidth(int width) override;

    int height() const override;
    void setHeight(int height) override;

    std::string title() const override;
    void setTitle(const std::string &title) override;

    void initializeWindow();
};

WindowSDL2::WindowSDL2(const std::string &title, int width, int height)
    : Window()
{
    this->pimpl.reset(new WindowImplSDL2());
    WindowImplSDL2 *pimpl = dynamic_cast<WindowImplSDL2 *>(this->pimpl.get());

    pimpl->m_sdlWindow = SDL_CreateWindow(
        title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width,
        height, SDL_WINDOW_SHOWN);
}

WindowSDL2::~WindowSDL2() {}

SDL_Window *WindowSDL2::window() const
{
    return (dynamic_cast<WindowImplSDL2 *>(pimpl.get()))->m_sdlWindow;
}

// Implementation class
WindowImplSDL2::~WindowImplSDL2() { SDL_DestroyWindow(m_sdlWindow); }

void WindowImplSDL2::initializeWindow()
{
    m_sdlWindow = SDL_CreateWindow(
        this->title().c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        this->width(), this->height(), SDL_WINDOW_SHOWN);
}

int WindowImplSDL2::width() const
{

    int w = 0, h = 0;
    if (m_sdlWindow) {
        SDL_GetWindowSize(m_sdlWindow, &w, &h);
    }

    return w;
}

void WindowImplSDL2::setWidth(int width)
{
    if (m_sdlWindow) {
        int w = 0, h = 0;
        SDL_GetWindowSize(m_sdlWindow, &w, &h);
        SDL_SetWindowSize(m_sdlWindow, width, h);
    }
}

int WindowImplSDL2::height() const
{
    int w = 0, h = 0;
    if (m_sdlWindow) {
        SDL_GetWindowSize(m_sdlWindow, &w, &h);
    }

    return h;
}

void WindowImplSDL2::setHeight(int height)
{
    if (m_sdlWindow) {
        int w = 0, h = 0;
        SDL_GetWindowSize(m_sdlWindow, &w, &h);
        SDL_SetWindowSize(m_sdlWindow, w, height);
    }
}

string WindowImplSDL2::title() const
{
    string ret;
    ret.assign(SDL_GetWindowTitle(m_sdlWindow));
    return ret;
}

void WindowImplSDL2::setTitle(const string &title)
{
    SDL_SetWindowTitle(m_sdlWindow, title.c_str());
}

} // namespace AG
