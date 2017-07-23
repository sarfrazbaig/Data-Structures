#include <bits/stdc++.h>
using namespace std;

vector<int>bfs(vector<int>a[],int s,int n)
{
    vector<int>visited(n);
    for(int i=0;i<n;i++)
    {
        visited[i] = 0;
    }
    queue<int>q;
    q.push(s);
    visited[s] = 1;
    while(!q.empty())
    {
        int p =q.front();
        q.pop();
        for(int i=0;i<a[p].size();i++)
        {
            if(visited[a[p][i]]==0)
            {
                q.push(a[p][i]);
                visited[a[p][i]] = visited[p]+1;
            }
        }
    }
    
    return visited; 
    
}

int main()
{
    int n;
    cin>>n;
    vector<int> a[n];
    
    for(int i=0;i<n-1;i++)
    {
        int p,q;
        cin>>p>>q;
        a[p].push_back(q);
        a[q].push_back(p);
        
    }
    
    int k;
    cin>>k;
    vector<int>ans = bfs(a,1,n);
    for(int i=0;i<ans.size();i++)
    {
        if(ans[i]==k)
        {
            cout<<ans[i]<<endl;
        }
    }
}
