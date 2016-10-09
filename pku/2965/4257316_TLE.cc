#include <iostream>
using namespace std;

int s[4][4];
int b[4][4];

int main()
{
	char ss[5];
	int i,j,x,y,k,maxx=99999999;
	int n=4;
	int l;
	for(i=0;i<n;i++)
	{
		scanf("%s",ss);
		for(j=0;j<n;j++)
		{
			if(ss[j]=='+')
				s[i][j]=1;
			else
				s[i][j]=0;
		}
	}
	int m=1<<16;
	for(i=0;i<m;i++)
	{
		int tt=0;
		memset(b,0,sizeof(b));
		for(j=0;j<16;j++)
		{
			if(i&(1<<j))
			{
				tt++;
				x=j/4;
				y=j%4;
				for(k=0;k<4;k++)
				{
					b[x][k]^=1;
					b[k][y]^=1;
				}
				b[x][y]^=1;
			}
		}
		for(j=0;j<4;j++)
		{
			for(k=0;k<4;k++)
			{
				if(b[j][k]^s[j][k]!=0)
					break;
			}
			if(k<4)
				break;
		}
		if(j==4)
		{
			if(tt<maxx)
			{
				l=i;
				maxx=tt;
			}
		}
	}	
	
	printf("%d\n",maxx);
	for(j=0;j<16;j++)
	{
		if(l&(1<<j))
		{
			x=j/4;
			y=j%4;
			printf("%d %d\n",x+1,y+1);
		}
	}
	return 0;
}