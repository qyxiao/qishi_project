#include "Publisher.h"
#include <string>
#include <iostream>
#include <json.hpp>
#include <fstream>

using json = nlohmann::json;

void Publisher::deliver_msg(list<string>& transactions) {
	messenger->msg_reader(transactions, file_path);
	for (auto str : transactions) {
		cout << str << ", ";
	}
	cout << endl;
}