#include <iostream>
#include <string.h>

using namespace std;
#define MAX 101


char s[MAX],c[2*MAX];
int d[MAX][MAX],n,l;

int min(int a,int b)
{return a<b?a:b;}

void find(int x,int y)
{
	int k,t,p;
	if(x==y)
	{
		if(s[x]=='('||s[x]==')')
		{
			c[l++]='(';
			c[l++]=')';
		}
		if(s[x]=='['||s[x]==']')
		{
			c[l++]='[';
			c[l++]=']';
		}
		return;
	}
	if(d[x][y]==0)
	{
		for(k=x;k<=y;k++)
			c[l++]=s[k];
		return;
	}
	t=0xffff;
	for(k=x;k<y;k++)
	{
		if(t>d[x][k]+d[k+1][y])
		{
			p=k;
			t=d[x][k]+d[k+1][y];
		}
	}
	if(((s[x]=='['&&s[y]==']')||(s[x]=='('&&s[y]==')'))&&t>d[x+1][y-1])
	{
		c[l++]=s[x];
		find(x+1,y-1);
		c[l++]=s[y];
	}
	else
	{
		find(x,p);
		find(p+1,y);
	}
}
	

int main()
{
	int i,j,k,p;
	scanf("%s",s+1);
	s[0]='a';
	memset(d,127,sizeof(d));
	n=strlen(s+1);
	for(i=1;i<=n;i++)
	{
		d[i][i-1]=0;
		d[i][i]=1;
	}
	for(p=1;p<n;p++)
		for(i=1;i<=n-p;i++)
		{
			j=i+p;
			if((s[i]=='('&&s[j]==')')||(s[i]=='['&&s[j]==']'))
				d[i][j]=min(d[i][j],d[i+1][j-1]);
			if(s[i]=='('||s[i]=='[')
				d[i][j]=min(d[i][j],d[i+1][j]+1);
			if(s[i]==')'||s[i]==']')
				d[i][j]=min(d[i][j],d[i][j-1]+1);
			for(k=i;k<j;k++)
				d[i][j]=min(d[i][j],d[i][k]+d[k+1][j]);
		}
	l=0;
	find(1,n);
	c[l]='\0';
	printf("%s\n",c);
	return 0;
} 
