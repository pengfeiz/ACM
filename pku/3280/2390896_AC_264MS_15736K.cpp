#include <iostream>
#include <string.h>
using namespace std;
#define MAX 2002

char s[MAX],c[MAX];
int a[MAX][MAX],n,m;

struct gao
{
	int x,y;
}b[26];

int min(int a,int b)
{return a<b?a:b;}

int main()
{
//	freopen("in.txt","r",stdin);
	int l,i,j;
	char cc[2];
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	l=strlen(s+1);
	for(i=1;i<=l;i++)
		c[i]=s[l-i+1];
	c[l+1]='\0';
	for(i=0;i<n;i++)
	{
		scanf("%s",cc);
		scanf("%d%d",&b[cc[0]-'a'].x,&b[cc[0]-'a'].y);
	}
	a[0][0]=0;
	for(i=1;i<=l;i++)
		a[0][i]=min(b[s[i]-'a'].x,b[s[i]-'a'].y)+a[0][i-1];
	for(i=1;i<=l;i++)
		a[i][0]=min(b[c[i]-'a'].x,b[c[i]-'a'].y)+a[i-1][0];
	for(i=1;i<=l;i++)
		for(j=1;j<=l;j++)
		{
			if(s[i]==c[j])
				a[j][i]=a[j-1][i-1];
			else
			{
				a[j][i]=a[j-1][i]+min(b[c[j]-'a'].x,b[c[j]-'a'].y);
				a[j][i]=min(a[j][i],a[j][i-1]+min(b[s[i]-'a'].x,b[s[i]-'a'].y));
			}
		}
	printf("%d\n",a[l][l]/2);
	return 0;
}


