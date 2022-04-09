#pragma once
#include <json.hpp>
#include <string>


using namespace std;

class Publisher {
	string file_path;
public:
	Publisher(string fp):file_path(fp){}

	void deliver_msg(vector<string>& transactions);
};