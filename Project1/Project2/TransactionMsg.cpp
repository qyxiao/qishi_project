#include "TransactionMsg.h"


void TransactionMsg::msg_generator(list<string>& msg, Order& order) {
	msg.push_back(to_string(order.get_order_id()));
	msg.push_back(to_string(order.get_quantity()));
	msg.push_back(order.get_type());
	msg.push_back(order.get_price().to_str());
}


void TransactionMsg::msg_modifier(list<string>& msg, Order& order) {
	msg.push_back(to_string(order.get_order_id()));
	//msg.push_back(time);
	msg.push_back(order.get_price().to_str());
	msg.push_back(order.get_symbol());

}


void TransactionMsg::msg_reader(list<string>& transactions, string file_path) {
	ofstream outs(file_path, fstream::app);
	auto msg_ptr = transactions.begin();
	for (int i = 0; i < (int)transactions.size() / 4; i++) {
		json json_str;
		json_str["Order ID"] = *msg_ptr++;
		json_str["Quantity"] = *msg_ptr++;
		json_str["Order Type"] = *msg_ptr++;
		json_str["Price"] = *msg_ptr++;
		//json_str["Time"] = *msg_ptr++;
		outs << json_str << std::endl;
	}
}