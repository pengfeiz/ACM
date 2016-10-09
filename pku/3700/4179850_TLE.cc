#include <iostream>
#include <vector>
using namespace std;

#define maxn 51

int a[51],n,minn;
//bool p[51];
int p[51];

/*
void solve(int x,int y,int z,int w)
{
	if(y>=minn)
		return;
	if(z==n)
	{
		if(y<minn)
			minn=y;
		return;
	}
	int j;
	bool ff=false;
	if(w==0)
	{
		for(j=x+1;j<n;j++)
		{
			if(!p[j]&&a[j]>a[x])
			{
				p[j]=true;
				solve(j,y,z+1,w);
				p[j]=false;
				ff=true;
			}
		}
	}
	else
	{
		for(j=x+1;j<n;j++)
		{
			if(!p[j]&&a[j]<a[x])
			{
				p[j]=true;
				solve(j,y,z+1,w);
				p[j]=false;
				ff=true;
			}
		}
	}
	if(!ff)
	{
		for(j=0;j<n;j++)
			if(!p[j])
				break;
		if(j<n)
		{
			p[j]=true;
			solve(j,y+1,z+1,0);
			solve(j,y+1,z+1,1);
			p[j]=false;
		}
	}
}*/

void solve(int x,int z)
{
	if(z>=minn)
		return;
	if(x==n)
	{
		if(z<minn)
			minn=z;
		return;
	}

	int i;

	p[x]=1;
	bool ff=false;
	for(i=0;i<x;i++)
	{
		if(p[i]==p[x]&&a[i]<a[x])
		{
			ff=true;
			p[i]=3;
			solve(x+1,z);
			p[i]=1;
			break;
		}
	}
	if(!ff)
		solve(x+1,z+1);
	p[x]=2;
	ff=false;
	for(i=0;i<x;i++)
	{
		if(p[i]==p[x]&&a[i]>a[x])
		{
			ff=true;
			p[i]=3;
			solve(x+1,z);
			p[i]=2;
			break;
		}
	}
	if(!ff)
		solve(x+1,z+1);
	p[x]=0;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int i;
	while(scanf("%d",&n),n)
	{
		minn=99999999;
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		/*	a[i]=rand()%10001;
		for(i=0;i<n;i++)
			printf("%d ",a[i]);
		printf("\n");*/
		memset(p,0,sizeof(p));
		solve(0,0);
		printf("%d\n",minn);
	}
	return 0;
}