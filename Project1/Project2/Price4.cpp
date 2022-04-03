#pragma once
#include "Price4.h"
#include <algorithm>
#include <array>



Price4::Price4(const std::string& str) {
	int decimal_index = -1;
	for (int i = 0; i < (int)str.size(); i++) {
		if (str[i] == '.') {
			decimal_index = i;
			break;
		}
	}
	if (decimal_index > 0) {
		long integer_part = stol(str.substr(0, decimal_index));
		long float_part;
		if (integer_part < 1) {
			float_part = stol(str.substr(decimal_index + 1, min((int)str.size() - decimal_index-1, 4)))*padding[min((int)str.size() - decimal_index-1, 4)];
		}
		else {
			float_part = stol(str.substr(decimal_index + 1, min((int)str.size() - decimal_index-1, 2)))*padding[min((int)str.size() - decimal_index-1, 2)];
		}
		unscaled_ = integer_part * 10000 + float_part;
	}
	else if (decimal_index == 0) {
		unscaled_ = stol(str.substr(1, min((int)str.size() - 1, 4)))*padding[min((int)str.size() - 1, 4)];
	}
	else {
		unscaled_ = stol(str) * 10000;
	}
}

string Price4::to_str() const {
	string unscale_str = to_string(unscaled_ / 10000) + ".";
	string res = to_string(unscaled_ % 10000);
	if (unscaled_ > 10000) {
		unscale_str = unscale_str + string(max(0, 2 - (int)res.size()), '0') + res;
	}
	else {
		unscale_str = unscale_str + string(max(0, 4 - (int)res.size()), '0') + res;
	}
	return unscale_str;
}
