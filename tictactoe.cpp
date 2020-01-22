#include <iostream>
#include "tictactoe.h"
#include <algorithm>
using namespace std;
#include <sstream>

/*
TicTacToe.cpp -> CPP file
Author -> Shubham Kashikar
Date -> 09/16/2019
Compiler -> Microsoft C++ Compiler
The file contains complete logic.Functions and methods are defined in this file
*/


int count(string a, char c)  // To count specific character in a string. Ex. counting the number of x in the imput string 
{
	int b = 0;
	for (int i = 0; i <= a.length(); i++)
	{
		if (a[i] == c)
		{
			b++;
		}
	}
	return b;
}

int random(string a)
{
	int count_e = count(a, 'e');
	//int arr[10] = {};
	int array[10] = {};
	int x = 0;

	for (int i = 0; i < a.length(); i++) {
		array[i] = (rand() % 10);
		if (a[array[i]] == 'e')
		{
			x = array[i];
		}
	}
	return x;
}

int validation_one(string a) {
	int count_x = count(a, 'x');  // Count of number of X in the given string
	int count_o = count(a, 'o');  // Count of number of O in the given string
	int count_e = count(a, 'e');  // Count of number of empty spaces in the given string
	int z = 0;
	// To check the count 
	int count = count_x + count_o + count_e;
		if (count == 9)
		{
			int count1 = count_x - count_o; // Check the difference in 'X' and 'O' 
			if ((count1 >= 2) || (count1 <= -2))
			{
				cout << "Impossible Position" << endl;
				z = 1; //Impossible Position
			}
		}
		else
		{
			cout << "Invalid Letter" << endl;
			z = 2; //Invalid Letter
		}
	return z;
}

string print(string a)
{	
	ostringstream s1;
	ostringstream s2;
	ostringstream s3;
	string x = "e";
	string y = " ";
	size_t pos;
	while ((pos = a.find(x)) != string::npos) {
		a.replace(pos, 1, y);
		cout << a;
	}

	//replace(a.begin(), a.end(), x, y);

	s1 << "\n" << "|" << a[0] << "|" << a[1] << "|" << a[2] << "|" << "\n";
	s2 << "|" << a[3] << "|" << a[4] << "|" << a[5] << "|" << "\n";
	s3 << "|" << a[6] << "|" << a[7] << "|" << a[8] << "|" << "\n";

	
	string d;
	string b;
	string c;

	d = s1.str();
	b = s2.str();
	c = s3.str();

	string abc = d + b + c;

	cout << abc;
	return abc;

}


int winner(string a)
{	
	int z = 0;
	if (((a[0] & a[1] & a[2]) == 'o') || ((a[3] & a[4] & a[5]) == 'o') || ((a[6] & a[7] & a[8]) == 'o'))
	{
		cout << "O is the winner";
		z = 1;
	}
	else if(((a[0] & a[3] & a[6]) == 'o') || ((a[1] & a[4] & a[7]) == 'o') || ((a[2] & a[5] & a[8]) == 'o'))
	{
		cout << "O is the winner";
		z = 1;
	}
	else if (((a[0] & a[4] & a[8]) == 'o') || ((a[2] & a[4] & a[6]) == 'o'))
	{
		cout << "O is the winner";
		z = 1;
	}
	else if (((a[0] & a[1] & a[2]) == 'x') || ((a[3] & a[4] & a[5]) == 'x') || ((a[6] & a[7] & a[8]) == 'x'))
	{
		cout << "X is the winner";
		z = 2;
	}
	else if (((a[0] & a[3] & a[6]) == 'x') || ((a[1] & a[4] & a[7]) == 'x') || ((a[2] & a[5] & a[8]) == 'x'))
	{
		cout << "X is the winner";
		z = 2;
	}
	else if (((a[0] & a[4] & a[8]) == 'x') || ((a[2] & a[4] & a[6]) == 'x'))
	{
		cout << "X is the winner";
		z = 2;
	}
	return z;
}

char next_turn(string a)
{
	char f;
	int count_x = count(a, 'x');  
	int count_o = count(a, 'o');
	int count_e = count(a, 'e');
	int count_x_o = count_x - count_o;
	if (count_e > 0)
	{
		if ((count_x_o == 1 || count_x_o == -1 || count_x_o == 0) & (count_o > 0))
		{
			cout << "Player X's turn" << endl;
			f = 'x';
		}
		else
		{
			cout << "Player O's turn" << endl;
			f = 'o';
		}
	}
	else
	{
		f = 't';
	}
	return f;
}


string TicTacToe::validation(string pos)
//string validation(string pos)
{
	
	//TicTacToe t;
	string output;
	ostringstream os1;
	os1 << "Input String :" << pos ;
	string input;
	input = os1.str();
	int len;
	int z = 0;
	len = pos.length();
	if (len < 9) 
	{
		output = input + " is not valid: Invalid Length!";
		cout << "Invalid Length";
	}
	else {
		z = 1;
		string c = print(pos);
		int v1 = validation_one(pos);
		if (v1 == 1)
		{
			output = input + " is not valid: Impossible Position!";
			//output = printone(t);
		}
		else if (v1 == 2)
		{
			output = input + " is not valid: Invalid Letter!";
		}
		else if (v1 == 0)
		{
			
			int w = winner(pos);
			if (w == 1)
			{
				output = input + c + "O is the winner";
			}
			else if (w == 2)
			{
				output = input + c +  "X is the winner";
			}
			else if (w == 0)
			{
				char y = next_turn(pos);
				int u = random(pos);
				if (y == 't')
				{
					output = input + c + "The Game is Tie!";
				}
				else if (y == 'o')
				{
					pos[u] = 'O';
					string d = print(pos);
					output = input + c + "Player O's turn" + d;
				}
				else
				{
					pos[u] = 'X';
					string d = print(pos);
					output = input + c + "Player X's turn" + d;
				}
			}
		}
	}
return output;
}