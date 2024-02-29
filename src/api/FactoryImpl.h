#pragma once

#include <memory>

namespace AG {

class Director;
class Window;

class FactoryImpl {
public:
    FactoryImpl(){};
    virtual ~FactoryImpl(){};

    virtual Director *getDirector() = 0;
    virtual Window *createWindow() = 0;
};
} // namespace AG
