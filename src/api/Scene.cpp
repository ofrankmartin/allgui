#include "Scene.h"

#include "SceneImpl.h"

namespace AG {

Scene::Scene() {}

Scene::~Scene() {}

Window *Scene::parentWindow() const { return pimpl->m_parentWindow; }

void Scene::setParentWindow(Window *const window)
{
    if (pimpl->m_parentWindow != window) {
        pimpl->m_parentWindow = window;
    }
}

} // namespace AG