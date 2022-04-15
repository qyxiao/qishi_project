#pragma once
#include "Order.h"
#include <vector>
#include <string>
#include <iostream>
#include <json.hpp>
#include <fstream>
#include <list>

using json = nlohmann::json;

class TransactionMsg {
public:
	virtual void msg_generator(list<string>& msg, Order& order);
	virtual void msg_reader(list<string>& msgs, string file_path);
	virtual void msg_modifier(list<string>& msgs, Order& order);
};