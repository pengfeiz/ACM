#include <iostream>
using namespace std;
#define MAX 300
int main()
{
	int nn,x1,x2,y1,y2,t,a[MAX][MAX],i,j,k,he[8][2]={1,2,2,1,1,-2,2,-1,-1,-2,-2,-1,-1,2,-2,1},n;
	cin>>nn;
	while(nn-->0)
	{
		t=0;
		cin>>n;
		cin>>x1>>y1>>x2>>y2;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				a[i][j]=-1;
		a[x1][y1]=t;
		while(a[x2][y2]==-1)
		{
			for(i=0;i<n;i++)
				for(j=0;j<n;j++)
				{
					if(a[i][j]==t)
					    for(k=0;k<8;k++)
							if(i+he[k][0]>=0&&i+he[k][0]<n&&j+he[k][1]>=0&&j+he[k][1]<n&&a[i+he[k][0]][j+he[k][1]]==-1)
								a[i+he[k][0]][j+he[k][1]]=t+1;
				}
			t++;
		}
		cout<<t<<endl;
	}
	return 0;
}


		
