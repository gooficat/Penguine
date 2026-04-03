#pragma once

#include <cstdint>
#include <vector>

#include "GL.hxx"
#include "Shader.hxx"
#include "mathematics/Vec.hxx"

namespace Penguine
{
namespace Rendering
{
class Vertex
{
  public:
	Mathematics::Vec<float, 3> position;
	Mathematics::Vec<float, 3> normal;
	Mathematics::Vec<float, 2> uv;
};

class Face
{
  public:
	Mathematics::Vec<std::uint32_t, 3> indices;
};

class Mesh
{
  public:
	Mesh(const std::vector<Vertex> &vertices, const std::vector<Face> &faces);

	void Draw(const Shader &shader) const;

  private:
	void GenBuffers(const std::vector<Vertex> &vertices, const std::vector<Face> &faces);

	GL::Uint m_vao, m_vbo, m_ebo;
};
} // namespace Rendering
} // namespace Penguine