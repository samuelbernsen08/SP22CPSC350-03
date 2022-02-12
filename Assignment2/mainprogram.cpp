#include "parser.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

int main()
{

	Parser object; // create object of parser type

	object.num_pairs();

	object.check_non_alpha();

	object.check_alpha();

	object.average();

	object.output();


	return 0;
}
