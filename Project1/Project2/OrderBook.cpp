#include "OrderBook.h"
#include "Order.h"
int OrderBook::get_quantity(Price4 price) {
	if (price_quantity.find(price) != price_quantity.end()) {
		return price_quantity[price];
	}
	return 0;
}


vector<string> OrderBook::ask_price_quantity(Price4 price, int quantity) {
	vector<string> result;
	while (asks[price].size() > 0 && quantity > 0) {
		auto pq = asks[price].front();
		if ((*pq).get_quantity() <= quantity) {
			messenger->msg_generator(result, *pq);
			quantity -= (*pq).get_quantity();
			price_quantity[price] -= (*pq).get_quantity();
			order_pool.erase(pq);
			asks[price].pop_front();
			id_order_ab.erase((*pq).get_order_id());
		}
		else {
			int share_left = (*pq).get_quantity() - quantity;
			pq->set_quantity(quantity);
			messenger->msg_generator(result, *pq);
			quantity = 0;
			pq->set_quantity(share_left);
		}
	}
	if (asks[price].size() == 0) {
		asks.erase(price);
		price_quantity.erase(price);
	}
	return result;
}



vector<string> OrderBook::bid_price_quantity(Price4 price, int quantity) {
	vector<string> result;
	while (bids[price].size() > 0 && quantity > 0) {
		auto pq = bids[price].front();
		if ((*pq).get_quantity() <= quantity) {
			messenger->msg_generator(result, *pq);
			quantity -= (*pq).get_quantity();
			price_quantity[price] -= (*pq).get_quantity();
			order_pool.erase(pq);
			bids[price].pop_front();
			id_order_ab.erase((*pq).get_order_id());
		}
		else {
			int share_left = (*pq).get_quantity() - quantity;
			pq->set_quantity(quantity);
			messenger->msg_generator(result, *pq);
			quantity = 0;
			pq->set_quantity(share_left);
		}
	}
	if (bids[price].size() == 0) {
		bids.erase(price);
		price_quantity.erase(price);
	}
	return result;
}



void OrderBook::add_pool(Order& order) {
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




void OrderBook::cancel_pool(Order& order) {
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
	price_quantity[price] -= order.get_quantity();
	if (price_quantity[price] == order.get_quantity()) {
		price_quantity.erase(price);
	}
	else {
		price_quantity[price] -= order.get_quantity();
	}
	id_order_ab.erase(id);
}

