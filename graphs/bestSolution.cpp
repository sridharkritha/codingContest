#include <iostream>
#include <queue>
using namespace std;

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

int conv_to_num(int a[])
{
	int n;
	n = (a[3] *1000) + (a[2] *100) + (a[1] * 10) + (a[0]);
	return n;
}

void conv_to_arr(int digit[],int n)
{
	digit[0] = n%10;
	n /= 10;
	digit[1] = n%10;
	n /= 10;
	digit[2] = n%10;
	n /= 10;
	digit[3] = n%10;
}

bool visit[100005];
int dist[100005];

int main()
{
	int t;
	sieve();
	scanf("%d",&t);
	while(t--)
	{
		queue<int> q;
		int num1, num2, i, digit[4];
		scanf("%d%d",&num1,&num2);

		memset(visit,false,sizeof(visit));
		memset(dist,-1,sizeof(dist));

		if(num1 == num2)
		{
			printf("0\n");
			continue;
		}

		q.push(num1);
		dist[num1] = 0;
		visit[num1] = true;

		while(!q.empty())
		{
			int val = q.front();

			if(val == num2) break;

			for(i= 0; i<4; i++)
			{
				conv_to_arr(digit,val);
				for(int j= 0; j<10; j++)
				{
					digit[i] = j;
					int temp = conv_to_num(digit);

					if(!visit[temp] && prime[temp] && temp >= 1000)
					{
						visit[temp] = true;
						q.push(temp);
						dist[temp] = dist[val] + 1;
					}
				}

			}
			q.pop();
		}

		if(dist[num2]==-1) printf("-1\n");
		else printf("%d\n",dist[num2]);
	}
	return 0;
}