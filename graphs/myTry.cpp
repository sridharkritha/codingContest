
#include <iostream>
#include <queue>
#include <map>
#include <sstream>
#include <list>
using namespace std;

#if 0

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

inline int mod(int b, int m) {
	if(b < m) return b;
	return b % m;
}

int main()
{
	map<unsigned long long, bool> visited;
	// bool visited[1000000000];
	// memset(visited, false, sizeof visited);
	unsigned long long t = 0, m = 0;
	// 999 => 111111111111111111111111111
	//  20 => 100
	//   3 => 111
	//  17 => 11101
	unsigned long long a =  20;// 999; // 17; //  
	queue<unsigned long long> q;
	q.push(1);
	t = q.front();
	visited[t] = false;

	unsigned long long f = 0;
	unsigned long long s = 0;
	
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
			/*
			f = mod((m * mod(10, a)), a);
			s = mod(f+1, a);
			q.push(f);
			q.push(s);
			visited[f] = false;
			visited[s] = false;
			*/
			 
			 m %= a; 
			 q.push(m*10);
			 q.push(m*10 + 1);
			 visited[m*10] = false;
			 visited[m*10 + 1] = false;
		}
	}
	return 0;
}

#endif

#elif 0

// src: https://github.com/sridharkritha/SPOJ/blob/master/ONEZERO.cpp

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
	t = 1;
	while(t--) {
		//scanf("%d", &n);
		n = 17; // 3;// 999;
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

#elif 0
#include<stack>

typedef long long int LLD;
typedef unsigned long long int LLU;

using namespace std;

queue< pair<LLD, int> > q;
pair<LLD, int> p;

LLD bfs(int n){
	bool visited[20000];
	fill(visited, visited + n, false);
	LLD res;
	q.push(make_pair(1, 1));
	
	while(!q.empty()){
		p = q.front();
		q.pop();
		visited[p.second] = true;
		if((p.second % n) == 0){
			res = p.first;
			break;
		}
		else{
			LLD tmp1 = p.first;
			tmp1 <<= 1;
			int modulo = (p.second * 10) % n;
			if(!visited[modulo])
				q.push(make_pair(tmp1, modulo));
			LLD tmp2 = p.first;
			tmp2 <<= 1;
			tmp2 |= 1;
			modulo = (p.second * 10 + 1) % n;
			if(!visited[modulo])
				q.push(make_pair(tmp2, modulo));
		}
	}
	
	while(!q.empty())
		q.pop();
	
	return res;
}

void display(LLD n){
	stack<int> s;
	while(n){
		s.push(n % 2);
		n >>= 1;
	}
	while(!s.empty()){
		cout << s.top();
		s.pop();
	}
	cout << endl;
}

int main(){
	int t, n;	
    scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		LLD result = bfs(n);
		display(result);
	}
	return 0;
}

#elif 0

inline int mod(int b, int m) {
	if(b < m) return b;
	return b % m;
}

int main()
{
	int a = 0, n =  7       ;
	
	for(int u = 0; u < 100; ++u)
	{
		a = mod((u * mod(10, n)), n);
		cout<< a << ",";
		if(u && u % n == 0)
		cout<<endl;
	}

	return 0;
}

#elif 0

// Calculate MOD of a very large number (ex: even can't be stored in 'long long int')

// Hint: Divide and Conquer
// 12345678910346916352 % 7
// 1 mod 7 = 1
// 12 mod 7 = (1 * 10 + 2) mod 7 = 5
// 123 mod 7 = (5 * 10 + 3) mod 7 = 4
// 1234 mod 7 = (4 * 10 + 4) mod 7 = 2 etc.,

// src: http://www.geeksforgeeks.org/how-to-compute-mod-of-a-big-number/
// http://pravnlives.blogspot.co.uk/#
//    (A+B)%m = (A%m + B%m) %m
//    (A-B)%m = (A%m - B%m) %m
//    (A*B)%m = (A%m * B%m) %m


// Function to comput num (mod m)
int mod(string num, unsigned int m)
{    
    int res = 0;
 
    // One by one process all digits of 'num' from left to right
    for (int i = 0; i < num.length(); i++)
         res = (res*10 + (unsigned int)num[i] - '0') % m;
 
    return res;
}

int main()
{
	string num = "12345678910346916352";  // 12345678910346916352 % 7	
    cout << mod(num, 7); // 1
    return 0;
}

#elif 1


#endif
