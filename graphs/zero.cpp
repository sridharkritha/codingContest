#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> isPath(string src, string dst)  // a1 - h8 
{
	vector<string> posList;
	string s = NULL;
	int c = src[0] - 'a';
	int r = src[1] - '1';
	

	for(int i = 0; i < 8; ++i)
	{
		if(r+1 < 8 && c-2 >=0)

		posList.push_back(s);
	}
	return posList;
}

int main()
{
	return 0;
}