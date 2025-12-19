#include "engine.h"
#include <iostream>
#include <vector> 
#include <cstring>
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
	vkDestroyInstance(instance, nullptr);
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
	if (enableValidationLayers && !checkValidationLayerSupport()) {
		throw std::runtime_error("validation layers requested, but not available!");
	}
	VkApplicationInfo appInfo{};
	appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	appInfo.pApplicationName = "3DPhysicsEngine";
	appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo.pEngineName = "No Engine"; // TODO: this is an engine so...?
	appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo.apiVersion = VK_API_VERSION_1_0;
	VkInstanceCreateInfo createInfo{};
	createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	createInfo.pApplicationInfo = &appInfo;

	uint32_t glfwExtensionCount = 0;
	const char** glfwExtensions;

	glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
	
	createInfo.enabledExtensionCount = glfwExtensionCount;
	if (enableValidationLayers) {
		createInfo.enabledLayerCount = static_cast<uint32_t>(validationLayers.size());
		createInfo.ppEnabledLayerNames = validationLayers.data();
	} else {
		createInfo.enabledLayerCount = 0;
	}

	createInfo.ppEnabledExtensionNames = glfwExtensions;
	VkResult result = vkCreateInstance(&createInfo, nullptr, &instance);
	if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) {
		throw std::runtime_error("failed to create instance!");
	} else {
		std::cout << "Instance created successfully!\n";
	}

	uint32_t extensionCount = 0;
	vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
	std::vector<VkExtensionProperties> extensions(extensionCount);
	vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());

	std::cout << "Available extensions:\n";

	for (const auto& extension : extensions) {
		std::cout << '\t' << extension.extensionName << '\n';
	}
}

bool Engine::checkValidationLayerSupport() {
	uint32_t layerCount;
	vkEnumerateInstanceLayerProperties(&layerCount, nullptr);

	std::vector<VkLayerProperties> availableLayers(layerCount);
	vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());
	
	for (const char* layerName : validationLayers) {
		bool layerFound = false;
		
		for (const auto& layerProperties : availableLayers) {
			if (strcmp(layerName, layerProperties.layerName) == 0) {
				layerFound = true;
				break;
			}
		}	
		
		if (!layerFound) {
			return false;
		}
	}

	return true;
}
