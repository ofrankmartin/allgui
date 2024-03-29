#pragma once

#include <string>

namespace AG {

class WindowImpl {
public:
    WindowImpl() {}
    virtual ~WindowImpl() {}

    virtual int width() const = 0;
    virtual void setWidth(int width) = 0;

    virtual int height() const = 0;
    virtual void setHeight(int height) = 0;

    virtual std::string title() const = 0;
    virtual void setTitle(const std::string &title) = 0;

    virtual int initialize(const std::string &title, int width, int height) = 0;

    virtual int draw() = 0;
};

} // namespace AG
