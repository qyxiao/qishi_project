#pragma once
#include "Order.h"
#include "OrderBook.h"
#include <unordered_map>
#include "Publisher.h"
#include <list>

class MatchEngine {
	unordered_map<string, OrderBook> symbol_OrderBook;
	Publisher* publisher;
	list<string> handel_bid(Order& order);
	list<string> handel_ask(Order& order);
	list<string> handel_cancel(Order& order);
	TransactionMsg* messenger;
public:
	MatchEngine(Publisher* publisher) :publisher(publisher) { messenger = publisher->get_messenger(); }
	list<string> handle_order(Order order);
	//void to_publish(list<string>& transactions);
	Publisher* get_publisher() { return publisher; }
};