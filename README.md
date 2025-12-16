## 3D physics engine

### Dependancies
---
**System Update:** `sudo apt update`  
**Build Tools:** `sudo apt install build-essential cmake ninja-build`  
**Vulkan Packages:** `sudo apt install libvulkan1 mesa-vulkan-drivers vulkan-tools`  
**Vulkan Libs:** `sudo apt install libvulkan-dev`  
**SPIR-V Debug Tools:** `sudo apt install vulkan-validationlayers spirv-tools`  
**GLFW Windowmanagement and GLM math:** `sudo apt install libglfw3-dev libglm-dev`  

#### Test Dependancies:
`vulkaninfo`
`vkcube`

### Compiling -> linking -> running:
---
1. cd into the build directory.  
2. `cmake .. && make && ./3DPhysicsEngine`  

### Learning Resources:
---
https://www.glfw.org/docs/latest/vulkan_guide.html
https://vulkan-tutorial.com/
