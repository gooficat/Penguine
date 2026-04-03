#pragma once

#include "mathematics/Vec.hxx"
#include <cstdint>

namespace Penguine
{
namespace Rendering
{
class Renderer
{
  public:
	Renderer(const Math::Vec<std::uint16_t, 2> &size);
	~Renderer();
	void Render();

  private:
	void LoadGLExts();
};
} // namespace Rendering
} // namespace Penguine