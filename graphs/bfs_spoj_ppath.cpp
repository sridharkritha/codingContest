#include <iostream>
#include <queue>
#include <cstring> // memset
using namespace std;
// BFS
// http://www.spoj.com/problems/PPATH/

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
	sieve();

	bool visit[100005];
	int dist[100005];
	unsigned int a, b, t, m, tc;
	cin >> tc;
	for(int g = 0; g < tc; ++tc)
	{
		cin>> a >> b;		
		memset(visit,false,sizeof(visit));
		memset(dist, -1,sizeof(dist));

		queue<unsigned int> q;	
		visit[a] = true;
		dist[a] = 0;
		q.push(a);

		while(!q.empty())
		{
			t = q.front();
			q.pop();

			if(t == b) break;
		
			// Adjacent numbers		
			for(unsigned int l = 3; l < 4; --l)
			{
				unsigned int *nA = numToAry(t);
				for(int d = 0; d < 10; ++d)
				{
					nA[l] = d;
					m = aryToNum(nA);
					if(prime[m] && !visit[m] && m > 999)
					{
						visit[m] = true;
						dist[m] = dist[t] + 1;
						q.push(m);					
					}
				}
			}
		}

		if(dist[b] == -1)
			cout<<"Impossible"<<endl;
		else 
		    cout<<dist[b]<<endl;
	}

	return 0;
}



