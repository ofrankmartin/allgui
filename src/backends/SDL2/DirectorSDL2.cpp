#include "DirectorSDL2.h"

#include <atomic>
#include <iostream>
#include <list>
#include <unordered_map>
#include <string>

#include <SDL2/SDL.h>

#include <Errors.h>
#include <Exception.h>
#include <DirectorImpl.h>

#include "WindowSDL2.h"

namespace AG {

using std::atomic;
using std::cerr;
using std::cout;
using std::endl;
using std::list;
using std::string;
using std::unique_ptr;
using std::unordered_map;

class DirectorImplSDL2 : public DirectorImpl {
public:
    DirectorImplSDL2() : readyToFinish(false) {}

    atomic<bool> readyToFinish;

    // Parent implementation
    void initialize() override;
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
void DirectorImplSDL2::initialize()
{
    uint32_t wasVideoInit = SDL_WasInit(SDL_INIT_VIDEO);
    if ((wasVideoInit & SDL_INIT_VIDEO) == SDL_INIT_VIDEO) {
        throw Exception(Exception::Severity::Warning,
                        "SDL video subsystem already initialized");
    }

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        string errorMsg =
            string("Could not initialize sdl2: ") + SDL_GetError();
        throw Exception(Exception::Severity::Warning, errorMsg);
    }
}

int DirectorImplSDL2::finalize()
{
    readyToFinish.store(true);

    return RETURN_SUCCESS;
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
            finalize();
        }

    } while (!readyToFinish.load());

    cleanup();

    return RETURN_SUCCESS;
}

// Implementation class functions
int DirectorImplSDL2::cleanup()
{
    m_windows.clear();
    setActiveWindow(std::string());

    SDL_Quit();

    return RETURN_SUCCESS;
}

int DirectorImplSDL2::draw()
{
    Window *activeWindowPtr = activeWindow();

    if (activeWindowPtr) {
        return activeWindowPtr->draw();
    } else {
        return RETURN_ERROR_UNKNOWN;
    }
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

    return RETURN_SUCCESS;
}

} // namespace AG
