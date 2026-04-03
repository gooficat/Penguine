#pragma once

#include <cstddef>
#include <initializer_list>
#include <iostream>

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
			if (i < N)
				data[i++] = val;
	}
	Vec() = default;
	Vec(const size_t v)
	{
		for (auto i = 0; i < N; ++i)
			data[i] = v;
	}

	const T &Get() const
	{
		return data[0];
	}

	T &operator[](const std::size_t &i)
	{
		return data[i];
	}

	T operator[](const std::size_t &i) const
	{
		return data[i];
	}

  private:
	T data[N];
};

template <typename T, std::size_t N>
class Mat : public Vec<Vec<T, N>, N>
{
  public:
	Mat(const Vec<Vec<T, N>, N> &arr) : Vec<Vec<T, N>, N>(arr)
	{
	}
	static constexpr Mat<T, N> Identity(const T v)
	{
		Mat<T, N> out;
		for (auto i = 0; i < N; ++i)
			for (auto j = 0; j < N; ++j)
				out[i][j] = i == j ? v : 0;
		return out;
	}
	static constexpr Mat<T, N> Identity()
	{
		return Identity(1);
	}

	Mat<T, N> operator*(const Mat<T, N> &m)
	{
		auto res = Mat<T, N>(0);
		for (auto i = 0; i < N; ++i)
			for (auto j = 0; j < N; ++j)
				for (auto k = 0; k < N; k++)
					res[i][j] += (*this)[i][k] * (m[k][j]);
		return res;
	}

	Mat<T, N> operator+(const Vec<T, N> &v)
	{
		auto res = *this;
		for (auto i = 0; i < N - 1; ++i)
			res[N - 1][i] += v[i];
		return res;
	}

	Mat<T, N> operator-(const Vec<T, N> &v)
	{
		auto res = *this;
		for (auto i = 0; i < N - 1; ++i)
			res[N - 1][i] -= v[i];
		return res;
	}

	Vec<T, N> operator*(const Vec<T, N> &v)
	{
		Mat<T, N> scalar(0);
		for (auto i = 0; i < N - 1; ++i)
			scalar[i][i] = v[i];
		return scalar * this;
	}

	Mat() = default;
	const T &Get() const
	{
		return Vec<Vec<T, N>, N>::Get().Get();
	}
};

using Vec2F = Vec<float, 2>;
using Vec3F = Vec<float, 3>;
using Vec4F = Vec<float, 4>;

using Vec2I = Vec<int, 2>;
using Vec3I = Vec<int, 3>;
using Vec4I = Vec<int, 4>;

using Mat2F = Mat<float, 2>;
using Mat3F = Mat<float, 3>;
using Mat4F = Mat<float, 4>;

using Mat2I = Mat<int, 2>;
using Mat3I = Mat<int, 3>;
using Mat4I = Mat<int, 4>;

} // namespace Math
} // namespace Penguine