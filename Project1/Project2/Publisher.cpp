#include "Publisher.h"
#include <string>
#include <iostream>
#include <json.hpp>
#include <fstream>

using json = nlohmann::json;

//void Publisher::deliver_msg(list<string>& transactions) {
//	messenger->msg_reader(transactions, file_path);
//	for (auto str : transactions) {
//		cout << str << ", ";
//	}
//	cout << endl;
//}


void Publisher::deliver_msg(std::future<list<string>>&& future_transactions) {
	auto transactions = future_transactions.get();
	messenger->msg_reader(transactions, file_path);
	for (auto str : transactions) {
		cout << str << ", ";
	}
	cout << endl;
}