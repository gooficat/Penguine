#pragma once

#include <cstdint>
#ifdef GLXXI
#define GLXXE
#define GLXXN = NULL
#else
#define GLXXE extern
#define GLXXN
#endif

#define GLXXF(t, n, ...) GLXXE t (*n)(__VA_ARGS__) GLXXN

#undef FALSE

namespace GL
{

using Boolean  = bool;
using Byte	   = std::int8_t;
using UByte	   = std::uint8_t;
using Enum	   = std::uint32_t;
using Uint	   = std::uint32_t;
using Int	   = std::int32_t;
using Sizei	   = std::uint32_t;
using Int64	   = std::int64_t;
using Uint64   = std::uint64_t;
using Short	   = std::int16_t;
using UShort   = std::uint16_t;
using IntPtr   = std::intptr_t;
using SizeiPtr = std::uintptr_t;
using BitField = std::uint32_t;
using Float	   = float;
using Double   = double;

enum : BitField
{
	COLOR_BUFFER_BIT	 = 0x00004000,
	DEPTH_BUFFER_BIT	 = 0x00000100,
	VERTEX_SHADER		 = 0x8B31,
	FRAGMENT_SHADER		 = 0x8B30,
	GEOMETRY_SHADER		 = 0x8DD9,
	COMPILE_STATUS		 = 0x8B81,
	LINK_STATUS			 = 0x8B82,
	STATIC_DRAW			 = 0x88E4,
	ARRAY_BUFFER		 = 0x8892,
	ELEMENT_ARRAY_BUFFER = 0x8893,
	TRIANGLES			 = 0x0004,
	UNSIGNED_INT		 = 0x1405,
	FLOAT				 = 0x1406,
	FALSE				 = 0,
};

void *LoadFunc(const char *name);
void  Load();

GLXXF(void, Viewport, Int, Int, Sizei, Sizei);
GLXXF(void, ClearColor, Float, Float, Float, Float);
GLXXF(void, Clear, BitField);
GLXXF(Uint, CreateShader, Enum);
GLXXF(void, ShaderSource, Uint, Sizei, const char **, const Int *);
GLXXF(void, CompileShader, Uint);
GLXXF(void, DeleteShader, Uint);
GLXXF(Uint, CreateProgram);
GLXXF(void, AttachShader, Uint, Uint);
GLXXF(void, LinkProgram, Uint);
GLXXF(void, GetShaderiv, Uint, Enum, Int *);
GLXXF(void, GetProgramiv, Uint, Enum, Int *);
GLXXF(void, UseProgram, Uint);
GLXXF(void, GenBuffers, Sizei, Uint *);
GLXXF(void, BindBuffer, Enum, Uint);
GLXXF(void, BufferData, Enum, SizeiPtr, const void *, Enum);
GLXXF(void, GenVertexArrays, Sizei, Uint *);
GLXXF(void, BindVertexArray, Uint);
GLXXF(void, VertexAttribPointer, Uint, Int, Enum, Boolean, Sizei, const void *);
GLXXF(void, EnableVertexAttribArray, Uint);
GLXXF(void, DrawElements, Enum, Sizei, Enum, const void *);
GLXXF(Int, GetUniformLocation, Uint, const char *);
GLXXF(void, DeleteProgram, Uint);
GLXXF(void, GetProgramInfoLog, Uint, Sizei, Sizei *, char *);
GLXXF(void, GetShaderInfoLog, Uint, Sizei, Sizei *, char *);
GLXXF(void, Uniform1i, Int, Int);
GLXXF(void, Uniform1ui, Int, Uint);
GLXXF(void, Uniform1f, Int, Float);
GLXXF(void, Uniform2fv, Int, Sizei, const Float *);
GLXXF(void, Uniform3fv, Int, Sizei, const Float *);
GLXXF(void, Uniform4fv, Int, Sizei, const Float *);
GLXXF(void, UniformMatrix2fv, Int, Sizei, Boolean, const Float *);
GLXXF(void, UniformMatrix3fv, Int, Sizei, Boolean, const Float *);
GLXXF(void, UniformMatrix4fv, Int, Sizei, Boolean, const Float *);

} // namespace GL