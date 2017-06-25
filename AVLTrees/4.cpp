#include <iostream> 
using namespace std; 

int main() { 
	int m,n; 
	int a[600][600]; 
	bool found = false;
	int t;

	cin>>t; 
	while(t--)
	{
		
	// cout << " m & n :" ; 
					cin>>n; 
					char b[500][600];
					// cout<<" Enter matrix elements : "; 
					for (int i = 0; i < 2; i++) { 
					for (int j = 0 ; j < n ; j++) { 
					cin>>b[i][j]; 
					} 
					}

					for (int i = 0; i < 2; i++) { 
					for (int j = 0 ; j < n ; j++) { 
						if(b[i][j]=='#')
						{
							a[i][j]=1;
						} 
						else if(b[i][j]=='.')
						{
							a[i][j]=0;
						}
					} 
					}  

					int xiter [] = { 1, 0 , -1 ,0 }; 
					int yiter [] = { 0, 1 , 0 ,-1 }; 

					int island_count = 0; 


					// Count number of islands - 
					for (int i =0 ; i < 2; i++) 
					for (int j = 0; j < n; j++) { 
					if (a[i][j] == 1) { 
					bool island = true; 
					a[i][j] = 2; 
					for (int k = 0; k < 4; k++) { 
					int x = i+ xiter[k]; 
					int y = j + yiter[k]; 
					if (x < 0 || y < 0 || x >=2
					 || y>= n) 
					continue; 
					if (a[x][y] == 1) { 
					a[x][y] = 2; 
					} else if (a[x][y] == 2) { 
					island = false; 
					} 
					} 
					if (island) 
					island_count++; 
					} 
					} 
					// cout << " Number of islands : " <<island_count <<endl; 
					if(island_count>1)
					{
						cout<<"no"<<endl;
					}
					else
					{
						cout<<"yes"<<endl;
					}


	}
	 
}