#ifndef __FACTORY_H__
#define __FACTORY_H__

#include <memory>
#include <string>

namespace AG {

class Director;
class FactoryImpl;

class Factory {
public:
    Factory(const std::string &backend);
    ~Factory();

    std::shared_ptr<Director> getDirector();

private:
    std::unique_ptr<FactoryImpl> pimpl;
};
} // namespace AG

#endif // __FACTORY_H__
