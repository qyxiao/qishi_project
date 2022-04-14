#include "TransactionMsg.h"


void TransactionMsg::msg_generator(vector<string>& msg, Order& order) {
	msg.push_back(to_string(order.get_order_id()));
	msg.push_back(to_string(order.get_quantity()));
	msg.push_back(order.get_type());
	msg.push_back(order.get_price().to_str());
}


void TransactionMsg::msg_modifier(vector<string>& msg, Order& order) {
	msg.push_back(to_string(order.get_order_id()));
	//msg.push_back(time);
	msg.push_back(order.get_price().to_str());
	msg.push_back(order.get_symbol());

}


void TransactionMsg::msg_reader(vector<string>& transactions, string file_path) {
	ofstream outs(file_path, fstream::app);
	for (int i = 0; i < (int)transactions.size(); i += 5) {

		json json_str = { {"Order ID", transactions[i]}, {"Symbol", transactions[i + 1]},
		{"Price", transactions[i + 2]}, {"Order Type", transactions[i + 3]}, {"Time", transactions[i + 4]} };

		outs << json_str << std::endl;
	}
}