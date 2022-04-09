#include "TransactionMsg.h"


vector<string> TransactionMsg::msg_generator(Order order) {
	vector<string> result;
	return result;
}


void TransactionMsg::msg_reader(vector<string>& transactions, string file_path) {
	ofstream outs(file_path, fstream::app);
	for (int i = 0; i < (int)transactions.size(); i += 5) {

		json json_str = { {"Order ID", transactions[i]}, {"Symbol", transactions[i + 1]},
		{"Price", transactions[i + 2]}, {"Order Type", transactions[i + 3]}, {"Time", transactions[i + 4]} };

		outs << json_str << std::endl;
	}
}