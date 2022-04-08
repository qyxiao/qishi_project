#pragma once
#include "MatchEngine.h"
#include "Order.h"
#include <vector>
class Loader {
	vector<MatchEngine*> engines;
	void deliver_order(Order order);
	void read_json(string filepath);
public:
	void process_orders(string filepath);
};
