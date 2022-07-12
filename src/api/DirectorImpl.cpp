#include "DirectorImpl.h"

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

void DirectorImpl::addWindow(const std::string &idx, Window *const window)
{
    m_windows[idx] = std::shared_ptr<Window>(window);
    if (m_windows.size() == 1) {
        setActiveWindow(idx);
    }
}

void DirectorImpl::setActiveWindow(const std::string &idx)
{
    m_activeWindow = m_windows[idx];
}

} // namespace AG