#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
1x1 = 8x8
2x2 = 7x7
3x3 = 6x6
4x4 = 5x5
5x5 = 4x4
6x6 = 3x3
7x7 = 2x2
8x8 = 1x1
*/
int main()
{
	unsigned int a, total;
	vector<unsigned int> output;

	while(true)
	{
		cin>>a;

		if(a)
		{
			total = 0;
			for(unsigned int i = a; i != 0; --i)
			{
				total += i * i;
			}
		
			output.push_back(total);
		}
		else
		{
			for(unsigned int i = 0; i < output.size(); ++i)
			{
				cout<<output[i]<<endl;
			}
			break;
		}
	}
	return 0;
}