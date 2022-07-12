#include "Window.h"

#include "WindowImpl.h"

namespace AG {
Window::Window() {}

Window::~Window() {}

int Window::width() const { return pimpl->width(); }

void Window::setWidth(int width) { pimpl->setWidth(width); }

int Window::height() const { return pimpl->height(); }

void Window::setHeight(int height) { pimpl->setHeight(height); }

std::string Window::title() const { return pimpl->title(); }

void Window::setTitle(const std::string &title) { pimpl->setTitle(title); }
} // namespace AG
