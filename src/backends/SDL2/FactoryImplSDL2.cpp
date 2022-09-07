#include "FactoryImplSDL2.h"

#include "DirectorSDL2.h"
#include "WindowSDL2.h"

namespace AG {
std::shared_ptr<Director> FactoryImplSDL2::getDirector()
{
    if (!m_director) {
        m_director.reset(new DirectorSDL2());
    }

    return m_director;
}

Window* FactoryImplSDL2::createWindow()
{
    WindowSDL2* window = new WindowSDL2();
    return window;
}

} // namespace AG
