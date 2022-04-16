#pragma once
#include "MatchEngine.h"
#include "Order.h"
#include <vector>
#include <iostream>
#include <json.hpp>
#include <fstream>
#include "Price4.h"
#include <future>
#include <deque>
#include "Publisher.h"
#include <utility>
//#include <chrono>

using json = nlohmann::json;


class Loader {
	vector<MatchEngine*> engines;
	Publisher* publisher;
	void deliver_order(Order order);
	void read_json(string filepath);
public:
	Loader(vector<MatchEngine*> engines) :engines(engines), publisher(engines[0]->get_publisher()) {}

	void process_orders(string filepath);
};
