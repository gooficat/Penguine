#include "app.h"

class TestApp : public App {
public:
  TestApp() : App() {
      scenes["hello"] = std::make_shared<Scene>();
      active_scene = "hello";

      ShaderResource vertShader(
        "C:\\Projects\\Penguine\\penguine_core\\resources\\test.vert",
        VERTEX_SHADER
      );
      vertShader.load();
      
      ShaderResource fragShader(
        "C:\\Projects\\Penguine\\penguine_core\\resources\\test.frag",
        FRAGMENT_SHADER
      );
      fragShader.load();
      
      MeshResource testMesh("C:\\Projects\\Penguine\\penguine_core\\resources\\cube.obj");
      testMesh.generateVAO(
        {
          {{-0.5f,-0.5f, 0.0f}},
          {{ 0.5f,-0.5f, 0.0f}},
          {{ 0.0f, 0.5f, 0.0f}}
        },
        {
          0, 1, 2
        }
      );

      scenes["hello"]->addLayer(
        std::shared_ptr<Camera>( new Camera(
          Camera::makePerspective(
            1.5f,
            (float)window->getWidth() / (float)window->getHeight(),
            0.1f, 1000.0f
          ),
          {0,0,0}, {0,0,0}
        )),
        std::shared_ptr<ShaderProgram>( new ShaderProgram({
          vertShader,
          fragShader
        }))
      );

      scenes["hello"]->addTickable(
        "testactor",
        new Tickable(

        )
      );

      scenes["hello"]->layers[0]->addViewable(
        "testmesh",
        new Viewable(
          
        )
      );
  }

private:
};

int main(void)
{
  auto *app = new TestApp();

  app->run();

  return 0;
}
