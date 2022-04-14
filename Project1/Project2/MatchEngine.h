#pragma once
#include "Order.h"
#include "OrderBook.h"
#include <unordered_map>
#include "Publisher.h"

class MatchEngine {
	unordered_map<string, OrderBook> symbol_OrderBook;
	Publisher* publisher;
	void handel_bid(Order& order);
	void handel_ask(Order& order);
	void handel_cancel(Order& order);
public:
	MatchEngine(Publisher* publisher):publisher(publisher){}
	void handle_order(Order& order);
	void to_publish(vector<string>& transactions);

};