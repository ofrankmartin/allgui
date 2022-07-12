#ifndef __SUBFACTORY_H__
#define __SUBFACTORY_H__

#include <memory>
#include "Director.h"

namespace AG {
class FactoryImpl {
public:
    FactoryImpl(){};
    virtual ~FactoryImpl(){};

    virtual std::shared_ptr<Director> getDirector() = 0;
};
} // namespace AG

#endif // __SUBFACTORY_H__
