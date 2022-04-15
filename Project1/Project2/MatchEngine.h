#pragma once
#include "Order.h"
#include "OrderBook.h"
#include <unordered_map>
#include "Publisher.h"
#include <list>

class MatchEngine {
	unordered_map<string, OrderBook> symbol_OrderBook;
	Publisher* publisher;
	void handel_bid(Order& order);
	void handel_ask(Order& order);
	void handel_cancel(Order& order);
	TransactionMsg* messenger;
public:
	MatchEngine(Publisher* publisher) :publisher(publisher) { messenger = publisher->get_messenger(); }
	void handle_order(Order& order);
	void to_publish(list<string>& transactions);

};