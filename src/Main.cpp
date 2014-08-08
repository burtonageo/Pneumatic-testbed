#include <string>
#include <iostream>

#include "pneu/graphics/Window.hpp"
#include "pneu/core/MethodResult.hpp"

auto main(int argc, const char** argv) -> int {
  pneu::graphics::Window win("testing", 800, 600, 80, 60);

  win.init().onError([](const std::string& error) {
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
