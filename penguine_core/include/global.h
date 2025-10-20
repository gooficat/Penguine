#ifndef GLOBAL_H
#define GLOBAL_H

// #include "lib/glad/gl.h"

#include "lib/glad/gl.h"

// #pragma comment(lib, "lib/glfw3.lib") // now that is disgusting

#define RGFW_OPENGL
#define RGFW_USE_XDL
#define RGFW_ALLOC_DROPFILES
#define RGFW_PRINT_ERRORS
#define RGFW_DEBUG
#define GL_SILENCE_DEPRECATION
#include "lib/RGFW.h"

#include "lib/stb_image.h"


#define LINALG_FORWARD_COMPATIBLE
#include "lib/linalg.h"

#include "lib/json.hpp"

using linalg::aliases::float1;
using linalg::aliases::float2;
using linalg::aliases::float3;
using linalg::aliases::float4;

using linalg::aliases::int1;
using linalg::aliases::int2;
using linalg::aliases::int3;
using linalg::aliases::int4;

using linalg::aliases::float4x4;


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

using std::unique_ptr;
using std::shared_ptr;

using std::make_shared;
using std::make_unique;

using std::string;

#endif