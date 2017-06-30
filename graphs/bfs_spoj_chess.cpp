#include <iostream>
#include <queue>
#include <map>
#include <string>
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

#if 1

 // http://www.spoj.com/problems/NAKANJ/

vector<string> neigbhourNodes(string node)
{
	vector<string> v;
	string s;

	int x = 0, y = 0;
	char c;

	// Case 1: x = -1
	//		   y = -2 , 2
	x = node[0] - 'a' - 1;

	if(x > 0)
	{
		c = x + 'a';
		y = node[1] - '0' - 2;

		if(y > 0)
		{			
			s = c + NumberToString(y);
			v.push_back(s);
		}

		y = node[1] - '0' + 2;

		if(y < 9) // 1 to 8
		{
			s = c + NumberToString(y);
			v.push_back(s); 
		}
	}

	// Case 2: x = -2
	//		   y = -1 , 2
	x = node[0] - 'a' - 2;

	if(x > 0)
	{
		c = x + 'a';
		y = node[1] - '0' - 1;

		if(y > 0)
		{			
			s = c + NumberToString(y);
			v.push_back(s);
		}

		y = node[1] - '0' + 1;

		if(y < 9) // 1 to 8
		{
			s = c + NumberToString(y);
			v.push_back(s); 
		}
	}

	// Case 3: x =  1
	//		   y = -2 , 2
	x = node[0] - 'a' + 1;

	if(x < 8) // a to h
	{
		c = x + 'a';
		y = node[1] - '0' - 2;

		if(y > 0)
		{			
			s = c + NumberToString(y);
			v.push_back(s);
		}

		y = node[1] - '0' + 2;

		if(y < 9) // 1 to 8
		{
			s = c + NumberToString(y);
			v.push_back(s); 
		}
	}

	// Case 4: x =  2
	//		   y = -1 , 1
	x = node[0] - 'a' + 2;

	if(x < 8) // a to h
	{
		c = x + 'a';
		y = node[1] - '0' - 1;

		if(y > 0)
		{			
			s = c + NumberToString(y);
			v.push_back(s);
		}

		y = node[1] - '0' + 1;

		if(y < 9) // 1 to 8
		{
			s = c + NumberToString(y);
			v.push_back(s); 
		}
	}

	return v;		 
}

int bfs(string src, string dst)
{
	vector<string> v;
	map<string, unsigned int> m;
	queue<string> q;
	string p;

	q.push(src);
	m[src] = 0;

	while(!q.empty())
	{
		p = q.front();
		q.pop();
		v = neigbhourNodes(p); // Hint: g6 node

		for(int i = 0; i < v.size(); ++i)
		{
			if(m.find(v[i]) == m.end()) 
			{
				// Not exist in map
				m[v[i]] = m[p] + 1; // distance calculation
				q.push(v[i]);

				if(v[i] == dst)
				{
					break;
				}
			}
		}		
	}

	int t = m[dst];
	return t;
}

int main()
{
	// vector<string> v;	
	// v = neigbhourNodes("g6");	
	// bfs("a1", "h8"); // 6

	unsigned int  n = 0;
	string src, dst;
	cin>> n;
	for(unsigned int i = 0; i < n; ++i)
	{
		cin >> src >> dst;
		cout << bfs(src, dst) << endl;
	}
	
	return 0;
}


#elif 0

#endif
