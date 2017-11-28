#include <string>
#include <sstream>
#include <iostream>
#include <fstream>

using namespace std;
void delve(string s);

main()
{
	ifstream pFile("if.html");
	stringstream buf;
	
	//these will eventually be part of the Interpreter class but for now they are here
	string pass_name;
	string pass_text;
	
	//delimiters
	string pass_start = "<tw-passagedata";
	string pass_end = "</tw-passagedata>";
	string link_start = "[[";
	string link_end = "]]";
	string pass_name_is = "name=\"";
	
	if (pFile.is_open())
	{
		cout << "\n\nOpening file....\n\n";
		
		//convert pFile to string---idk if will need this 
		buf << pFile.rdbuf();
		string story = buf.str();
		
		//display the first passage
		
		//passage name - - gets the passage name
		pass_name = "start"; //for testing to be removed
		unsigned beg_pos_name= story.find("name=\"");
		cout << story.substr (beg_pos_name+6, pass_name.length()) << endl;
		
		//display passage - - finds passage of x name and builds substring...will pass this to a function to get links etc
		pass_name = "start"; //for testing to be removed
		unsigned beg_pos_pass = story.find("name=\"" +pass_name + "\"");  //sets pos of passage with name="x"
		string s = story.substr(beg_pos_pass, 2000);
		unsigned end_pos_twtag = s.find(">");  //sets pos of the end of the <tw> tag for selected passage
		unsigned end_of_pass = s.find("</tw");  //sets pos of the end of the passage
		
		//cout << s.substr (end_pos_twtag+1, end_of_pass - end_pos_twtag-1) <<endl; //for testing to be removed
		delve ( s.substr (end_pos_twtag+1, end_of_pass - end_pos_twtag-1));
		
		//cout << story;   //for testing to be removed
		
		cout << "\n";
	}
	else
	{
		cout << "cannot find file";
	}
	
	
	
	return 0;
}

//delve is the function that will pick out all the variables and links
void delve(string s)
{
	
	cout << s;
}
