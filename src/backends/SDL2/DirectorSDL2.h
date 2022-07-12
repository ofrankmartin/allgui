#ifndef __DIRECTORSDL2_H__
#define __DIRECTORSDL2_H__

#include <Director.h>

#include <memory>

namespace AG {

class DirectorSDL2 : public Director {
public:
    DirectorSDL2();
    ~DirectorSDL2() override;
};

} // namespace AG

#endif // __DIRECTORSDL2_H__
