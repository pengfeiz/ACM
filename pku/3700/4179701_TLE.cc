#include <iostream>
#include <vector>
using namespace std;

#define maxn 51

int a[51],n,minn;
bool p[51];

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
		memset(p,0,sizeof(p));
		p[0]=true;
		solve(0,1,1,0);
		solve(0,1,1,1);
		printf("%d\n",minn);
	}
	return 0;
}