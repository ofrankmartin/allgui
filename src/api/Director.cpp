#include "Director.h"

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

Window *Director::activeWindow() const { return pimpl->activeWindow().get(); }

} // namespace AG
