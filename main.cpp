/*
main.cpp -> driver file
Author -> Shubham Kashikar
Date -> 09/16/2019
Compiler -> Microsoft C++ Compiler
The driver file which helps in executing the project
*/

#include <iostream>
#include "tictactoe.h"
#include <string>
#include <fstream>
using namespace std;

int main()
{	
	TicTacToe ttt;
	string pos;
	string abc;
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	while (!fin.eof())
	{
		getline(fin, pos);
		abc = ttt.validation(pos);
		ttt.validation(pos);
		fout  << abc << "\n"  << "____________________________" << endl;
		//operator << (cout, ttt.a);
		//fout << ttt;
	}
	fout.close();
	return 0;
}