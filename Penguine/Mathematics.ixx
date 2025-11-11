export module Mathematics;

import <cstdint>;


export
template<size_t N, typename T>
class Vec
{
public:
	T& operator[] ( size_t i )
	{
		return data [ i ];
	}
private:
	T data [ N ] {};
};

using Vec2 = Vec < 2, float>;
using Vec3 = Vec < 2, float>;
using Vec4 = Vec < 2, float>;

using Mat2 = Vec < 4, Vec<4, float>>;
using Mat3 = Vec < 4, Vec<4, float>>;
using Mat4 = Vec < 4, Vec<4, float>>;

