#pragma once

#include <memory>

namespace AG {

class SceneImpl;
class Window;

class Scene {
public:
    Scene();
    virtual ~Scene();

    Window *parentWindow() const;
    void setParentWindow(Window *const window);

protected:
    std::unique_ptr<SceneImpl> pimpl;
};

} // namespace AG
