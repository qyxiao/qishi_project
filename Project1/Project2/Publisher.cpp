#include "Publisher.h"
#include <string>
#include <iostream>
#include <json.hpp>
#include <fstream>

using json = nlohmann::json;

void Publisher::deliver_msg(vector<string>& transactions) {
	ofstream outs(file_path, fstream::app);
	for (int i = 0; i < transactions.size(); i += 5) {

		json json_str = { {"Order ID", transactions[i]}, {"Symbol", transactions[i+1]}, 
		{"Price", transactions[i+2]}, {"Order Type", transactions[i+3]}, {"Time", transactions[i+4]}};

		outs << json_str << std::endl;
	}
}