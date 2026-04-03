#pragma once

#include <cstdint>
#include <initializer_list>

#include "GL.hxx"
#include "Shader.hxx"
#include "mathematics/Math.hxx"

namespace Penguine
{
namespace Rendering
{
class Vertex
{
  public:
	Math::Vec3F position;
	Math::Vec3F normal;
	Math::Vec2F uv;

	Vertex() = default;
	Vertex(std::initializer_list<float> p, std::initializer_list<float> n, std::initializer_list<float> u)
		: position(p), normal(n), uv(u)
	{
	}
	Vertex(const Vertex &)			  = default;
	Vertex &operator=(const Vertex &) = default;
};

class Face
{
  public:
	Math::Vec3I indices;
	Face(std::initializer_list<std::int32_t> i) : indices(i)
	{
	}
	Face()						  = default;
	Face(const Face &)			  = default;
	Face &operator=(const Face &) = default;
};

class Mesh
{
  public:
	Mesh(std::initializer_list<Vertex> vertices, std::initializer_list<Face> faces);

	void Draw(const Shader &shader) const;

  private:
	void GenBuffers(std::initializer_list<Vertex> vertices, std::initializer_list<Face> faces);

	GL::Uint m_vao, m_vbo, m_ebo;
};
} // namespace Rendering
} // namespace Penguine