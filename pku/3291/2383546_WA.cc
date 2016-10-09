#include <iostream>
using namespace std;
#define MAX 201

char s[MAX],c[MAX];
int b[MAX][MAX],ls,lc;

int min(int a,int b)
{return a<b?a:b;}

int main()
{
	int i,j,t,x,y;
	while(scanf("%s%s",s,c),strcmp(s,"0")||strcmp(c,"0"))
	{
		memset(b,0,sizeof(b));
		ls=strlen(s);
		lc=strlen(c);
		for(i=0;i<ls;i++)
			for(j=0;j<lc;j++)
			{
				if(s[i]==c[j])
					b[i+1][j+1]=b[i][j]+1;
				else
					b[i+1][j+1]=b[i][j+1]>b[i+1][j]?b[i][j+1]:b[i+1][j];
			}
			t=ls<lc?ls:lc;
			x=b[ls][lc];
			y=ls>lc?ls:lc-x;
			printf("%d %d %d\n",t,x,y);
			for(i=0;y;i++)
			{
				y-=min(y,(x+y)/2);
				x+=min(x+y,t-x);
				printf("%d %d %d\n",t,x,y);
			}
		printf("%d\n",i>1?i:1);
	}
	return 0;
}

