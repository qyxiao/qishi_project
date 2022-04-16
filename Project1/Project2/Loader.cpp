#include "Loader.h"
#include "Order.h"

void Loader::deliver_order(Order order) {

}

void Loader::process_orders(string filepath) {
	std::ifstream ins(filepath);
	json j;
	string line;
	std::deque<std::future<void>> to_process_order_pool;
	int pipeline_depth = 10;
	unordered_map<string, std::atomic<unsigned int>> symbol_currentIdx;
	unordered_map<string, unsigned int> symbol_assignedId;

	while (std::getline(ins, line)) {
		j = json::parse(line);
		Order od = Order(j["Time"], j["Type"], j["OrderId"], j["Symbol"], j["Side"], j["Quantity"], Price4(j["Price"]));
		od.print_content();
		string symbol = od.get_symbol();
		if (symbol_assignedId.find(symbol) == symbol_assignedId.end()) {
			symbol_assignedId[symbol] = 0;
			symbol_currentIdx[symbol] = 0;
		}
		//future<list<string>> future_1;
		//should use a better hash for distributing traffic
		auto future_1 = std::async(std::launch::deferred, &MatchEngine::handle_order, &(*engines[symbol[0]-'A']), od, symbol_assignedId[symbol], std::ref(symbol_currentIdx[symbol]));
		symbol_assignedId[symbol]++;
		auto future_2 = std::async(std::launch::deferred, &Publisher::deliver_msg, &(*publisher), std::move(future_1));
		to_process_order_pool.push_back(std::move(future_2));
		if ((int)to_process_order_pool.size() > pipeline_depth)
		{
			to_process_order_pool.pop_front();
		}
	}

	for (auto& fut : to_process_order_pool)
	{
		fut.get();
	}
}

void Loader::read_json(string filepath) {
	

}