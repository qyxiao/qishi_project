#include<string>
using namespace std;

class Price4 {
public:
	Price4() = default;

	explicit Price4(long unscaled) : unscaled_(unscaled) {}

	explicit Price4(const std::string& str) {
		unscaled_ = stol(str.substr(0, str.size() - 5)) * 10000 + stol(str.substr(str.size() - 5, 4));
	}

	long unscaled() const { return unscaled_; }

	std::string to_str() const {
		string unscale_str = to_string(unscaled_ / 10000) + ".";
		string res = to_string(unscaled_ % 10000);
		unscale_str = unscale_str + string(4 - res.size(), '0') + res;
		return unscale_str;
	}

private:
	long unscaled_;
};