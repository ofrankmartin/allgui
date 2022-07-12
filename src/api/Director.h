#ifndef __DIRECTOR_H__
#define __DIRECTOR_H__

#include <list>
#include <memory>
#include <string>
#include <unordered_map>

#include "DirectorImpl.h"

namespace AG {



class Window;

class Director {
public:
    Director();
    virtual ~Director();

    int initialize();
    int finalize();
    int run();

    int addEventListener(const std::string &trigger, EventCallback callback);

    Window *activeWindow() const;

protected:
    std::unique_ptr<DirectorImpl> pimpl;
};

} // namespace AG

#endif // __DIRECTOR_H__