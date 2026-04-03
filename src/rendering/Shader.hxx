#pragma once

#include "GL.hxx"
#include "mathematics/Vec.hxx"
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
	void SetVec(const std::string &name, Mathematics::Vec<float, 2> value) const;
	void SetVec(const std::string &name, Mathematics::Vec<float, 3> value) const;
	void SetVec(const std::string &name, Mathematics::Vec<float, 4> value) const;
	void SetMat(const std::string &name, Mathematics::Mat<float, 2, 2> value) const;
	void SetMat(const std::string &name, Mathematics::Mat<float, 3, 3> value) const;
	void SetMat(const std::string &name, Mathematics::Mat<float, 4, 4> value) const;

  private:
	GL::Uint ID;
	GL::Uint CompileShader(const std::string &source, GL::Enum type);
};
} // namespace Rendering
} // namespace Penguine