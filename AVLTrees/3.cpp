#include <bits/stdc++.h>
using namespace std;

int main()
{

	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		char a[4][n+2];

		for(int i=0;i<4;i++)
		{
			for(int j=0;j<n+2;j++)
			{
				a[i][j]='b';
			}
		}
		
		for(int i=1;i<=2;i++)
		{
			for(int j=1;j<=n;j++)
			{
				cin>>a[i][j];
			}
		}

		int b[4][n+2];

		for(int i=0;i<4;i++)
		{
			for(int j=0;j<n+2;j++)
			{
				b[i][j]=-1;
			}
		}
		
		int count=0;
		for(int i=1;i<=2;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(a[i][j]=='#')
				{
					b[i][j]=count++;
				}
				else
				{
					b[i][j]=-1;
				}
			}
		}

		// for(int i=0;i<4;i++)
		// {
		// 	for(int j=0;j<n+2;j++)
		// 	{
		// 		cout<<b[i][j]<<"\t";
		// 	}
		// cout<<endl;
		// }
		



		
	}
}