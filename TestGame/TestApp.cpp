#include <Penguine.h>

class TestApp : public Penguine::App {
public:
	TestApp() {

	}
	compl TestApp() {

	}
private:
};

Penguine::App* Penguine::CreateApp()
{
	return new TestApp();
}