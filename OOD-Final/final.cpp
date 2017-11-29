#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "link.h"

bool end_of_story = false;

void foo();
string Delve(const string s, const string title);
void LinkBuilder(const string link);
vector<Link> link_list;

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

//goes through selected passage picking out display text links sets etc
string Delve (const string s, const string title)
{
	size_t find_passage = s.find("\""+title+"\""); //finds the pos of the segment in HTML file
	bool end_of_header = false;
	
	for (int i = find_passage; i < s.length() ; )
	{
		//ignores header information per assignment instructions
		if (end_of_header == false && s[i] != '>') 
			i++;
		//indicates that the end of the header tag has been found and rest of text is fair game until '<'
		if (end_of_header == false && s[i] == '>') 
		{
			end_of_header = true;
			i++;
		}
		
		//+++++LINK?+++++
		
		//possible link...checks for [[ link format...if not prints char and moves on
		if (s[i] == '[') 
		{
			if (s[i+1] == '[') //this is a link, has [[ format
			{
				string link_text; //builds string to pass to link builder
				i += 2; // skip the [[
				cout << "LINK FOUND" << endl; // TESTING
				for( ; ; )
				{
					if (s[i] != ']') 
					{
						link_text += s[i];
						i++;
					}
					else 
					{
						LinkBuilder (link_text);
						i += 2; // skip the ]]
						break; //link done building
					}
				}
			}
			else //this isn't a link, somebody just used brackets in their story
			{
				cout << s[i];
				i++;
			}
		}
		
		//+++++COMMAND?+++++
		
		//possible command...checks for (xxx: xxxxx) format
		if (s[i] == '(')
		{
			string command_text; //builds string to pass to command builder
			if (s[i+3] == ':' || s[i+4] == ':' || s[i+5] == ':' || s[i+8] == ':') //this is a command
			{
				cout << "COMMAND FOUND" << endl; //testing
				i++;
			}
			else //not a command, somebody just used parens in their story
			{
				cout << s[i] << "SOMETHING WRONG" << endl; //testing
				i++;
			}
		}
		
		//+++++DISP+++++
		
		//if text is not part of a link set or header it will be disp
		if (end_of_header == true && s[i] != '<' && s[i] != '(') 
		{
			cout << s[i];
			i++;
		}
		
		//+++++END+++++
		
		//end of passage found
		if (s[i] == '<') 
			break;
	}
	
	//display list of options to player and return their choice
	for (int i = 0 ; i < link_list.size() ; i++)
		cout << i+1 << "\t" << link_list[i].print() << endl;
	
	int player_choice;
	cout << endl << "You decide to: " ;
	cin >> player_choice;
	while (cin.fail() || player_choice > link_list.size())  //makes sure that user selects a valid option
	{
		cout << "Please choose an option above: ";
		cin.clear();
		cin.ignore(256,'\n');
		cin >> player_choice;
	}
	string next_link = link_list[player_choice-1].go(); 
	link_list.clear();
	return next_link;
}

//builds links sent to it from Delve
void LinkBuilder (const string link)
{
	size_t check_gt = link.find("&gt");
	if (check_gt != std::string::npos)
	{
		size_t gt_loc = link.find("&gt");
		string gt_disp;
		string gt_go;
		for (int j = 0 ; j < gt_loc-1; j++)
			gt_disp += link[j];
		for (int k = gt_loc+4; k < link.length() ; k++)
			gt_go += link[k];
		link_list.push_back(Link(gt_disp, gt_go));
	}
	else
		link_list.push_back(Link(link, link));
}


void foo ()
{
	end_of_story =true;
}
