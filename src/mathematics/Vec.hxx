#pragma once

#include <cstddef>
#include <initializer_list>

namespace Penguine
{
namespace Math
{
template <typename T, std::size_t N>
class Vec
{
  public:
	Vec(const T (&arr)[N])
	{
		for (std::size_t i = 0; i < N; ++i)
			data[i] = arr[i];
	}
	Vec(std::initializer_list<T> list)
	{
		std::size_t i = 0;
		for (auto &val : list)
		{
			if (i < N)
				data[i++] = val;
		}
	}
	Vec() = default;

	const T &Get() const
	{
		return data[0];
	}

	T operator[](const std::size_t &i) const
	{
		return data[i];
	}

  private:
	T data[N];
};

template <typename T, std::size_t N1, std::size_t N2>
class Mat : public Vec<Vec<T, N2>, N1>
{
  public:
	Mat(const Vec<Vec<T, N2>, N1> &arr) : Vec<Vec<T, N2>, N1>(arr)
	{
	}
	Mat() = default;
	const T &Get() const
	{
		return Vec<Vec<T, N2>, N1>::Get().Get();
	}
};

using Vec2F = Vec<float, 2>;
using Vec3F = Vec<float, 3>;
using Vec4F = Vec<float, 4>;

using Vec2I = Vec<int, 2>;
using Vec3I = Vec<int, 3>;
using Vec4I = Vec<int, 4>;

using Mat2F = Mat<float, 2, 2>;
using Mat3F = Mat<float, 3, 3>;
using Mat4F = Mat<float, 4, 4>;

using Mat2I = Mat<int, 2, 2>;
using Mat3I = Mat<int, 3, 3>;
using Mat4I = Mat<int, 4, 4>;

} // namespace Math
} // namespace Penguine