#include <string>
#include <sstream>
#include <iostream>
#include <fstream>

using namespace std;

bool end_of_story = 0;

void foo();
string delve(const string s, const string title);

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
		while (end_of_story != 1)
		{
			delve (story, pass_name);
			foo();
		}
	}
	
	else
	{
		cout << "cannot find file";
	}
	
	return 0;
}

//goes through selected passage picking out display text links sets etc
string delve (const string s, const string title)
{
	size_t find_passage = s.find("\""+title+"\""); //finds the pos of the segment in HTML file
	
	bool end_of_header = false;
	
	for (int i = find_passage; i < s.length() ; )
	{
		if (end_of_header == false && s[i] != '>') //ignores header information per assignment instructions
			i++;
		if (end_of_header == false && s[i] == '>') //ignores header information per assignment instructions
		{
			end_of_header = true;
			i++;
		}
		if (s[i] == '[') //possible link...checks if [[ format...if not prints char and moves on
		{
			if (s[i+1] == '[')
			{
				cout << "LINK FOUND" << endl;
			}
			else
			{
				cout << s[i];
				i++;
			}
		}
		if (end_of_header == true && s[i] != '<') //if text is not part of a link set or header it will be disp
		{
			cout << s[i];
			i++;
		}
		if (s[i] == '<') //ends when reaches the end of the passage
			break;
		
	}
	
	return "foo";
}
void foo ()
{
	end_of_story =1;
}
