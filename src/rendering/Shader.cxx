#include "Shader.hxx"

#include <fstream>
#include <iostream>

namespace Penguine::Rendering
{

std::string DumpFile(const std::string &path)
{
	std::ifstream file(path);
	std::string	  content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
	file.close();
	return content;
}

Shader::Shader(const std::string &vertexPath, const std::string &fragmentPath, const std::string &geometryPath)
{
	std::string vertexSource   = DumpFile(vertexPath);
	std::string fragmentSource = DumpFile(fragmentPath);
	GLuint		vertexShader   = CompileShader(vertexSource, GL_VERTEX_SHADER);
	GLuint		fragmentShader = CompileShader(fragmentSource, GL_FRAGMENT_SHADER);

	ID = glCreateProgram();
	glAttachShader(ID, vertexShader);
	glAttachShader(ID, fragmentShader);
	if (geometryPath.empty() == false)
	{
		std::string geometrySource = DumpFile(geometryPath);
		GLuint		geometryShader = CompileShader(geometrySource, GL_GEOMETRY_SHADER);
		glAttachShader(ID, geometryShader);
	}
	glLinkProgram(ID);

	char  infoLog[512];
	GLint success;
	glGetProgramiv(ID, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(ID, 512, NULL, infoLog);
		std::cerr << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

GLuint Shader::CompileShader(const std::string &source, GLenum type)
{
	GLuint		shader = glCreateShader(type);
	const char *src	   = source.c_str();
	glShaderSource(shader, 1, &src, NULL);
	glCompileShader(shader);
	char  infoLog[512];
	GLint success;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		std::cerr << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
	return shader;
}

Shader::~Shader()
{
}

void Shader::Use() const
{
}

void Shader::SetBool(const std::string &name, bool value) const
{
	glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
}
void Shader::SetInt(const std::string &name, GLint value) const
{
	glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}
void Shader::SetUInt(const std::string &name, GLuint value) const
{
	glUniform1ui(glGetUniformLocation(ID, name.c_str()), value);
}
void Shader::SetFloat(const std::string &name, float value) const
{
	glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}
void Shader::SetVec(const std::string &name, Mathematics::Vec<float, 2> value) const
{
	glUniform2fv(glGetUniformLocation(ID, name.c_str()), 1, &value.Get());
}
void Shader::SetVec(const std::string &name, Mathematics::Vec<float, 3> value) const
{
	glUniform3fv(glGetUniformLocation(ID, name.c_str()), 1, &value.Get());
}
void Shader::SetVec(const std::string &name, Mathematics::Vec<float, 4> value) const
{
	glUniform4fv(glGetUniformLocation(ID, name.c_str()), 1, &value.Get());
}
void Shader::SetMat(const std::string &name, Mathematics::Mat<float, 2, 2> value) const
{
	glUniformMatrix2fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &value.Get().Get());
}
void Shader::SetMat(const std::string &name, Mathematics::Mat<float, 3, 3> value) const
{
	glUniformMatrix3fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &value.Get().Get());
}
void Shader::SetMat(const std::string &name, Mathematics::Mat<float, 4, 4> value) const
{
	glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &value.Get().Get());
}

} // namespace Penguine::Rendering