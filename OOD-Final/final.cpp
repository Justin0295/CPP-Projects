#include <fstream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <cctype>
#include <string>
#include <vector>

using namespace std;

main()
{
	ifstream story("if.html");
	
	if (story.is_open())
	{
		cout << "it's doing the thing!";
	}
	else
	{
		cout << "cannot find file";
	}
	
	
	
	return 0;
}