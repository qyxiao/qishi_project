#pragma once
#include "Price4.h"
#include <string>
#include <iostream>

class Order {
	long time;
	string type;
	int order_id;
	string symbol;
	string side;
	int quantity;
	Price4 limit_price;
public:
	Order(long tau, string ty, int oi, string sym, string sd, int quan, Price4 lm):time(tau), type(ty), order_id(oi), symbol(sym), side(sd), quantity(quan), limit_price(lm){}
	int get_order_id() {
		return order_id;
	}

	int get_quantity() {
		return quantity;
	}

	Price4 get_price() {
		return limit_price;
	}

	string get_type() {
		return type;
	}

	string get_symbol() {
		return symbol;
	}

	string get_side() {
		return side;
	}

	void set_quantity(int quant) {
		quantity = quant;
	}

	void subtract_quantity(int quant) {
		quantity -= quant;
	}

	void print_content() {
		cout << time << ", " << type << ", " << order_id << ", " << symbol << ", " << side << ", " << quantity << "," <<limit_price.to_str() <<endl;
	}


};