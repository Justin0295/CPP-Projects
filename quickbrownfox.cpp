//prints each individual char of input stream 


#include <iostream>
#include <sstream>
using namespace std;

int main()
{
	istringstream iss("The quick brown fox");
	ostringstream oss;

	int i(0);
	char c = iss.get();
	while (iss)
	{
		oss << "Char " << ++i << ": " << c << endl;
		c = iss.get();
	}

	cout << oss.str() << endl;

    return 0;
}
