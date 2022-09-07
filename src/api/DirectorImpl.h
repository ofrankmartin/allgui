#ifndef __DIRECTORIMPL_H__
#define __DIRECTORIMPL_H__

#include <list>
#include <memory>
#include <string>
#include <unordered_map>

#include "Events.h"

namespace AG {

class Window;

class DirectorImpl {
public:
    DirectorImpl();
    virtual ~DirectorImpl();

    // Parent implementation
    virtual int initialize() = 0;
    virtual int finalize() = 0;
    virtual int run() = 0;

    int addEventListener(const std::string &trigger, EventCallback callback);
    std::shared_ptr<Window> activeWindow() const;

    int addWindow(const std::string &idx, Window *const window);
    int setActiveWindow(const std::string &idx);
    int removeWindow(const std::string &idx);

protected:
    std::unordered_map<std::string, std::list<EventCallback>> m_eventListeners;
    std::unordered_map<std::string, std::shared_ptr<Window>> m_windows;
    std::shared_ptr<Window> m_activeWindow;
};

} // namespace AG

#endif // __DIRECTORIMPL_H__
