#include "../PhysicsEngine/engine.h"
#include <cassert>
#include <iostream>

/*
 * From the /Engine/build$ directory: cmake .. && make && ./EngineTests
*/

void test_getInstance() {
	Engine& engine1 = Engine::getInstance();
	Engine& engine2 = Engine::getInstance();
	assert(&engine1 == &engine2);
}

void test_initVulkan() {
}

void test_mainLoop() {
}

void test_cleanup() {
}

void test_initWindow() {
}

void test_createInstance() {
	
}
void test_checkValidationLayerSupport() {

}

int main() {
	test_getInstance();
	test_initVulkan();
	test_mainLoop();
	test_cleanup();
	test_initWindow();
	test_createInstance();
	test_checkValidationLayerSupport();
	std::cout << " << tests passed! >> " << std::endl;
}
