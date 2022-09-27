#include "Scene.h"

#include "SceneImpl.h"

namespace AG {

Scene::Scene() {}

Scene::~Scene() {}

std::shared_ptr<Window> Scene::parentWindow() const
{
    return pimpl->m_parentWindow;
}

void Scene::setParentWindow(std::shared_ptr<Window> &window)
{
    if (pimpl->m_parentWindow != window) {
        pimpl->m_parentWindow = window;
    }
}

} // namespace AG