#pragma once

#include "mathematics/Vec.hxx"
#include "third_party/glad/gl.h"
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
	void SetInt(const std::string &name, GLint value) const;
	void SetUInt(const std::string &name, GLuint value) const;
	void SetFloat(const std::string &name, GLfloat value) const;
	void SetVec(const std::string &name, Mathematics::Vec<float, 2> value) const;
	void SetVec(const std::string &name, Mathematics::Vec<float, 3> value) const;
	void SetVec(const std::string &name, Mathematics::Vec<float, 4> value) const;
	void SetMat(const std::string &name, Mathematics::Mat<float, 2, 2> value) const;
	void SetMat(const std::string &name, Mathematics::Mat<float, 3, 3> value) const;
	void SetMat(const std::string &name, Mathematics::Mat<float, 4, 4> value) const;

  private:
	GLuint ID;
	GLuint CompileShader(const std::string &source, GLenum type);
};
} // namespace Rendering
} // namespace Penguine