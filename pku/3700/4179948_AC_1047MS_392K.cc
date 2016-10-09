#include <iostream>
#include <vector>
using namespace std;

#define maxn 51

int a[51],n,minn;
int b[3][51];
int b1,b2;

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

	int i,q;

	bool ff=false;
	for(i=0;i<b1;i++)
	{
		if(a[x]>b[1][i])
		{
			ff=true;
			q=b[1][i];
			b[1][i]=a[x];
			solve(x+1,z);
			b[1][i]=q;
			break;
		}
	}
	if(!ff)
	{
		b[1][b1++]=a[x];
		solve(x+1,z+1);
		b1--;
	}

	ff=false;
	for(i=0;i<b2;i++)
	{
		if(a[x]<b[2][i])
		{
			ff=true;
			q=b[2][i];
			b[2][i]=a[x];
			solve(x+1,z);
			b[2][i]=q;
			break;
		}
	}
	if(!ff)
	{
		b[2][b2++]=a[x];
		solve(x+1,z+1);
		b2--;
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
		/*	a[i]=rand()%10001;
		for(i=0;i<n;i++)
			printf("%d ",a[i]);
		printf("\n");*/
		b1=b2=0;
		solve(0,0);
		printf("%d\n",minn);
	}
	return 0;
}