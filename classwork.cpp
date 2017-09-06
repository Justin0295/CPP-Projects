#include <iostream>
#include <fsteam>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

typedef struct
{
	string lname;
	string fname;
	int grade;
} grade_t;

int main()
{
	ifstream in (grades.txt);
	string line;
	int numstudents;
	vector<grade_t vec;
	in >> numstudents;
	getline (in, line);
	
	for (int i = 0; i < numstudents; i++)
	{
		getline(in, line);
		iss.str(line);
		grade_t x;
		iss >> x.fname >> x.lname >> x.grade;
		
		
	}
	
	return 0;
}