#include <iostream>
using namespace std;
int b[100][200],c[100];
int main()
{
	unsigned __int64 n;
	int i,j,t;
	c[0]=0;
	c[1]=0;
	b[1][0]=1;
	for(i=2;i<100;i++)
	{
		c[i]=c[i-1];
		for(j=0;j<=c[i];j++)
			b[i][j]=b[i-1][j]*3;
		for(j=1;j<=c[i];j++)
		{
			b[i][j]+=b[i][j-1]/10;
			b[i][j-1]%=10;
		}
		while(b[i][c[i]]>9)
		{
			b[i][c[i]+1]=b[i][c[i]]/10;
			b[i][c[i]]%=10;
			c[i]++;
		}
	}
	while(scanf("%I64d",&n)&&n)
	{
		t=0;
		j=0;
		n--;
		printf("{");
		while(n>0)
		{
			j++;
			if(n%2)
			{
				if(!t)
					printf(" ");
				if(t)
					printf(", ");
				t++;
				for(i=c[j];i>=0;i--)
					printf("%d",b[j][i]);
			}
			n/=2;
		}
		printf(" }\n");
	}
	return 0;
}



