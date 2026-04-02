#include "Renderer.hxx"

#include "third_party/glad/gl.h"

#pragma comment(lib, "opengl32.lib")

namespace Penguine
{
namespace Rendering
{

Renderer::Renderer()
{
	gladLoaderLoadGL();
}

Renderer::~Renderer()
{
}

void Renderer::Render()
{
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

} // namespace Rendering
} // namespace Penguine