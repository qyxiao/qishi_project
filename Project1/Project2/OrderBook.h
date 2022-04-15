#pragma once
#include "Order.h"
#include <string>
#include <map>
#include "Price4.h"
#include <list>
#include <unordered_map>
#include "TransactionMsg.h"

typedef list<Order>::iterator loiter;

class OrderBook {
	string symbol;
	map<Price4, list<loiter>> asks;
	map<Price4, list<loiter>, greater<Price4>> bids;
	unordered_map<int, pair<loiter, list<loiter>::iterator>> id_order_ab;
	list<Order> order_pool;
	unordered_map<Price4, int> price_quantity;
	TransactionMsg* messenger;

public:
	OrderBook() = default;
	OrderBook(string symbol, TransactionMsg* messenger):symbol(symbol), messenger(messenger){}
	int get_quantity(Price4 price);
	list<string> bid_price_quantity(Price4 price, int quantity); 
	list<string> ask_price_quantity(Price4 price, int quantity); 
	void add_pool(Order& order);
	void cancel_pool(Order& order);
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