#pragma once

#include <memory>
#include <string>

namespace AG {

class Director;
class Window;
class FactoryImpl;

class Factory {
public:
    Factory(const std::string &backend);
    ~Factory();

    Director *getDirector();
    Window *createWindow();

private:
    std::unique_ptr<FactoryImpl> pimpl;
};
} // namespace AG
