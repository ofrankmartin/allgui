#include <csignal>
#include <iostream>
#include <memory>

#include <Director.h>
#include <Errors.h>
#include <Factory.h>
#include <Window.h>

using namespace std;
using namespace AG;

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;

    Factory factory("SDL2");
    shared_ptr<Director> director = factory.getDirector();
    director->initialize();

    Window *mainWindow = factory.createWindow();
    if (mainWindow &&
        director->addWindow("main", mainWindow) == RETURN_SUCCESS) {
        director->activeWindow()->initialize("Hello AllGUI world!", 800, 600);
        director->run();
        return EXIT_SUCCESS;
    } else {
        director->run();
        return EXIT_FAILURE;
    }
}
