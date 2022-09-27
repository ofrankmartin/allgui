#ifndef __SCENEIMPL_H__
#define __SCENEIMPL_H__

#include <memory>

namespace AG {

class Window;

class SceneImpl {
public:
    SceneImpl() {}
    virtual ~SceneImpl() {}

    std::shared_ptr<Window> m_parentWindow;
};
} // namespace AG

#endif // __SCENEIMPL_H__
