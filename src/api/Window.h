#ifndef __WINDOW_H__
#define __WINDOW_H__

#include <memory>
#include <string>

namespace AG {

class WindowImpl;

class Window {
public:
    Window();
    virtual ~Window();

    virtual int width() const;
    virtual void setWidth(int width);

    virtual int height() const;
    virtual void setHeight(int height);

    virtual std::string title() const;
    virtual void setTitle(const std::string &title);

    virtual int initialize(const std::string &title, int width, int height);

    virtual int draw();

protected:
    std::unique_ptr<WindowImpl> pimpl;
};

} // namespace AG

#endif // __WINDOW_H__
