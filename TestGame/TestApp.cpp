#include <Penguine.h>

class TestApp : public Penguine::App {
public:
	TestApp() : App("Test App", 640, 320) {

	}
	compl TestApp() {

	}
private:
};

Penguine::App* Penguine::CreateApp()
{
	return new TestApp();
}