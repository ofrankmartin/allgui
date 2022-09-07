#include "DirectorImpl.h"

#include <iostream>

#include "Errors.h"
#include "Window.h"

namespace AG {

DirectorImpl::DirectorImpl() {}

DirectorImpl::~DirectorImpl() {}

int DirectorImpl::addEventListener(const std::string &trigger,
                                   EventCallback callback)
{
    auto it = m_eventListeners.find(trigger);
    if (it == m_eventListeners.end()) {
        m_eventListeners[trigger] = std::list<EventCallback>{callback};
    } else {
        (*it).second.push_back(callback);
    }

    return ERROR_SUCCESS;
}

std::shared_ptr<Window> DirectorImpl::activeWindow() const
{
    return m_activeWindow;
}

int DirectorImpl::addWindow(const std::string &idx, Window *const window)
{
    if (idx.empty()) {
        std::cerr << "Idx must be a non empty string" << std::endl;
        return ERROR_UNKNOWN;
    }

    m_windows[idx] = std::shared_ptr<Window>(window);
    if (m_windows.size() == 1) {
        setActiveWindow(idx);
    }

    return ERROR_SUCCESS;
}

int DirectorImpl::removeWindow(const std::string &idx)
{
    if (m_windows.count(idx) > 0) {
        std::shared_ptr<Window> remWin = m_windows[idx];

        m_windows.erase(idx);

        if (m_activeWindow == remWin) {
            if (m_windows.size() > 0) {
                setActiveWindow(m_windows.begin()->first);
            } else {
                setActiveWindow(std::string());
            }
        }
    }

    return ERROR_SUCCESS;
}

int DirectorImpl::setActiveWindow(const std::string &idx)
{
    if (idx.empty()) {
        m_activeWindow.reset();
    } else if (m_windows.count(idx) > 0) {
        m_activeWindow = m_windows[idx];
    } else {
        // TODO error handling
        return ERROR_UNKNOWN;
    }

    return ERROR_SUCCESS;
}

} // namespace AG