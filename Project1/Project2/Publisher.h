#pragma once
#include <json.hpp>
#include <string>
#include "TransactionMsg.h"


using namespace std;

class Publisher {
	string file_path;
	TransactionMsg* messenger;

public:
	Publisher(string fp, TransactionMsg* tm):file_path(fp), messenger(tm){}

	void deliver_msg(vector<string>& transactions);
};