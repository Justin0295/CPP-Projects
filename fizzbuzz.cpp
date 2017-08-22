/*
	FIZZBUZZ
	
	For numbers 1 - 100 if number is a mult of 3 prints FIZZ
	if number is a mult of 5 prints BUZZ if number is a mult 
	of 15 prints FIZZBUZZ
	
*/

#include <iostream>
using namespace std;

int main()
{
	for (int i = 1; i <=100; i++)
	{
		if (i%15 == 0)
			cout << "fizzbuzz\n";
		else if (i%3 == 0)
			cout << "fizz\n";
		else if (i%5==0)
			cout << "buzz\n";
		else 
			cout << i << endl;
	}
	
	return 0;
}
