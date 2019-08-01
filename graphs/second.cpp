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

vector<string> neigbhourNodes(string node)
{
	vector<string> v;
	string s;

	int x = 0, y = 0;
	char c;

	// Case 1:
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

		if(y < 7)
		{
			s = c + NumberToString(y);
			v.push_back(s); 
		}
	}

	// Case 2:
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

		if(y < 7)
		{
			s = c + NumberToString(y);
			v.push_back(s); 
		}
	}

	// Case 3:
	x = node[0] - 'a' + 1;

	if(x < 8)
	{
		c = x + 'a';
		y = node[1] - '0' - 2;

		if(y > 0)
		{			
			s = c + NumberToString(y);
			v.push_back(s);
		}

		y = node[1] - '0' + 2;

		if(y < 7)
		{
			s = c + NumberToString(y);
			v.push_back(s); 
		}
	}

	// Case 4:
	x = node[0] - 'a' + 2;

	if(x < 8)
	{
		c = x + 'a';
		y = node[1] - '0' - 1;

		if(y > 0)
		{			
			s = c + NumberToString(y);
			v.push_back(s);
		}

		y = node[1] - '0' + 1;

		if(y < 7)
		{
			s = c + NumberToString(y);
			v.push_back(s); 
		}
	}

	return v;		 
}

void bfs(string src, string dst)
{
	vector<string> v;
	map<string, bool> m;
	queue<pair<string,bool>> q;
	pair<string,bool> p;

	q.push(make_pair(src, true));

	while(!q.empty())
	{
		p = q.front();
		q.pop();
		v = neigbhourNodes(p.first);
		for(int i = 0; i < v.size(); ++i)
		{
			if(m.find(v[i]) == m.end()) 
			{
				// Not exist in map
				m[v[i]] = false; // not visited
				q.push(make_pair(v[i], false));
			}
		}		
	}
}

int main()
{
	vector<string> v;
	v = neigbhourNodes("h1");
	string src, dst;
	bfs(src, dst);
	cout<<"sridhar";
	return 0;
}


#elif 0



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

#elif 0

unsigned int mod(string sn, unsigned int m)
{
	unsigned int remainder = 0;
	for(int i = 0; i < sn.length(); ++i)
	{
		remainder = (remainder * 10 + sn[i] - '0') % m;
	}
	return remainder;
}

int main()
{
	map<string, bool> visited;	
	unsigned long long a =  999; // 17; //   	
	queue<string> q;
	string t,m;
	q.push("1");
	t = q.front();
	visited[t] = false;
	
	while(!q.empty())
	{
		m = q.front();
		q.pop();

		if(mod(m,a) == 0)
		{
			cout<< m;
			break;
		}

		// Find the next elements and push		
		if(!visited[m])
		{			
			visited[m] = true;
			q.push(m + "0");
			q.push(m + "1");
			visited[m + "0"] = false;
			visited[m + "1"] = false;
		}
	}
	return 0;
}

#elif 0

	#include <cstdio>
	using namespace std;

	const int MAX = 20002;

	struct pred { int p; char c; } pre[MAX];
	bool flag[MAX];
	int n, Q[MAX];

	inline int mod(int b, int m) {
		if(b < m) return b;
		return b % m;
	}

	void bfs(int s) {
		int qh, qt, p[2], i, u;
		qh = qt = 0;
		Q[qt++] = s;
		flag[s] = 1;
		pre[s].p = -1;
		pre[s].c = '1';
		while(qh < qt) {
			u = Q[qh++];
			p[0] = mod((u * mod(10, n)), n);
			p[1] = mod(p[0]+1, n);
			for(i=0; i<2; i++) {
				if(!flag[p[i]]) {
					pre[p[i]].p = u;
					pre[p[i]].c = '0'+i;
					if(!p[i]) 
						return;
					flag[p[i]] = 1;
					Q[qt++] = p[i];
				}
			}
		}
	}

	void print_path(int u) {
		if(u==-1) return;
		print_path(pre[u].p);
		putchar(pre[u].c);
	}

	int main() {
		int t, i;
		scanf("%d", &t);
		while(t--) {
			scanf("%d", &n);		
			if(n==1) {
				puts("1");
				continue;
			}
			for(i=0; i<n; i++) flag[i] = 0;
			bfs(1);
			print_path(0);
			putchar('\n');
		}
		return 0;
	}

#endif
