#include <iostream>
using namespace std;

#define MAX 26
#define MAX2 1001

int a[MAX][MAX];
int n,in[MAX],ll;
bool c[MAX];
int d[MAX];

int distra(int x,int y)
{
	int i,j;
	memset(c,0,sizeof(c));
	memset(d,127,sizeof(d));
	d[x]=0;
	c[x]=true;
	i=x;
	while(i!=y)
	{
		for(j=0;j<MAX;j++)
		{
			if(a[i][j]<d[j]-d[i])
				d[j]=d[i]+a[i][j];
		}
		for(j=0;j<MAX;j++)
			if(!c[j])
			{
				i=j;
				break;
			}
		for(j=0;j<MAX;j++)
			if(!c[j])
				if(d[j]<d[i])
					i=j;
		c[i]=true;
	}
	return d[y];
}

void dosth()
{
	int i,p,q;
	p=q=-1;
	for(i=0;i<MAX;i++)
	{
		if(in[i]%2)
		{
			if(p==-1)
				p=i;
			else
				q=i;
		}
	}
	if(p==q&&q==-1)
		printf("%d\n",ll);
	else
		printf("%d\n",ll+distra(p,q));
}

int main()
{
	char s[MAX2];
	int l,x,y;
	while(scanf("%s",s)!=EOF)
	{
		memset(in,0,sizeof(in));
		memset(a,127,sizeof(a));
		l=strlen(s);
		ll=l;
		x=s[0]-'a';
		y=s[l-1]-'a';
		in[x]++;
		in[y]++;
		a[x][y]=a[y][x]=l;
		while(scanf("%s",s),strcmp(s,"deadend"))
		{
			l=strlen(s);
			x=s[0]-'a';
			y=s[l-1]-'a';
			a[x][y]=a[y][x]=l;
			ll+=l;
			in[x]++;
			in[y]++;
		}
		dosth();
	}
	return 0;
}



