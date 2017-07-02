#include <bits/stdc++.h>
using namespace std;

int main()
{
	stack<int>s1,s2;
	int n;
	for(int i=0;i<10;i++)
	{
		cin>>n;
		s1.push(n);
		if(s2.empty())
		{
			s2.push(n);
		}
		else if(n<s2.top())
		{
			s2.pop();
			s2.push(n);
		}
	}

	cout<<s2.top()<<endl;	



}