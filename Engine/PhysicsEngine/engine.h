#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <stdexcept>
#include <cstdlib>
#include <vector>

/* 
This is the main class for the backend of the 3D Physics Engine.
Design Patterns: Singleton, Information Expert.
*/

class Engine {
public:
	static Engine& getInstance() {
		static Engine instance;
		return instance;
	}

	// Delete all operators to ensure only one instance of `Engine` exists.
	Engine(const Engine&) = delete; // Copy constructor
	Engine& operator=(const Engine&) = delete; // Assignment operator
	Engine(Engine&&) = delete; // Move constructor
	Engine& operator=(Engine&&) = delete; // Move assignment
	
	void run();
private:
	const uint32_t WIDTH = 800;
	const uint32_t HEIGHT = 600;
	const std::vector<const char*> validationLayers = {
		"VK_LAYER_KHRONOS_validation"
	};
	
	#ifdef NDEBUG
		const bool enableValidationLayers = false;
	#else
		const bool enableValidationLayers = true;
	#endif
	
	GLFWwindow* window;
	VkInstance instance;
	VkDebugUtilsMessengerEXT debugMessenger;
	Engine() = default;
	void initVulkan();
	void setupDebugMessenger();
	void initWindow();
	void mainLoop();
	void cleanup();
	void createInstance();
	bool checkValidationLayerSupport();
	std::vector<const char*> getRequiredExtensions();
	static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
			VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
			VkDebugUtilsMessageTypeFlagsEXT messageType,
			const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
			void* pUserData);


protected:
	
};
