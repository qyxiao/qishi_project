#pragma once
#include "Order.h"
#include <vector>
#include <string>
#include <iostream>
#include <json.hpp>
#include <fstream>

using json = nlohmann::json;

class TransactionMsg {
public:
	virtual void msg_generator(vector<string>& msg, Order& order);
	virtual void msg_reader(vector<string>& msgs, string file_path);
	virtual void msg_modifier(vector<string>& msgs, Order& order);
};