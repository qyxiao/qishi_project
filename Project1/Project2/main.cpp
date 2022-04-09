//#include "Price4.h"
#include <iostream>
#include <json.hpp>
#include "Publisher.h"

using json = nlohmann::json;

int main() {

	json j = {
  {"pi", 3.141},
  {"happy", true},
  {"name", "Niels"},
  {"nothing", nullptr},
  {"answer", {
	{"everything", 42}
  }},
  {"list", {1, 0, 2}},
  {"object", {
	{"currency", "USD"},
	{"value", 42.99}
  }}
	};

	std::cout << j.dump(4) << std::endl;
    
	return 0;
}