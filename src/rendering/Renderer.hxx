#pragma once

#include "mathematics/Math.hxx"
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
	void Clear();

  private:
	void LoadGLExts();
};
} // namespace Rendering
} // namespace Penguine