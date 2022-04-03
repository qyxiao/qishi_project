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


struct Key
{
	std::string first;
	std::string second;
	int         third;

	bool operator==(const Key &other) const
	{
		return (first == other.first
			&& second == other.second
			&& third == other.third);
	}
};