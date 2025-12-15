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
	
	void blank();
private:
	Engine() = default;

protected:
	
};
