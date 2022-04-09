#include "MatchEngine.h"
#include <string>
#include "Price4.h"

void MatchEngine::handle_order(Order order) {
	string symbol = order.get_symbol();
	if (order.get_type() == "Cancel") {
		handel_cancel(order);
	}else if (symbol_OrderBook.find(symbol) == symbol_OrderBook.end()) {
		symbol_OrderBook[symbol] = OrderBook(symbol);
		symbol_OrderBook[symbol].add_pool(order);
	}else {

	}
}

void MatchEngine::handel_cancel(Order order) {
	string symbol = order.get_symbol();
	if (symbol_OrderBook.find(symbol) == symbol_OrderBook.end()) {
		return;
	}
	symbol_OrderBook[symbol].cancel_pool(order);
}

void MatchEngine::handel_ask(Order order) {
	string symbol = order.get_symbol();
	if (symbol_OrderBook.find(symbol) == symbol_OrderBook.end()) {
		return;
	}
	OrderBook* OB = &symbol_OrderBook[symbol];
	Price4 price = order.get_price();
	while (order.get_quantity() > 0 && OB->top_bid() >= price) {
		int bid_quantity = OB->get_quantity(OB->top_bid());
		OB->bid_price_quantity(OB->top_bid(), min(bid_quantity, order.get_quantity()));  // need to keep transaction record in this step
		order.minus_quantity(bid_quantity);
	}
	if (order.get_quantity() > 0) {
		OB->add_pool(order);
	}
}


void MatchEngine::handel_bid(Order order) {
	string symbol = order.get_symbol();
	if (symbol_OrderBook.find(symbol) == symbol_OrderBook.end()) {
		return;
	}
	OrderBook* OB = &symbol_OrderBook[symbol];
	Price4 price = order.get_price();
	while (order.get_quantity() > 0 && OB->top_ask() <= price) {
		int ask_quantity = OB->get_quantity(OB->top_ask());
		OB->ask_price_quantity(OB->top_bid(), min(ask_quantity, order.get_quantity()));  // need to keep transaction record in this step
		order.minus_quantity(ask_quantity);
	}
	if (order.get_quantity() > 0) {
		OB->add_pool(order);
	}
}


void MatchEngine::to_publish(vector<string>& transactions) {
	publisher->deliver_msg(transactions);
}