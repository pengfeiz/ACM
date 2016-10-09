#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 26
#define MAX2 15
struct gao
{
	char s[MAX2];
	int n,m,p;
}s[MAX],c[MAX];


bool a[MAX][MAX],b[MAX][MAX],q[MAX]; 
int d[MAX],na,nb;

int change(char x)
{if(x>='a')return x-32;return x;}

bool com(gao a,gao b)
{
	int i=0;
	while(a.s[i]==b.s[i])
		i++;
	if(change(a.s[i])!=change(b.s[i]))
		return change(a.s[i])<change(b.s[i]);
	return a.s[i]<b.s[i];
}


bool dfs(int x)
{
	int i,j;
	for(i=0;i<x;i++)
		for(j=0;j<na;j++)
			if(d[j]>=0&&(a[s[i].p][s[j].p]^b[d[i]][d[j]]))
				return false;
	if(x==na)
		return true;
	for(i=0;i<na;i++)
	{
		if(!q[i]&&s[x].n==c[i].n&&s[x].m==c[i].m)
		{
			d[x]=i;
			q[i]=true;
			if(dfs(x+1))
				return true;
			q[i]=false;
			d[x]=-1;
		}
	}
	return false;
}

int main()
{
	int n,i,j,k;
	char ss[MAX2],cc[MAX2];
	while(scanf("%d",&n),n)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(s,0,sizeof(s));
		memset(c,0,sizeof(c));
		na=nb=0;
		for(i=0;i<n;i++)
		{
			scanf("%s%s",ss,cc);
			for(j=0;j<na;j++)
				if(!strcmp(ss,s[j].s))
					break;
			if(j==na)
			{
				strcpy(s[na].s,ss);
				s[na].p=na;
				na++;
			}
			for(k=0;k<na;k++)
				if(!strcmp(cc,s[k].s))
					break;
			if(k==na)
			{
				strcpy(s[na].s,cc);
				s[na].p=na;
				na++;
			}
			s[j].n++;
			s[k].m++;
			a[j][k]=true;
		}
		for(i=0;i<n;i++)
		{
			scanf("%s%s",ss,cc);
			for(j=0;j<nb;j++)
				if(!strcmp(ss,c[j].s))
					break;
			if(j==nb)
			{
				strcpy(c[nb].s,ss);
				c[nb].p=nb;
				nb++;
			}
			for(k=0;k<nb;k++)
				if(!strcmp(cc,c[k].s))
					break;
			if(k==nb)
			{
				strcpy(c[nb].s,cc);
				c[nb].p=nb;
				nb++;
			}
			c[j].n++;
			c[k].m++;
			b[j][k]=true;
		}
		sort(s,s+na,com);
		memset(d,0xff,sizeof(d));
		memset(q,0,sizeof(q));
		dfs(0);
		for(i=0;i<na;i++)
			printf("%s/%s\n",s[i].s,c[d[i]].s);
		printf("\n");
	}
	return 0;
}