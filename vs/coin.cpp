#include <iostream>
#include <vector>
using namespace std;
/*
Input:
12
2

Output:
13
2
*/
int main()
{
	long long n;
	long long total;
	vector<long long> output;

	// while(scanf("%d",&n)==1)
	while(cin>>n)
	{
		total = n/2 + n/3 + n/4;

		if(n > total)
		{
			output.push_back(n);
		}
		else
		{
			output.push_back(total);
		}
	}

	for(long long i = 0; i < output.size(); ++i)
	{
		cout<<output[i]<<endl;
	}

	return 0;
}