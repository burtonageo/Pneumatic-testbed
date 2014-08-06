#include <string>
#include <iostream>

#include "graphics/Window.hpp"
#include "core/MethodResult.hpp"

auto main(int argc, const char** argv) -> int {
  Pneumatic::Graphics::Window win("testing", 800, 600, 80, 60);

  win.init().ifNotOk([](const std::string& error) {
                       std::cout << error << std::endl;
                       exit(1);
                     });

  while (win.isRunning()) {
    win.pollEvents();
    win.update();
    win.renderFrame();
  }

  return 0;
}
