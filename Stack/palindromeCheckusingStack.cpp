#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s)
{
	stack<char> s1;
	int mark; 
	for(int i=0;s[i]!='X';i++)
	{
		
		s1.push(s[i]);
		mark=i+1;
	}
	for(int i=mark+1;i<s.length();i++)
	{
		if(s1.top()==s[i])
		{
			s1.pop();
		}
		else
		{
			return false;
		}
	}

	return true;
}




int main()
{
	string s = "ababXbaba";
	cout<<isPalindrome(s)<<endl;
	
}