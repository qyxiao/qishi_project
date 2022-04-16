#include <iostream>
#include <json.hpp>
#include "Publisher.h"
#include <fstream>
#include "Loader.h"
#include "MatchEngine.h"
#include "Publisher.h"
#include "TransactionMsg.h"

using json = nlohmann::json;
using namespace std;

int main() {

	TransactionMsg tm = TransactionMsg();
	Publisher pb = Publisher("out_msg.json", &tm);
	MatchEngine engine1 = MatchEngine(&pb);
	MatchEngine engine2 = MatchEngine(&pb);
	Loader loda = Loader({&engine1, &engine2});
	loda.process_orders("in_msg.json");

	return 0;
}