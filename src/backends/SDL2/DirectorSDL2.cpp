#include "DirectorSDL2.h"

#include <atomic>
#include <iostream>
#include <list>
#include <unordered_map>
#include <string>

#include <SDL2/SDL.h>

#include <Errors.h>
#include <DirectorImpl.h>

#include "WindowSDL2.h"

namespace AG {

using std::atomic;
using std::cerr;
using std::cout;
using std::endl;
using std::list;
using std::shared_ptr;
using std::string;
using std::unique_ptr;
using std::unordered_map;

class DirectorImplSDL2 : public DirectorImpl {
public:
    DirectorImplSDL2() : readyToFinish(false) {}

    uint m_screenWidth = 800;
    uint m_screenHeight = 600;
    string m_windowName = "SDL Application";

    atomic<bool> readyToFinish;
    shared_ptr<WindowSDL2> m_activeWindow;
    unordered_map<string, shared_ptr<WindowSDL2>> m_windows;

    // Parent implementation
    int initialize() override;
    int finalize() override;
    int run() override;

    // Private functions
    int cleanup();
    int draw();
    int eventHandler();
};

DirectorSDL2::DirectorSDL2() : Director() { pimpl.reset(new DirectorImplSDL2); }

DirectorSDL2::~DirectorSDL2() {}

// Implementation class
int DirectorImplSDL2::initialize()
{
    // TODO double initialization warning
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cerr << "Could not initialize sdl2: " << SDL_GetError() << endl;
        return ERROR_UNKNOWN;
    }

    WindowSDL2 *newWindow = new WindowSDL2("SDL2 Application", 800, 600);

    if (newWindow == NULL) {
        cerr << "could not create window: " << SDL_GetError() << endl;
        return ERROR_UNKNOWN;
    }

    addWindow("main", newWindow);

    return ERROR_SUCCESS;
}

int DirectorImplSDL2::finalize()
{
    int retval = ERROR_SUCCESS;

    readyToFinish.store(true);

    return retval;
}

int DirectorImplSDL2::run()
{
    do {
        int rc = 0;
        if ((rc = eventHandler())) {
            cerr << "Failed processing events" << endl;
        }

        if ((rc = draw())) {
            cerr << "Failed drawing frame" << endl;
        }

    } while (!readyToFinish.load());

    cleanup();

    return ERROR_SUCCESS;
}

// Implementation class functions
int DirectorImplSDL2::cleanup()
{
    m_windows.clear();

    SDL_Quit();

    return ERROR_SUCCESS;
}

int DirectorImplSDL2::draw()
{
    std::shared_ptr<Window> activeWindowPtr = activeWindow();

    WindowSDL2 *window = nullptr;
    if (activeWindowPtr) {
        window = dynamic_cast<WindowSDL2 *>(activeWindowPtr.get());
    }

    SDL_Window *sdlWindow = nullptr;
    if (window) {
        sdlWindow = window->window();
    }

    if (sdlWindow) {
        SDL_Surface *screenSurface = SDL_GetWindowSurface(sdlWindow);
        SDL_Color colors[5] = {
            {0xFF, 0xFF, 0xFF, 0xFF}, {0xFF, 0x00, 0x00, 0xFF},
            {0x00, 0xFF, 0x00, 0xFF}, {0x00, 0x00, 0xFF, 0xFF},
            {0x00, 0x00, 0x00, 0xFF},
        };

        Uint32 ticks = SDL_GetTicks();
        int idx = (ticks / 1000) % 5;

        SDL_FillRect(screenSurface, NULL,
                     SDL_MapRGB(screenSurface->format, colors[idx].r,
                                colors[idx].g, colors[idx].b));
        SDL_UpdateWindowSurface(sdlWindow);
    }

    return ERROR_SUCCESS;
}

int DirectorImplSDL2::eventHandler()
{
    SDL_Event evt = {};
    while (SDL_PollEvent(&evt)) {
        switch (evt.type) {
        case SDL_QUIT:
            finalize();
            break;

        default:
            break;
        }

        // TODO process the event queue
        // Assembly the trigger string based on the input event I.e. "ctrl+c"
        string triggerStr;
        list<EventCallback> &eventCallbacks = m_eventListeners[triggerStr];
        for (auto evt : eventCallbacks) {
            evt();
        }
    }

    return ERROR_SUCCESS;
}

} // namespace AG
