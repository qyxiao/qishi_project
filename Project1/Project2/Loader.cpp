#include "Loader.h"
#include "Order.h"

void Loader::deliver_order(Order order) {

}

void Loader::process_orders(string filepath) {
	std::ifstream ins(filepath);
	json j;
	string line;
	//for(int i=0; i<2; i++) {
	//	ins >> j;
	//	/*cout << j;*/
	//	//long tau, string ty, int oi, string sym, string sd, int quan, Price4 lm
	//	Order od = Order(j["Time"], j["Type"], j["OrderId"], j["Symbol"], j["Side"], j["Quantity"], Price4(j["Price"]));
	//	od.print_content();
	//	//engines[0]->handle_order(Order(j["Time"], j["Type"], j["OrderId"], j["Symbol"], j["Side"], j["Quantity"], Price4(j["Price"])));
	//	//cout << j["Time"];
	//}
	while (std::getline(ins, line)) {
		j = json::parse(line);
		Order od = Order(j["Time"], j["Type"], j["OrderId"], j["Symbol"], j["Side"], j["Quantity"], Price4(j["Price"]));
		od.print_content();
		engines[0]->handle_order(od);
	}
}

void Loader::read_json(string filepath) {
	

}