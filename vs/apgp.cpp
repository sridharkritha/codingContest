#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
Input:
4 7 10
2 6 18
0 0 0

Output:
AP 13
GP 54
*/
int main()
{
	int a,b,c;
	vector<string> series;
	vector<int> number;
	while(true)
	{
		cin>>a>>b>>c;
		if(!a&&!b&&!c)
		{
			for(int i = 0 ; i< number.size(); ++i)
			{
				cout<<series[i]<<number[i]<<endl;
			}
			break;
		}
		else
		{
			if(c-b == b-a)
			{
				series.push_back("AP ");
				number.push_back(c + (c-b));
				// cout<<"AP "<< c + (c-b);
			}
			else
			{
				series.push_back("GP ");
				number.push_back(c * (c / b));
				// cout<<"GP "<< c * (c / b);
			}
		}
	}

	return 0;
}