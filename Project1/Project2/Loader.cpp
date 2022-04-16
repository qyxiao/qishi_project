#include "Loader.h"
#include "Order.h"

void Loader::deliver_order(Order order) {

}

void Loader::process_orders(string filepath) {
	std::ifstream ins(filepath);
	json j;
	string line;
	std::deque<std::future<void>> visualize_futures;
	int pipeline_depth = 10;
	while (std::getline(ins, line)) {
		j = json::parse(line);
		Order od = Order(j["Time"], j["Type"], j["OrderId"], j["Symbol"], j["Side"], j["Quantity"], Price4(j["Price"]));
		od.print_content();
		//engines[0]->handle_order(od);

		auto future_1 = std::async(std::launch::async, &MatchEngine::handle_order, &(*engines[0]), od);
		auto future_2 = std::async(std::launch::async, &Publisher::deliver_msg, &(*publisher), std::move(future_1));
		visualize_futures.push_back(std::move(future_2));
		if ((int)visualize_futures.size() > pipeline_depth)
		{
			// At this point the main thread will call a destructor of the oldest future,
			// which in its turn will block until the thread gets joined.
			visualize_futures.pop_front();
		}
	}
}

void Loader::read_json(string filepath) {
	

}