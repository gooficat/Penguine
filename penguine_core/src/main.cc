#include "app.h"

class TestApp : public App {
public:
  TestApp() : App() {

  }


private:
};

int main(void)
{
  auto *app = new TestApp();

  app->run();

  
  return 0;
}
