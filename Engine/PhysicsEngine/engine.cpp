#include "engine.h"
#include <iostream>
using namespace std;

void Engine::run() {
	initWindow();
	initVulkan();
	mainLoop();
	cleanup();
}

void Engine::initVulkan() {
	createInstance();
}

void Engine::mainLoop() {
	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();
	}
}

void Engine::cleanup() {
	glfwDestroyWindow(window);
	glfwTerminate();
}

void Engine::initWindow() {
	glfwInit();
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
						       // monitor?, OpenGLOnly
	window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);		
}

void Engine::createInstance() {
	VkApplicationInfo appInfo{};
	appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	appInfo.pApplicationName = "3DPhysicsEngine";
	appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo.pEngineName = "No Engine"; // TODO: this is an engine so...?
	appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo.apiVersion = VK_API_VERSION_1_0;
}
