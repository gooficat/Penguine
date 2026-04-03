#define GLXXI
#include "GL.hxx"
#include <stdexcept>
#ifdef _WIN32
#include <Windows.h>
#endif

#define TGLLF(p)                                                                                                       \
	p = decltype(p)(LoadFunc("gl" #p));                                                                                \
	if (!p)                                                                                                            \
		throw std::runtime_error("Failed to load OpenGL function");

namespace GL
{
void *LoadFunc(const char *name)
{
	void *p;
#ifdef _WIN32
	p = (void *)wglGetProcAddress(name);
	if (p == 0 || (p == (void *)0x1) || (p == (void *)0x2) || (p == (void *)0x3) || (p == (void *)-1))
	{
		static HMODULE module = LoadLibraryA("opengl32.dll");
		p					  = (void *)GetProcAddress(module, name);
	}
#endif
	return p;
}

void Load()
{
	TGLLF(Viewport);
	TGLLF(ClearColor);
	TGLLF(Clear);
	TGLLF(CreateShader);
	TGLLF(ShaderSource);
	TGLLF(CompileShader);
	TGLLF(DeleteShader);
	TGLLF(CreateProgram);
	TGLLF(AttachShader);
	TGLLF(LinkProgram);
	TGLLF(DeleteProgram);
	TGLLF(GetProgramiv);
	TGLLF(GetShaderiv);
	TGLLF(GetProgramInfoLog);
	TGLLF(GetShaderInfoLog);
	TGLLF(UseProgram);
	TGLLF(GenBuffers);
	TGLLF(BindBuffer);
	TGLLF(BufferData);
	TGLLF(GenVertexArrays);
	TGLLF(BindVertexArray);
	TGLLF(VertexAttribPointer);
	TGLLF(EnableVertexAttribArray);
	TGLLF(DrawElements);
	TGLLF(GetUniformLocation);
	TGLLF(Uniform1i);
	TGLLF(Uniform1ui);
	TGLLF(Uniform1f);
	TGLLF(Uniform2fv);
	TGLLF(Uniform3fv);
	TGLLF(Uniform4fv);
	TGLLF(UniformMatrix2fv);
	TGLLF(UniformMatrix3fv);
	TGLLF(UniformMatrix4fv);
}

} // namespace GL