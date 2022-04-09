#pragma once
#include<string>
#include <algorithm>
#include <array>
using namespace std;

class Price4 {
public:
	Price4() = default;

	explicit Price4(long unscaled) : unscaled_(unscaled) {}

	explicit Price4(const std::string& str);

	long unscaled() const { return unscaled_; }

	std::string to_str() const;

	Price4(const Price4& price) : Price4(price.unscaled_) {}

	static const Price4 MaxVal;

	static const Price4 MinVal;

	bool operator==(const Price4 &that) const
	{
		return this->unscaled() == that.unscaled();
	}
	bool operator!=(const Price4 &that) const
	{
		return this->unscaled() != that.unscaled();
	}
	bool operator<(const Price4 &that) const
	{
		return this->unscaled() < that.unscaled();
	}
	bool operator<=(const Price4 &that) const
	{
		return this->unscaled() <= that.unscaled();
	}
	bool operator>(const Price4 &that) const
	{
		return this->unscaled() > that.unscaled();
	}
	bool operator>=(const Price4 &that) const
	{
		return this->unscaled() >= that.unscaled();
	}

private:
	static constexpr array<int, 5> padding{ 10000, 1000, 100, 10, 1 };
	long unscaled_;
};


namespace std {

	template <>
	struct hash<Price4>
	{
		std::size_t operator()(const Price4& k) const
		{
			using std::size_t;
			using std::hash;
			using std::string;

			// Compute individual hash values for first,
			// second and third and combine them using XOR
			// and bit shifting:

			return  hash<long>()(k.unscaled());
		}
	};

}