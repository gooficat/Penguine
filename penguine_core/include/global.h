#pragma once

#include "lib/glad/gl.h"

#define RGFW_OPENGL
#include "lib/RGFW.h"

#define LINALG_FORWARD_COMPATIBLE
#include "lib/linalg.h"
using namespace linalg::aliases; // woo dangerous!

#include <cstdint>
#include <vector>
#include <cstring>

using std::int8_t;
using std::int16_t;
using std::int32_t;
using std::int64_t;
using std::uint8_t;
using std::uint16_t;
using std::uint32_t;
using std::uint64_t;
