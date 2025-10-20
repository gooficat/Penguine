#include "app.h"

// class TestApp : public App {
// public:
//   TestApp() : App() {
//       scenes["hello"] = make_shared<Scene>();
//       active_scene = "hello";

//       ShaderResource vertShader(
//         "C:\\Projects\\Penguine\\penguine_core\\resources\\test.vert",
//         VERTEX_SHADER
//       );
//       vertShader.load();
      
//       ShaderResource fragShader(
//         "C:\\Projects\\Penguine\\penguine_core\\resources\\test.frag",
//         FRAGMENT_SHADER
//       );
//       fragShader.load();
      
//       shared_ptr<MeshResource> testMesh( new MeshResource("C:\\Projects\\Penguine\\penguine_core\\resources\\cube.obj"));
//       testMesh->generateVAO( // this should be internal later but for now it is just in here
//         {
//           {{-0.5f,-0.5f, 0.0f}},
//           {{ 0.5f,-0.5f, 0.0f}},
//           {{ 0.0f, 0.5f, 0.0f}}
//         },
//         {
//           0, 1, 2
//         }
//       );

//       shared_ptr<Camera> testCam(
//         new Camera(
//           Camera::makePerspective(
//             1.5f,
//             (float)window->getWidth() / (float)window->getHeight(),
//             0.1f, 1000.0f
//           ),
//           {0,0,0}, {0,0,0}
//         )
//       );

//       shared_ptr<ShaderProgram> simpShaderProgram(
//         new ShaderProgram(
//           vertShader,
//           fragShader
//         )
//       );

//       scenes["hello"]->addLayer(
//         testCam,
//         simpShaderProgram
//       );

//       shared_ptr<Tickable> testTickable(
//         new Tickable(
          
//         )
//       );

//       shared_ptr<Viewable> testViewable(
//         new MeshViewable(
//           testMesh
//         )
//       );

//       scenes["hello"]->addTickable(
//         "testtickable",
//         testTickable
//       );

//       scenes["hello"]->layers[0]->addViewable(
//         "testviewable",
//         testViewable
//       );
//   }

// private:
// };

int main(void)
{
  auto *app = new App("app.json");

  app->run();

  return 0;
}
