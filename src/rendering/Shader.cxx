#include "Shader.hxx"
#include "GL.hxx"

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
	GL::Uint	vertexShader   = CompileShader(vertexSource, GL::VERTEX_SHADER);
	GL::Uint	fragmentShader = CompileShader(fragmentSource, GL::FRAGMENT_SHADER);

	ID = GL::CreateProgram();
	GL::AttachShader(ID, vertexShader);
	GL::AttachShader(ID, fragmentShader);
	if (geometryPath.empty() == false)
	{
		std::string geometrySource = DumpFile(geometryPath);
		GL::Uint	geometryShader = CompileShader(geometrySource, GL::GEOMETRY_SHADER);
		GL::AttachShader(ID, geometryShader);
	}
	GL::LinkProgram(ID);

	char	infoLog[512];
	GL::Int success;
	GL::GetProgramiv(ID, GL::LINK_STATUS, &success);
	if (!success)
	{
		GL::GetProgramInfoLog(ID, 512, NULL, infoLog);
		std::cerr << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}

	GL::DeleteShader(vertexShader);
	GL::DeleteShader(fragmentShader);
}

GL::Uint Shader::CompileShader(const std::string &source, GL::Enum type)
{
	GL::Uint	shader = GL::CreateShader(type);
	const char *src	   = source.c_str();
	GL::ShaderSource(shader, 1, &src, NULL);
	GL::CompileShader(shader);
	char	infoLog[512];
	GL::Int success;
	GL::GetShaderiv(shader, GL::COMPILE_STATUS, &success);
	if (!success)
	{
		GL::GetShaderInfoLog(shader, 512, NULL, infoLog);
		std::cerr << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
	return shader;
}

Shader::~Shader()
{
	GL::DeleteProgram(ID);
}

void Shader::Use() const
{
	GL::UseProgram(ID);
}

void Shader::SetBool(const std::string &name, bool value) const
{
	GL::Uniform1i(GL::GetUniformLocation(ID, name.c_str()), (int)value);
}
void Shader::SetInt(const std::string &name, GL::Int value) const
{
	GL::Uniform1i(GL::GetUniformLocation(ID, name.c_str()), value);
}
void Shader::SetUInt(const std::string &name, GL::Uint value) const
{
	GL::Uniform1ui(GL::GetUniformLocation(ID, name.c_str()), value);
}
void Shader::SetFloat(const std::string &name, float value) const
{
	GL::Uniform1f(GL::GetUniformLocation(ID, name.c_str()), value);
}
void Shader::SetVec(const std::string &name, Math::Vec2F value) const
{
	GL::Uniform2fv(GL::GetUniformLocation(ID, name.c_str()), 1, &value.Get());
}
void Shader::SetVec(const std::string &name, Math::Vec3F value) const
{
	GL::Uniform3fv(GL::GetUniformLocation(ID, name.c_str()), 1, &value.Get());
}
void Shader::SetVec(const std::string &name, Math::Vec4F value) const
{
	GL::Uniform4fv(GL::GetUniformLocation(ID, name.c_str()), 1, &value.Get());
}
void Shader::SetMat(const std::string &name, Math::Mat2F value) const
{
	GL::UniformMatrix2fv(GL::GetUniformLocation(ID, name.c_str()), 1, GL::FALSE, &value.Get());
}
void Shader::SetMat(const std::string &name, Math::Mat3F value) const
{
	GL::UniformMatrix3fv(GL::GetUniformLocation(ID, name.c_str()), 1, GL::FALSE, &value.Get());
}
void Shader::SetMat(const std::string &name, Math::Mat4F value) const
{
	GL::UniformMatrix4fv(GL::GetUniformLocation(ID, name.c_str()), 1, GL::FALSE, &value.Get());
}

} // namespace Penguine::Rendering