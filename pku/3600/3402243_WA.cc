#include <iostream>
using namespace std;

bool a[21][21];
bool b[21][21];
int aa[21];
int bb[21];
int cc[21];
int c[21];
bool f[21];

int main()
{
//	freopen("in.txt","r",stdin);
	int n,m,N,M,i,j,k,x,y,tt,t;
	char s[22];
	for(i=0;i<21;i++)
		c[i]=1<<i;
	scanf("%d%d",&n,&m);
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	for(i=0;i<n;i++)
	{
		scanf("%s",s);
		for(j=0;j<m;j++)
		{
			if(s[j]=='1')
				a[i][j]=true;
		}
	}
	memset(aa,0,sizeof(aa));
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			if(a[i][j])
				aa[j]++;
	scanf("%d%d",&N,&M);
	for(i=0;i<N;i++)
	{
		scanf("%s",s);
		for(j=0;j<M;j++)
		{
			if(s[j]=='1')
				b[i][j]=true;
		}
	}
	memset(bb,0,sizeof(bb));
	for(i=0;i<N;i++)
		for(j=0;j<M;j++)
			if(b[i][j])
				bb[j]++;
	tt=N-n;
	x=1<<N;
	for(k=0;k<x;k++)
	{
		t=0;
		for(i=0;i<M;i++)
			cc[i]=bb[i];
		for(i=0;i<N;i++)
		{
			if(k&c[i])
				t++;
		}
		if(t!=tt)
			continue;
		for(i=0;i<N;i++)
		{
			if(k&c[i])
			{
				for(j=0;j<M;j++)
					if(b[i][j])
						cc[j]--;
			}
		}
		j=0;
		for(i=0;i<m&&j<M;i++,j++)
		{
			while(aa[i]!=cc[j])
			{
				j++;
				if(j>=M)
					break;
			}
		}
		if(i==m)
			break;
	}
	if(k<x)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}
