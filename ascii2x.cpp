#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main()
{
	ifstream front("left.txt");
	ifstream back("right.txt");
	if (front.is_open() && back.is_open())
	{
	std:string leftH, leftW, rightH, rightW;
		string sLine;

		//tokenizes the height/width from input txt
		front >> leftH >> leftW;
		back >> rightH >> rightW;

		//converts left/right height/width strings to int
		int LH = std::stoi(leftH);
		int LW = std::stoi(leftW);
		int RH = std::stoi(rightH);
		int RW = std::stoi(rightW);

		//if the right image is larger than the left image increase
		//left image height so formatting is preserved
		while (RH > LH)
			LH++;
		
		for (int i = 0; i < LH; i++)
		{
			getline(front, sLine);
			cout << sLine;
			if (sLine.length() < LW)
				for (int j = sLine.length(); j < LW; j++)
					cout << " ";
			getline(back, sLine);
			cout << sLine;
			cout << "\n";
		}
	}
	else
		cout << "Unable to open a neccessary file\n\n";

	return 0;
}
