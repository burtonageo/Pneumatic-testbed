#include <string>
#include <iostream>

#include "pneu/graphics/Color.hpp"
#include "pneu/graphics/Window.hpp"
#include "pneu/graphics/Renderer.hpp"
#include "pneu/core/MethodResult.hpp"

#define GLM_FORCE_CXX11
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>

auto main(int argc, const char** argv) -> int {
  pneu::graphics::Window window("testing", 800, 600, 80, 60);

  window.init().onError([](const std::string& error) {
                          std::cout << error << std::endl;
                          exit(1);
                        });

  // set background to a nice shade of blue
  window.getRenderer().setBackgroundColor(pneu::graphics::Color<>(0.2f, 0.3f, 0.7f));

  while (window.isRunning()) {
    window.pollEvents();
    window.update();
    window.renderFrame();
  }

  return 0;
}
