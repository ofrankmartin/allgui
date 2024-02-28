#include "Director.h"

#include "DirectorImpl.h"

#include <Errors.h>

namespace AG {

using std::string;

Director::Director() {}

Director::~Director() {}

int Director::initialize() { return pimpl->initialize(); }

int Director::finalize() { return pimpl->finalize(); }

int Director::run() { return pimpl->run(); }

int Director::addEventListener(const string &trigger, EventCallback callback)
{
    return pimpl->addEventListener(trigger, callback);
}

Window *Director::activeWindow() const { return pimpl->activeWindow(); }

int Director::addWindow(const std::string &idx, Window *const window)
{
    return pimpl->addWindow(idx, window);
}

int Director::setActiveWindow(const std::string &idx)
{
    return pimpl->setActiveWindow(idx);
}

int Director::removeWindow(const std::string &idx)
{
    return pimpl->removeWindow(idx);
}

} // namespace AG
