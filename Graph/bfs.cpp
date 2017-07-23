#include <bits/stdc++.h>
using namespace std;

vector<int> a[10];
bool visited[10];


void init(bool a[],int n)
{
	for(int i=0;i<10;i++)
	{
		a[i] = 0;
	}
}

void bfs(int s)
{
	queue<int> q;
	q.push(s);
	visited[s] = 1;

	while(!q.empty())
	{
		int p = q.front();
		cout<<p<<endl;
		q.pop();
		for(int i=0;i<a[p].size();i++)
		{
			if(visited[a[p][i]]==false)
			{
				q.push(a[p][i]);
				visited[a[p][i]]= 1;
			}

		}
	}
}





int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int p,q;
		cin>>p>>q;
		a[p].push_back(q);
		a[q].push_back(p);
	}

	bfs(1);

}