#pragma once

#include "Api.h"

struct Vec
{
	// this is a generic parent class and is only for inheritance
};

struct PENGUINE_API Vec2 : public Vec {
	float x;
	float y;
};