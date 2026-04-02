#pragma once

#include <cstddef>

namespace Penguine
{
namespace Mathematics
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
};

} // namespace Mathematics
} // namespace Penguine