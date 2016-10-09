#include <iostream>
using namespace std;

int s[4][4];
int d[4][4];
int b[4],c[4];

int main()
{
	char ss[5];
	int e[16];
	for(i=0;i<16;i++)
		e[i]=1<<i;
	int i,j,x,y,k,maxx=99999999;
	int l;
	for(i=0;i<4;i++)
	{
		scanf("%s",ss);
		for(j=0;j<4;j++)
		{
			if(ss[j]=='+')
				s[i][j]=true;
			else
				s[i][j]=false;
		}
	}
	int m=1<<16;
	for(i=0;i<m;i++)
	{
		int tt=0;
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		memset(d,0,sizeof(d));
		for(j=0;j<16;j++)
		{
			if(i&e[j])
			{
				tt++;
				x=j/4;
				y=j%4;
				b[x]^=1;
				c[y]^=1;
				d[x][y]^=1;
			}
		}
		for(j=0;j<4;j++)
		{
			for(k=0;k<4;k++)
			{
				if((b[j]^c[k]^s[j][k]^d[j][k])==1)
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
		if(l&e[j])
		{
			x=j/4;
			y=j%4;
			printf("%d %d\n",x+1,y+1);
		}
	}
	return 0;
}