#pragma once

#include <memory>

namespace AG {

class Window;

class SceneImpl {
public:
    SceneImpl() {}
    virtual ~SceneImpl() {}

    Window *m_parentWindow;
};
} // namespace AG
