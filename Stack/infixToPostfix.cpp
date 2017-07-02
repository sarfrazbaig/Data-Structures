#include <bits/stdc++.h>
using namespace std;

int getPrecedence(char s)
{
	if(s =='*' || s =='/')
	{
		return 2;
	}
	else if(s == '+' || s=='-')
	{
		return 1;
	}
}

bool isOperator(char s)
{
	if(s=='+'||s=='/'||s=='-'||s=='*')
	{
		return true;
	}
	else
	{
		return false;
	}
}

string infixToPostfix(string exp)
{
	string res="";
	stack<char>s;

	for(int i=0;i<exp.length();i++)
	{
		if(!isOperator(exp[i]))
		{
			res.push_back(exp[i]);
		}
		else
		{
			if(s.empty())
			{
				s.push(exp[i]);
			}
			else
			{
				char p=s.top();
				if(getPrecedence(p)<getPrecedence(exp[i]))
				{
					s.push(exp[i]);
				}
				else
				{
					while(!s.empty())
					{
						char t = s.top();
						s.pop();
						res.push_back(t);
					}

					s.push(exp[i]);
				}
			}
		}
	}

	if(!s.empty())
	{
		while(!s.empty())
		{
			res.push_back(s.top());
			s.pop();
		}
	}

	return res;

}


int main()
{
	string exp = "a+b*c";
	cout<<infixToPostfix(exp)<<endl;
	
}