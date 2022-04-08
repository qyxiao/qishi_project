#pragma once
#include "Price4.h"
#include <string>
class Order {
	long time;
	string type;
	int order_id;
	string symbol;
	string side;
	int quantity;
	Price4 limit_price;
	Order(long tau, string ty, int oi, string sym, string sd, int quan, Price4 lm):time(tau), type(ty), order_id(oi), symbol(sym), side(sd), quantity(quan), limit_price(lm){}
};