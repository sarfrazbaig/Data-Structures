#include <bits/stdc++.h>
using namespace std;

int performOperations(int a,int b,char s)
{
	if(s=='+')
	{
		return a+b;
	}
	if(s=='-')
	{
		return a-b;
	}
	if(s=='*')
	{
		return a*b;
	}
	if(s=='/')
	{
		return a/b;
	}
}

bool isOperator(char c)
{
	if(c=='+' || c=='-'|| c=='*' ||c=='/')
	{
		return true;
	}

	return false;
}


int postFixEvaluation(string exp)
{
	stack<int>s;
	for(int i=0;i<exp.length();i++)
	{
		if(isOperator(exp[i]) && exp[i]!=' ')
		{	
			int op2 = s.top();
			s.pop();
			int op1 = s.top();
			s.pop();

			int res = performOperations(op1,op2,exp[i]);
			s.push(res); 
		}
		else
		{
			if(exp[i]!=' ')
				s.push(exp[i]-48);
		}
		// cout<<s.top()<<endl;
	}
	
	return s.top();
}


int main()
{
	string exp = "2 3 * 5 4 * + 9 - ";
	cout<<postFixEvaluation(exp)<<endl;
}