#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main()
{
	string input;
	string stop = "!stop";

	do
	{
		cout << "Enter (" << stop << " to quit): ";
		getline(cin, input);
		cout << "==>" << input << endl;	
		std::regex_match();
		std::regex_search(); //no workie
	}while(input!=stop);

	cout << "Bye." << endl;
	return 0;
}
