#include <PenguineCore.hpp>
#include <iostream>

class MyGame : public Penguine::Application {
public:
	MyGame() : Penguine::Application::Application() {
		std::cout << "Hello from the game!\n";
	}

	~MyGame() {

	}
};

void main() {
	auto game = new MyGame();
}