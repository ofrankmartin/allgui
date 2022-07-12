#include "Factory.h"

#include <iostream>

#include "FactoryImpl.h"
#include "../backends/SDL2/FactoryImplSDL2.h"

namespace AG {

using std::cerr;
using std::cout;
using std::endl;
using std::shared_ptr;
using std::string;

Factory::Factory(const string &backend)
{
    if (backend.compare("SDL2") == 0) {
        pimpl.reset(new FactoryImplSDL2());
    } else {
        cerr << "Unsupported backend \"" << backend << "\"" << endl;
    }
}

Factory::~Factory() {}

shared_ptr<Director> Factory::getDirector() { return pimpl->getDirector(); }

} // namespace AG
