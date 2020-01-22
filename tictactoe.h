/*
TicTacToe.h -> Header file
Author -> Shubham Kashikar
Date -> 09/16/2019
Compiler -> Microsoft C++ Compiler
The file is used to Class define and members of the class.
*/

#include <iostream>
#include <string>
using namespace std;

class TicTacToe
{
public:
	string validation(string a);
};

/*
class TicTacToe
{
public:
	string validation(string a);
	
public:
	TicTacToe(string d) {
		validation(d);
	}
  friend void operator << (ostream& out,TicTacToe &tt);
	
};
*/
/*
void operator << (ostream& out, TicTacToe& tt)
{
	out << tt.validation(d);
}
*/

