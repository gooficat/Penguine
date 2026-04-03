#pragma once

#include "GL.hxx"
#include "mathematics/Math.hxx"
#include <string>

namespace Penguine
{
namespace Rendering
{
class Shader
{
  public:
	Shader(const std::string &vertexPath, const std::string &fragmentPath, const std::string &geometryPath = "");
	~Shader();

	void Use() const;

	void SetBool(const std::string &name, bool value) const;
	void SetInt(const std::string &name, GL::Int value) const;
	void SetUInt(const std::string &name, GL::Uint value) const;
	void SetFloat(const std::string &name, GL::Float value) const;
	void SetVec(const std::string &name, Math::Vec2F value) const;
	void SetVec(const std::string &name, Math::Vec3F value) const;
	void SetVec(const std::string &name, Math::Vec4F value) const;
	void SetMat(const std::string &name, Math::Mat2F value) const;
	void SetMat(const std::string &name, Math::Mat3F value) const;
	void SetMat(const std::string &name, Math::Mat4F value) const;

  private:
	GL::Uint ID;
	GL::Uint CompileShader(const std::string &source, GL::Enum type);
};
} // namespace Rendering
} // namespace Penguine