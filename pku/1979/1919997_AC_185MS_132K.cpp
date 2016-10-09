#include <iostream>
using namespace std;
int num[22][22];
int main()
{
	int w,h,i,j,k,tt;
	char c;
	while(cin>>w>>h&&w&&h)
	{
		tt=0;
		for(i=0;i<22;i++)
			for(j=0;j<22;j++)
				num[i][j]=0;
		for(i=1;i<=h;i++)
			for(j=1;j<=w;j++)
			{
				cin>>c;
				if(c=='#')
					num[i][j]=0;
				else if(c=='.')
					num[i][j]=1;
				else if(c=='@')
				{
					tt=1;
					num[i][j]=2;
				}
			}
		for(k=0;k<450;k++)
			for(i=1;i<=h;i++)
				for(j=1;j<=w;j++)
					if(num[i][j]==1&&(num[i-1][j]==2||num[i][j-1]==2||num[i][j+1]==2||num[i+1][j]==2))
					{
						tt++;
						num[i][j]=2;
					}
		cout<<tt<<endl;
	}
	return 0;
}



				