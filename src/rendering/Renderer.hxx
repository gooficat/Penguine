#pragma once

namespace Penguine
{
namespace Rendering
{
class Renderer
{
  public:
	Renderer();
	~Renderer();
	void Render();

  private:
	void LoadGLExts();
};
} // namespace Rendering
} // namespace Penguine