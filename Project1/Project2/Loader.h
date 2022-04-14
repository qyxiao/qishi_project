#pragma once
#include "MatchEngine.h"
#include "Order.h"
#include <vector>
#include <iostream>
#include <json.hpp>
#include <fstream>
#include "Price4.h"

using json = nlohmann::json;


class Loader {
	vector<MatchEngine*> engines;
	void deliver_order(Order order);
	void read_json(string filepath);
public:
	Loader(vector<MatchEngine*> engines) :engines(engines) {}

	void process_orders(string filepath);
};
