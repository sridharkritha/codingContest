#include <iostream>
#include <queue>
#include <sstream>
using namespace std;

// Integer to String
template <typename T>
 std::string NumberToString ( T Number )
 {
     std::ostringstream ss;
     ss << Number;
     return ss.str();
 }

bool checkOneZeoForm(unsigned int n)
{
	std::string s = NumberToString (n);
	for(unsigned int i = 0; i < s.length(); ++i)
	{
		if(s[i] != '0' && s[i] != '1') return false;
	}
	return true;
}

unsigned int nextNumber(unsigned int n)
{
	if(n % 10) return n * 10;
	else n + 1;
}

#if 0
// Brute Force Method
int main()
{
	unsigned int a =  17; //999;
	unsigned int b = 1, t;
	
	bool r = checkOneZeoForm(42);

	while(1)
	{
		if(checkOneZeoForm(a*b)) break;
		b++;
	}
	t = a * b; // 999 => 100101111
	           // 17 =>  11101
	return 0;
}

#else

bool visited[1000000000];

int main()
{
	memset(visited, false, sizeof visited);
	unsigned int t = 0, m = 0;
	unsigned int a = 999; // 17; //
	queue<int> q;
	q.push(1);
	t = q.front();
	visited[t] = false;
	while(!q.empty())
	{
		m = q.front();
		q.pop();

		if(m % a == 0)
		{
			cout<< m;
			break;
		}

		// Find the next elements and push		
		if(!visited[m])
		{			
			visited[m] = true;
			q.push(m*10);
			q.push(m*10 + 1);			
		}

	}
	return 0;
}

#endif
