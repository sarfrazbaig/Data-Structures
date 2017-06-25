#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long int n;
		cin>>n;
		vector<long long int>a(n);
		long long int count = 0;

		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		if(a.size()%2==0)
		{
			count = count+
			a.pop_back();

		}

		long long int comp = a.size();

		int start,end;
		start = 0;
		end = a.size()-1;
		long long int check = 1;
		
		for(int i=0;i<a.size();i++)
		{
			cout<<a[i]<<" ";
		}
		cout<<endl;
		for(int i=1;i<=comp/2;i++)
		{
			cout<<"start"<<start<<" "<<"end"<<end<<endl;
			if(a[start]==a[end] && a[start]==check)
			{
				check++;
				start++;
				end--;
			}
			else
			{
				if(a[start]==check && a[end]!=check)
				{
					a[end] = check;
					count = count + (a[end] - check);
					start++;
					end--;
					check++;
				}
				else if(a[end]==check && a[start]!=check)
				{
					a[start]=check;
					count = count + (a[start]-check);
					start++;
					end--;
					check++;
				}
				else
				{
					a[start]=check;
					a[end]=check;
					count = count + (a[start]-check);
					count = count + (a[end]-check);
					check++;
				}
			}
		}
		long long int middle = a.size()/2;
		cout<<a[middle]<<"middle"<<endl;
		while(a[middle]!=check)
		{
			a[middle]--;
			count++;
		}
		cout<<count<<endl;
	}	
}