#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "delve.h"
#include "link.h"

vector<Link> link_list;

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
		//possible link...checks for [[ link format...if not prints char and moves on
		if (s[i] == '[') 
		{
			if (s[i+1] == '[') //this is a link, has [[ format
			{
				string link_text; //builds string to pass to link builder
				i += 2; // skip the [[
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
		//possible command...checks for (xxx: xxxxx) format
		if (s[i] == '(')
		{
			string command_text; //builds string to pass to command builder
			if (s[i+3] == ':' || s[i+4] == ':' || s[i+5] == ':' || s[i+8] == ':') //this is a command
			{
				string pass_cmd_txt;
				if (s[i+5] == '$' || s[i+6] == '$' || s[i+7] == '$') //nearby $ should indicate a set command
				{
					for ( ; ; )
						{
							if (s[i] != ')')
							{
								pass_cmd_txt += s[i];
								i++;
							}
							else
							{
								pass_cmd_txt += s[i];
								cout << "***" << pass_cmd_txt << endl;
								i++;
								break;
							}
						}
				}
				i++;
			}
			else //not a command, somebody just used parens in their story
			{
				cout << s[i];
				i++;
			}
		}
		//if text is not part of a link set or header it will be disp
		if (end_of_header == true && s[i] != '<' && s[i] != '(') 
		{
			cout << s[i];
			i++;
		}
		//end of passage found
		if (s[i] == '<') 
			break;
	}
	
	//display list of options to player and return their choice
	for (int i = 0 ; i < link_list.size() ; i++)
		cout << "\t" <<  i+1 << "\t" << link_list[i].print() << endl;
	
	int player_choice;
	cout << endl << "You decide to: " ;
	cin >> player_choice;
	while (cin.fail() || player_choice > link_list.size() || player_choice <= 0)  //makes sure that user selects a valid option
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