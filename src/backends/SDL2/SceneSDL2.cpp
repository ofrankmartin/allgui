#include "SceneSDL2.h"

#include <SceneImpl.h>

namespace AG {

class SceneSDL2Impl : public SceneImpl {
public:
    SceneSDL2Impl() {}
    ~SceneSDL2Impl() {}
};

SceneSDL2::SceneSDL2() : Scene() { this->pimpl.reset(new SceneSDL2Impl); }

SceneSDL2::~SceneSDL2() {}

} // namespace AG
