#include <iostream>
using namespace std;
int num[20000][2];
int main()
{
	int n,i,j,k,t=0;
	while(cin>>n&&n!=0)
	{		
		if(t==0)
			t=1;
		else
			cout<<endl;
		while(cin>>num[1][0]&&num[1][0]!=0)
		{
			num[1][1]=1;
			for(i=2;i<=n;i++)
			{
				cin>>num[i][0];
				num[i][1]=1;
			}
			j=1;
			for(i=1;i<n&&j==1;i++)
			{
				if(num[i][0]-num[i+1][0]<=1)
					num[num[i][0]][1]=0;
				else
				{
					num[num[i][0]][1]=0;
					for(k=num[i+1][0]+1;k<num[i][0]&&j==1;k++)
						if(num[k][1]!=0)
							j=0;
				}
			}
			if(j==0)
				cout<<"No\n";
			else
				cout<<"Yes\n";
		}
	}
	return 0;
}


				