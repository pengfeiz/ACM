#include <iostream>
using namespace std;
#define MAX 200

char s[MAX][40];
char st[40],en[40];
double a[MAX][MAX],l;
int n,m,x,y,tim=0,nn;

double minn(double a,double b)
{return a>b?b:a;}

int main()
{
	int i,j,k;
	while(scanf("%d%d",&nn,&m),nn||m)
	{
		memset(a,0,sizeof(a));
		tim++;
		n=0;
		printf("Scenario #%d\n",tim);
		for(i=0;i<m;i++)
		{
			scanf("%s%s%lf",st,en,&l);
			for(j=0;j<n;j++)
				if(strcmp(st,s[j])==0)
					break;
			x=j;
			for(j=0;j<n;j++)
				if(strcmp(en,s[j])==0)
					break;
			y=j;
			if(x==n&&y==n)
			{
				strcpy(s[n],st);
				strcpy(s[n+1],en);
				a[n][n+1]=a[n+1][n]=l;
				n+=2;
			}
			else if(x==n)
			{
				strcpy(s[n],st);
				a[n][y]=a[y][n]=l;
				n++;
			}
			else if(y==n)
			{
				strcpy(s[n],en);
				a[x][n]=a[n][x]=l;
				n++;
			}
			else if(a[x][y]<l)
				a[x][y]=a[y][x]=l;
		}
		for(k=0;k<nn;k++)
			for(i=0;i<nn;i++)
				for(j=0;j<nn;j++)
					if(a[i][j]<minn(a[i][k],a[k][j]))
						a[i][j]=minn(a[i][k],a[k][j]);
		scanf("%s%s",st,en);
		for(j=0;j<n;j++)
			if(strcmp(st,s[j])==0)
			{
				x=j;
				break;
			}
		for(j=0;j<n;j++)
			if(strcmp(en,s[j])==0)
			{
				y=j;
				break;
			}
		printf("%.0lf tons\n\n",a[x][y]);
	}
	return 0;
}