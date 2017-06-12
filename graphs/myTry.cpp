

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

/*
// Brute Force Method
int main()
{
	unsigned int a =  999, b = 1, t;
	
	bool r = checkOneZeoForm(42);

	while(1)
	{
		if(checkOneZeoForm(a*b)) break;
		b++;
	}
	t = a * b;
	return 0;
}
*/

unsigned int nextNumber(unsigned int n)
{
	if(n % 10) return n * 10;
	else n + 1;

	
}

bool visited[10005];

int main()
{
	memset(visited, false, sizeof visited);
	unsigned int t = 0, m = 0;
	queue<int> q;
	q.push(1);
	t = q.front();
	visited[t] = true;
	while(!q.empty())
	{
		m = q.front();
		q.pop();
		// Find the next element

		
		if(!visited[m])
		{
			visited[m] = true;
			//q.push
			q.pop();
		}

	}


	return 0;
}



























////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <queue>
using namespace std;
/*
	1033
    1733     
    3733     
    3739     
    3779
    8779
    8179     
*/

bool prime[100005];
void sieve(int n = 100005)
{
	// Create a boolean array "prime[0..n]" and initialize
	// all entries it as true. A value in prime[i] will
	// finally be false if i is Not a prime, else true.

	memset(prime, true, sizeof(prime));
	prime[0] = false;
	prime[1] = false;

	for (int p=2; p*p<=n; p++)
	{
		// If prime[p] is not changed, then it is a prime
		if (prime[p] == true)
		{
			// Update all multiples of p
			for (int i=p*p; i<=n; i += p)
				prime[i] = false;
		}
	}
}

unsigned int nA[4] = {0};
unsigned int* numToAry(unsigned int n)
{
	// wrong : for(unsigned int i = 3; i >= 0; --i) => bcos of unsigned 
	// correct: for(unsigned i = n-1; i < n ; --i) => Iterates from n-1 to 0 [idiom]
	for(unsigned int i = 3; i < 4; --i)  
	{
		nA[i] = n % 10;
		n = n / 10;
	}
	return nA;
}

unsigned int aryToNum(unsigned int a[])
{
	unsigned int n = 0, p = 1;
	for(unsigned int i = 3; i < 4; --i) 
	{
		n += a[i] * p;
		p *= 10;
	}
	return n;
}

int main()
{
	unsigned int a, b, t;
	cin>> a >> b;

	bool visit[100005];
	int dist[100005];
	memset(visit,false,sizeof(visit));
	memset(dist, -1,sizeof(dist));

	queue<unsigned int> q;	
	visit[a] = true;
	dist[a] = 0;
	q.push(a);

	t = q.front();


	while(!q.empty())
	{
		t = q.front();
		q.pop();

		if(t == b) break;
		
		// Adjacent numbers
		unsigned int *nA = numToAry(t);
		for(int l = 3; l < 4; --l)
		{
			for(int d = 0; d < 10; ++d)
			{
				nA[l] = d;
				t = aryToNum(nA);
				if(prime[t] && !visit[t])
				{
					visit[t] = true;
					dist[t] += 1;
					q.push(t);
					cout<<prime[t];
				}

			}
		}
	}


	cout<<dist[b];

	return 0;
}



