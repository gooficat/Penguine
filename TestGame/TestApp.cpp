#include <Penguine.h>

class TestApp : public Penguine::App {
public:
	TestApp() : App(640, 320, "Test App") {

	}
	compl TestApp() {

	}
private:
};

Penguine::App* Penguine::CreateApp()
{
	return new TestApp();
}