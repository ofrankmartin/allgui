#include "FactoryImplSDL2.h"

#include "DirectorSDL2.h"

namespace AG {
std::shared_ptr<Director> FactoryImplSDL2::getDirector()
{
    if (!m_director) {
        m_director.reset(new DirectorSDL2());
    }

    return m_director;
}
} // namespace AG
