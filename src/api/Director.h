#pragma once

#include <list>
#include <memory>
#include <string>
#include <unordered_map>

#include <Events.h>

namespace AG {

class Window;
class DirectorImpl;

class Director {
public:
    Director();
    virtual ~Director();

    void initialize();
    int finalize();
    int run();

    int addEventListener(const std::string &trigger, EventCallback callback);

    Window *activeWindow() const;

    int addWindow(const std::string &idx, Window *const window);
    int setActiveWindow(const std::string &idx);
    int removeWindow(const std::string &idx);

protected:
    std::unique_ptr<DirectorImpl> pimpl;
};

} // namespace AG
