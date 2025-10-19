#ifndef GLOBAL_H
#define GLOBAL_H

// #include "lib/glad/gl.h"

#include "lib/glad/gl.h"

// #pragma comment(lib, "lib/glfw3.lib") // now that is disgusting

#define RGFW_OPENGL
#define RGFW_USE_XDL // feel free to remove this line if you don't want to use XDL (-lX11 -lXrandr -lGLX will be required)
#define RGFW_ALLOC_DROPFILES
// #define RGFW_IMPLEMENTATION
#define RGFW_PRINT_ERRORS
#define RGFW_DEBUG
#define GL_SILENCE_DEPRECATION
#include "lib/RGFW.h"


#define LINALG_FORWARD_COMPATIBLE
#include "lib/linalg.h"
using namespace linalg::aliases; // woo dangerous!

#include <cstdint>
#include <vector>
#include <cstring>
#include <iostream>
#include <map>
#include <memory>
#include <cmath>

using std::int8_t;
using std::int16_t;
using std::int32_t;
using std::int64_t;
using std::uint8_t;
using std::uint16_t;
using std::uint32_t;
using std::uint64_t;

#endif