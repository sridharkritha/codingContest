#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <vector>
using namespace std;

/*
Input:
3
(a+(b*c))
((a+b)*(z+x))
((a+t)*((b+(a+c))^(c+d)))

Output:
abc*+
ab+zx+*
at+bac++cd+^*
*/



int main()
{
	vector<string> v;
	string outputString;	
	stack<char> stk;	
	char c;
	// +, -, *, /, ^ - Priority order
	map<char,unsigned int> m;
	m['+'] = 0;
	m['-'] = 1;
	m['*'] = 2;
	m['/'] = 3;
	m['^'] = 4;

	string str; //  = "((a+t)*((b+(a+c))^(c+d)))" ; // "(a+(b*c))";	
	unsigned int tc = 0;
	unsigned int n = 0;
	cin >> n;

	for(tc = 0; tc < n; ++tc)
	{
		outputString.clear();

		cin >> str;

		for(unsigned int i = 0; i < str.size(); ++i)
		{
			c = str[i];
			if(c >= 'a' && c <= 'z') // isalpha(c)
			{
				// If it is an operand, push it to the output
				outputString.push_back(c);
			}
			else if(c == ')')
			{
				// If it is a right bracket, keep popping the stack and pushing into the output until a left bracket is encountered
				while('(' != stk.top())
				{
					outputString.push_back(stk.top());
					stk.pop();
				}

				stk.pop(); // remove '('			
			}
			else if(c == '(')
			{
				//  If it is a left bracket, push onto stack
				stk.push(c);
			}
			else
			{
				// If it's an operator - check for precedence if the top of the stack is an operator and it has higher precedence than 
				// current operator then pop the stack and push onto output, continue until condition is false. Then push in the current operator into stack.
				while(m[c] < m[stk.top()])
				{
					outputString.push_back(stk.top());
					stk.pop();
				}
				stk.push(c);
			}
		
		}

		// cout<<outputString<<endl;
		v.push_back(outputString);
	}

	for(tc = 0; tc < n; ++tc)
	{
		cout<<v[tc]<<endl;
	}	

	return 0;
}