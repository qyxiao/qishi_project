#include "OrderBook.h"
#include "Order.h"
int OrderBook::get_quantity(Price4 price) {
	if (price_quantity.find(price) != price_quantity.end()) {
		return price_quantity[price];
	}
	return 0;
}

vector<int> OrderBook::ask_price_quantity(Price4 price, int quantity) {
	vector<int> result;
	if (price_quantity[price] == quantity) {
		for (auto pq : asks[price]) {
			result.push_back(pq->get_order_id());
			order_pool.erase(pq);
		}
		asks.erase(price);
		price_quantity.erase(price);
	}
	else {
		//missing 
	}
	return result;
}

vector<int> OrderBook::bid_price_quantity(Price4 price, int quantity) {
	vector<int> result;
	if (price_quantity[price] == quantity) {
		for (auto pq : bids[price]) {
			result.push_back(pq->get_order_id());
			order_pool.erase(pq);
		}
		bids.erase(price);
		price_quantity.erase(price);
	}
	else {
		//missing 
	}
	return result;
}


void OrderBook::add_pool(Order order) {
	Price4 price = order.get_price();
	int quantity = order.get_quantity();
	price_quantity[price] += quantity;
	order_pool.push_back(order);
	if (order.get_type() == "bid") {
		bids[price].push_back(--order_pool.end());
		id_order_ab[order.get_order_id()] = make_pair(--order_pool.end(), --bids[price].end());
	}
	else {
		asks[price].push_back(--order_pool.end());
		id_order_ab[order.get_order_id()] = make_pair(--order_pool.end(), --asks[price].end());
	}
}


void OrderBook::cancel_pool(Order order) {
	int id = order.get_order_id();
	if (id_order_ab.find(id) == id_order_ab.end()) {
		return;
	}
	auto iters = id_order_ab[id];
	Price4 price = order.get_price();
	if (order.get_type() == "bid") {
		bids[price].erase(iters.second);
	}
	else {
		asks[price].erase(iters.second);
	}
	order_pool.erase(iters.first);
}

