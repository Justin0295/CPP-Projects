#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <unordered_map>
using namespace std;

#include "commands.h"

unordered_map <string, bool> u;

void build_set (const string chunk)
{
	size_t found = chunk.find("$");
	string setbuild;
	bool setcheck;
	
	for (int j = found+1 ; j < chunk.length() ; j++)
	{
		if (chunk[j] != ' ')
			setbuild += chunk[j];
		else
			break;
	}
	
	size_t T_or_F = chunk.find("true");
	if (T_or_F != std::string::npos)
			setcheck = true;
	else
		setcheck = false;
	
	auto search = u.find(setbuild);
	if (search != u.end())
		search->second = setcheck;
	else
		u [setbuild] = setcheck;
	
}