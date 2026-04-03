#include "Mesh.hxx"
#include "GL.hxx"

namespace Penguine
{
namespace Rendering
{

Mesh::Mesh(const std::vector<Vertex> &vertices, const std::vector<Face> &faces)
{
	GenBuffers(vertices, faces);
}

void Mesh::Draw(const Shader &shader) const
{
	GL::BindVertexArray(m_vao);
	GL::DrawElements(GL::TRIANGLES, 3, GL::UNSIGNED_INT, nullptr);
	GL::BindVertexArray(0);
}

void Mesh::GenBuffers(const std::vector<Vertex> &vertices, const std::vector<Face> &faces)
{
	GL::GenVertexArrays(1, &m_vao);
	GL::GenBuffers(1, &m_vbo);
	GL::GenBuffers(1, &m_ebo);

	GL::BindVertexArray(m_vao);

	GL::BindBuffer(GL::ARRAY_BUFFER, m_vbo);
	GL::BufferData(GL::ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL::STATIC_DRAW);

	GL::BindBuffer(GL::ELEMENT_ARRAY_BUFFER, m_ebo);
	GL::BufferData(GL::ELEMENT_ARRAY_BUFFER, faces.size() * sizeof(Face), faces.data(), GL::STATIC_DRAW);

	// Position
	GL::EnableVertexAttribArray(0);
	GL::VertexAttribPointer(
		0, 3, GL::FLOAT, GL::FALSE, sizeof(Vertex), reinterpret_cast<void *>(offsetof(Vertex, position)));

	// Normal
	GL::EnableVertexAttribArray(1);
	GL::VertexAttribPointer(
		1, 3, GL::FLOAT, GL::FALSE, sizeof(Vertex), reinterpret_cast<void *>(offsetof(Vertex, normal)));

	// UV
	GL::EnableVertexAttribArray(2);
	GL::VertexAttribPointer(2, 2, GL::FLOAT, GL::FALSE, sizeof(Vertex), reinterpret_cast<void *>(offsetof(Vertex, uv)));

	GL::BindVertexArray(0);
}

} // namespace Rendering
} // namespace Penguine
