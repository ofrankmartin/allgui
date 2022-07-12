#include <iostream>
#include <memory>

#include <Director.h>
#include <Factory.h>

using namespace std;
using namespace AG;

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;

    Factory factory("SDL2");
    shared_ptr<Director> director = factory.getDirector();

    director->initialize();
    director->run();

    return EXIT_SUCCESS;
}
