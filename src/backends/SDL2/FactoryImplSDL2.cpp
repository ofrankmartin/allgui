#include "FactoryImplSDL2.h"

#include "DirectorSDL2.h"
#include "WindowSDL2.h"

namespace AG {

FactoryImplSDL2::FactoryImplSDL2() {}

FactoryImplSDL2::~FactoryImplSDL2() {}

Director *FactoryImplSDL2::getDirector()
{
    if (!m_director) {
        m_director.reset(new DirectorSDL2());
    }

    return m_director.get();
}

Window *FactoryImplSDL2::createWindow()
{
    WindowSDL2 *window = new WindowSDL2();
    return window;
}

} // namespace AG
