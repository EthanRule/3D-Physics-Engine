# 3D Physics Engine
3D Physics Engine built with Vulkan.

## Dependancies

**Install All:**
```
sudo apt update && sudo apt install -y build-essential cmake ninja-build libvulkan1 mesa-vulkan-drivers vulkan-tools libvulkan-dev vulkan-validationlayers spirv-tools libglfw3-dev libglm-dev
```

<details>

  
<summary>Click to install one at a time</summary>
  
**System Update:**
```
sudo apt update
```

**Build Tools:** 
```
sudo apt install build-essential cmake ninja-build
```  
**Vulkan Packages:** 
```
sudo apt install libvulkan1 mesa-vulkan-drivers vulkan-tools
```  
**Vulkan Libs:** 
```
sudo apt install libvulkan-dev
```  
**SPIR-V Debug Tools:** 
```
sudo apt install vulkan-validationlayers spirv-tools
```  
**GLFW Window management and GLM math:**
```
sudo apt install libglfw3-dev libglm-dev
```  
</details>


#### Test Dependencies with:
```
vulkaninfo
```  
```
vkcube
```  

### Build and run:
1. cd into the build directory.  
2.
```
cmake .. && make && ./3DPhysicsEngine
```

### Credits:
https://www.vulkan.org/  
https://gcc.gnu.org/  

### Resources:
https://vulkan-tutorial.com  
https://cplusplus.com/  
