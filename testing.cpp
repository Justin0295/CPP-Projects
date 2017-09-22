#include <iostream>
using namespace std;

int main()
{
	const int LEN = 80;
	char line[LEN];

	cout << "Enter a sentence of no more than " << LEN-1 << " characters:\n";
	cin.getline(line, LEN);
	cout << "The sentence you entered is:\n";

	for (int i = 0; line[i] != '\0'; i++)
	{
		cout << line[i];
	}
	
	return 0;
}
