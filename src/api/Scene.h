#ifndef __SCENE_H__
#define __SCENE_H__

#include <memory>

namespace AG {

class SceneImpl;
class Window;

class Scene {
public:
    Scene();
    virtual ~Scene();

    std::shared_ptr<Window> parentWindow() const;
    void setParentWindow(std::shared_ptr<Window> &window);

protected:
    std::unique_ptr<SceneImpl> pimpl;
};

} // namespace AG

#endif // __SCENE_H__
