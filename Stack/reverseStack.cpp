#include <bits/stdc++.h>
using namespace std;

void p_b(stack<int>&s,int v)
{
    if(s.empty())
    {
        s.push(v);
        return;
    }
    int temp = s.top();
    s.pop();
    p_b(s,v);
    s.push(temp);
}


void reverse(stack<int>&s)
{
    if(!s.empty())
    {
        int v = s.top();
        s.pop();
        reverse(s);
        p_b(s,v);
    }
}



int main()
{
    stack<int> s;
    for(int i=0;i<5;i++)
    {
        s.push(i);
    }   
    reverse(s);
    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
}