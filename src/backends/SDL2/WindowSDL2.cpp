#include "WindowSDL2.h"

#include <iostream>

#include <SDL2/SDL.h>

#include <Errors.h>

#include <WindowImpl.h>

namespace AG {

using std::cerr;
using std::endl;
using std::string;

class WindowImplSDL2 : public WindowImpl {
public:
    ~WindowImplSDL2();
    SDL_Window *m_sdlWindow = nullptr;
    SDL_Renderer *m_renderer = nullptr;
    SDL_Texture *m_windowTexture = nullptr;

    int width() const override;
    void setWidth(int width) override;

    int height() const override;
    void setHeight(int height) override;

    std::string title() const override;
    void setTitle(const std::string &title) override;

    int initialize(const std::string &title, int width, int height) override;

    int draw() override;
};

WindowSDL2::WindowSDL2() : Window() { this->pimpl.reset(new WindowImplSDL2()); }

WindowSDL2::~WindowSDL2() {}

SDL_Window *WindowSDL2::window() const
{
    return (dynamic_cast<WindowImplSDL2 *>(pimpl.get()))->m_sdlWindow;
}

// Implementation class
WindowImplSDL2::~WindowImplSDL2()
{
    auto initSubsystems = SDL_WasInit(SDL_INIT_VIDEO);
    if ((initSubsystems & SDL_INIT_VIDEO) == SDL_INIT_VIDEO) {
        if (m_renderer) {
            SDL_DestroyRenderer(m_renderer);
        }
        if (m_sdlWindow) {
            SDL_DestroyWindow(m_sdlWindow);
        }
    }
}

int WindowImplSDL2::initialize(const std::string &title, int width, int height)
{
    m_sdlWindow = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED,
                                   SDL_WINDOWPOS_UNDEFINED, width, height,
                                   SDL_WINDOW_SHOWN);
    if (m_sdlWindow == nullptr) {
        cerr << "could not create window: " << SDL_GetError() << endl;
        return RETURN_ERROR_UNKNOWN;
    }

    m_renderer = SDL_CreateRenderer(m_sdlWindow, -1, SDL_RENDERER_ACCELERATED);
    if (m_renderer == nullptr) {
        cerr << "could not create renderer: " << SDL_GetError() << endl;
        return RETURN_ERROR_UNKNOWN;
    }

    m_windowTexture =
        SDL_CreateTexture(m_renderer, SDL_GetWindowPixelFormat(m_sdlWindow),
                          SDL_TEXTUREACCESS_TARGET, width, height);
    if (m_windowTexture == nullptr) {
        cerr << "could not create texture: " << SDL_GetError() << endl;
        return RETURN_ERROR_UNKNOWN;
    }

    return RETURN_SUCCESS;
}

int WindowImplSDL2::draw()
{
    if (m_sdlWindow == nullptr) {
        cerr << "No SDL window available." << endl;
        return RETURN_ERROR_UNKNOWN;
    }

    SDL_Color colors[5] = {
        {0xFF, 0xFF, 0xFF, 0xFF}, {0xFF, 0x00, 0x00, 0xFF},
        {0x00, 0xFF, 0x00, 0xFF}, {0x00, 0x00, 0xFF, 0xFF},
        {0x00, 0x00, 0x00, 0xFF},
    };

    Uint32 ticks = SDL_GetTicks();
    int idx = (ticks / 1000) % 5;

    SDL_SetRenderTarget(m_renderer, m_windowTexture);
    SDL_SetRenderDrawColor(m_renderer, colors[idx].r, colors[idx].g,
                           colors[idx].b, colors[idx].a);
    SDL_RenderClear(m_renderer);
    SDL_SetRenderTarget(m_renderer, nullptr);
    SDL_RenderCopy(m_renderer, m_windowTexture, nullptr, nullptr);
    SDL_RenderPresent(m_renderer);

    return RETURN_SUCCESS;
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
