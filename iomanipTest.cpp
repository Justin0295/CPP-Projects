#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

int main()
{
	//prompts user for number of shares and price until an invalid input is entered

	double numshares, price, total(0);

	cout << "Enter the number of shares and price per share. Enter Q to quit: ";
	cin >> numshares >> price;

	while (!cin.fail())
	{
	total += numshares * price;
	cout << "Enter the number of shares and price per share: ";
	cin >> numshares >> price;
	}

	cout << '$' << fixed << setprecision(2) << total << endl;

	system("PAUSE");

	return 0;
}
