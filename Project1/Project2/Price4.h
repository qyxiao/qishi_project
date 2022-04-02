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

private:
	static constexpr array<int, 5> padding{ 10000, 1000, 100, 10, 1 };
	long unscaled_;
};