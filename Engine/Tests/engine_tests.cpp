#include "../PhysicsEngine/engine.h"
#include <cassert>
#include <iostream>
void test_getInstance() {
	Engine& engine1 = Engine::getInstance();
	Engine& engine2 = Engine::getInstance();
	assert(&engine1 == &engine2);
}

int main() {
	test_getInstance();

	std::cout << " << tests passed! >> " << std::endl;
}
