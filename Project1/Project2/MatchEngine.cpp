#include "MatchEngine.h"
#include <string>
#include "Price4.h"

list<string> MatchEngine::handle_order(Order order) {
	string symbol = order.get_symbol();
	//list<string> result;
	if (order.get_type() == "Cancel") {
		return handel_cancel(order);
	}else if(order.get_side() == "Bid"){
		return handel_bid(order);
	}else {
		return handel_ask(order);
	}
}

list<string> MatchEngine::handel_cancel(Order& order) {
	string symbol = order.get_symbol();
	list<string> result;
	if (symbol_OrderBook.find(symbol) == symbol_OrderBook.end()) {
		return result;
	}
	symbol_OrderBook[symbol].cancel_pool(order);
	return result;
}

list<string> MatchEngine::handel_ask(Order& order) {
	string symbol = order.get_symbol();
	list<string> result;
	if (symbol_OrderBook.find(symbol) == symbol_OrderBook.end()) {
		symbol_OrderBook[symbol] = OrderBook(symbol, messenger);
		symbol_OrderBook[symbol].add_pool(order);
		return result;
	}
	OrderBook* OB = &symbol_OrderBook[symbol];
	Price4 price = order.get_price();
	while (order.get_quantity() > 0 && OB->top_bid() >= price) {
		int bid_quantity = min(OB->get_quantity(OB->top_bid()), order.get_quantity());
		list<string> msgs = OB->bid_price_quantity(OB->top_bid(), bid_quantity);  // need to keep transaction record in this step
		result.splice(result.end(), msgs);
		order.subtract_quantity(bid_quantity);
	}
	if (order.get_quantity() > 0) {
		OB->add_pool(order);
	}
	return result;
	//if (result.size() > 0) {
	//	to_publish(result);
	//}
}


list<string> MatchEngine::handel_bid(Order& order) {
	string symbol = order.get_symbol();
	list<string> result;
	if (symbol_OrderBook.find(symbol) == symbol_OrderBook.end()) {
		symbol_OrderBook[symbol] = OrderBook(symbol, messenger);
		symbol_OrderBook[symbol].add_pool(order);
		return result;
	}
	OrderBook* OB = &symbol_OrderBook[symbol];
	Price4 price = order.get_price();
	while (order.get_quantity() > 0 && OB->top_ask() <= price) {
		int ask_quantity = min(OB->get_quantity(OB->top_ask()), order.get_quantity());
		list<string> msgs = OB->ask_price_quantity(OB->top_bid(), min(ask_quantity, order.get_quantity()));  // need to keep transaction record in this step
		result.splice(result.end(), msgs);
		order.subtract_quantity(ask_quantity);
	}
	if (order.get_quantity() > 0) {
		OB->add_pool(order);
	}
	return result;
	//if (result.size() > 0) {
	//	to_publish(result);
	//}
}


//void MatchEngine::to_publish(list<string>& transactions) {
//	publisher->deliver_msg(transactions);
//}