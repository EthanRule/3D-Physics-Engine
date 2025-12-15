#include <iostream>
#include "PhysicsEngine/engine.h"
using namespace std;

int main(void) {
	Engine& engine = Engine::getInstance();
	engine.blank();

	return 0; 
}
