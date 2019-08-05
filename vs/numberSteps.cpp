#include <iostream>
#include <string>
#include <vector>
#include <sstream> // integer to string
using namespace std;
/*
Input:
3
4 2
6 6
3 4

Output:
6
12
No Number
*/

string IntToString(unsigned int a)
{
    ostringstream temp;
    temp << a;
    return temp.str();
}

int main()
{
	unsigned int tc, x, y, t;
	vector<string> output;
	cin >> tc;
	for(unsigned int i = 0; i < tc; ++i)
	{
		cin >> x >> y;
		if((x-y > 2)||(x == 1 && y == 0))
		{
			output.push_back("No Number");
		}
		else
		{
			if((x == 0 && y == 0) ||(x == 2 && y == 0)) //special case
			{
				output.push_back(IntToString(x)); // C++ 11 - to_string(t)
			}
			else if( !(x%2) && !(y%2)) // both even - Note bracket is important when you use ! and %
			{
				t = x + y;
				output.push_back(IntToString(t)); // C++ 11 - to_string(t)
			}
			else if( x%2 && y%2) // both odd
			{
				t = x + y - 1;
				output.push_back(IntToString(t));
			}
			else
			{
				output.push_back("No Number");
			}
		}
	}

	for(unsigned int i = 0; i < tc; ++i)
	{
		cout<<output[i]<<endl;
	}
	
	return 0;
}