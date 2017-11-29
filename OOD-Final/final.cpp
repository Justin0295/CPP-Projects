#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "link.h"
#include "delve.h"

bool end_of_story = false;

void foo();


main ()
{
	ifstream pFile ("if.html");
	
	if (pFile.is_open())
	{
		cout << "\n\nOPENING FILE....\n" << endl;
		stringstream buf;
		buf << pFile.rdbuf();
		string story = buf.str();
		string pass_name = "start";
		
		//find first passage title
		size_t start_check_1 = story.find("=\"New Game");
		size_t start_check_2 = story.find("=\"Start");
		size_t start_check_3 = story.find("=\"start");
		size_t start_check_4 = story.find("=\"new game");
		if (start_check_1 != std::string::npos)
			pass_name = ("New Game");
		else if (start_check_2 != std::string::npos)
			pass_name = ("Start");
		else if (start_check_3 != std::string::npos)
			pass_name = ("start");
		else if (start_check_4 != std::string::npos)
			pass_name = ("new game");
		else
			cout << "Cannot determine start" << endl; //temp will need to replace with another way to find start
		
		//loop that runs story
		while (end_of_story != true)
		{
			pass_name = Delve (story, pass_name);
			//foo();
		}
	}
	
	else
		cout << "cannot find file";
	
	return 0;
}





//

void foo ()
{
	end_of_story =true;
}
