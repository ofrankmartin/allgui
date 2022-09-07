#ifndef __FACTORYIMPLSDL2_H__
#define __FACTORYIMPLSDL2_H__

#include <FactoryImpl.h>

#include <memory>

namespace AG {

class FactoryImplSDL2 : public FactoryImpl {
public:
    FactoryImplSDL2() {}
    ~FactoryImplSDL2() {}

    std::shared_ptr<Director> getDirector() override;
    Window* createWindow() override;

private:
    std::shared_ptr<Director> m_director;
};

} // namespace AG
#endif // __FACTORYIMPLSDL2_H__
