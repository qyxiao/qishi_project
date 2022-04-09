#pragma once
#include "Order.h"
#include <vector>
#include <string>
#include <string>
#include <iostream>
#include <json.hpp>
#include <fstream>

using json = nlohmann::json;

class TransactionMsg {
public:
	virtual vector<string> msg_generator(Order order);
	virtual void msg_reader(vector<string>& msgs, string file_path);
};