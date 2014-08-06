#include <string>
#include <iostream>

#include "graphics/Window.hpp"
#include "core/MethodResult.hpp"

using namespace std;

auto main(int argc, const char** argv) -> int {
	Pneumatic::Graphics::Window win("testing", 800, 600, 80, 60);

	auto win_init_result = win.init();
	if (!win_init_result.isOk()) {
		cout << win_init_result.getError() << endl;
		return 1;
	}

	while (win.isRunning()) {
		win.pollEvents();
		win.updateWindow();
	}
	return 0;
}
