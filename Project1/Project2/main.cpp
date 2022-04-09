#include <iostream>
#include <json.hpp>
#include "Publisher.h"
#include <fstream>
#include "Loader.h"
#include "MatchEngine.h"
#include "Publisher.h"

using json = nlohmann::json;
using namespace std;

int main() {

	Publisher pb = Publisher("pretty.json");
	vector<string> msg = { "1", "2", "3", "4", "5" };
	pb.deliver_msg(msg);

	//json j = {
 // {"pi", 3.141},
 // {"happy", true},
 // {"name", "Niels"},
 // {"nothing", nullptr},
 // {"answer", {
	//{"everything", 42}
 // }},
 // {"list", {1, 0, 2}},
 // {"object", {
	//{"currency", "USD"},
	//{"value", 42.99}
 // }}
	//};

	//ofstream outs("pretty.json");

	//outs << j << std::endl;

	//ofstream outs2("pretty.json", fstream::app);
	//outs2 << j << std::endl;
    
	return 0;
}