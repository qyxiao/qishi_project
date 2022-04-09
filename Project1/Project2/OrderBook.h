#pragma once
#include "Order.h"
#include <string>
#include <map>
#include "Price4.h"
#include <list>
#include <unordered_map>

typedef list<Order>::iterator loiter;

class OrderBook {
	string symbol;
	map<Price4, list<loiter>> asks;
	map<Price4, list<loiter>> bids;
	unordered_map<int, pair<loiter, list<loiter>::iterator>> id_order_ab;
	list<Order> order_pool;
	unordered_map<Price4, int> price_quantity;
public:
	OrderBook() = default;
	OrderBook(string symbol):symbol(symbol){}
	int get_quantity(Price4 price);
	vector<int> bid_price_quantity(Price4 price, int quantity); // should actually return vector<string>
	vector<int> ask_price_quantity(Price4 price, int quantity); // should actually return vector<string>
	void add_pool(Order order);
	void cancel_pool(Order order);
	Price4 top_ask() {
		if (asks.size() == 0) {
			return Price4::MaxVal;
		}
		return asks.begin()->first;
	}
	Price4 top_bid() {
		if (bids.size() == 0) {
			return Price4::MinVal;
		}
		return bids.begin()->first;
	}
};