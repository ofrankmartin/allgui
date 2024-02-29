#pragma once

#include <FactoryImpl.h>

#include <memory>

namespace AG {

class FactoryImplSDL2 : public FactoryImpl {
public:
    explicit FactoryImplSDL2();
    virtual ~FactoryImplSDL2();

    Director *getDirector() override;
    Window *createWindow() override;

private:
    std::unique_ptr<Director> m_director;
};

} // namespace AG
