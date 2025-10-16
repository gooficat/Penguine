#pragma once

#include "Api.h"

#include "Vec.h"

namespace Penguine {
	enum class KeyCode {
		LMB = 0x01,
		RMB,
		MMB = 0x04,
		N0 = 0x30,
		N1,
		N2,
		N3,
		N4,
		N5,
		N6,
		N7,
		N8,
		N9,
		A = 0x41,
		B,
		C,
		D,
		E,
		F,
		G,
		H,
		I,
		J,
		K,
		L,
		M,
		N,
		O,
		P,
		Q,
		R,
		S,
		T,
		U,
		V,
		W,
		X,
		Y,
		Z,
	};
	class PENGUINE_API EventHandler {
	public:
		bool IsKeyDown(KeyCode key) {
			// implement as per winapi or whatever platform
		}
		Vec2 GetMousePos() {
			// implement as per winapi or whatever platform
		}
	private:
	};
};