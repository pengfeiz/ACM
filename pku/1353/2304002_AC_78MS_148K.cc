#include <iostream>
using namespace std;


int a[2][200];
int n,m,k,p,q;


bool init()
{
	scanf("%d",&n);
	if(n==-1)
		return false;
	scanf(",%d,%d",&m,&k);
	printf("%d,%d,%d: ",n,m,k);
	return true;
}


void solve()
{
	int i,t;
	p=t=0;q=1;
	memset(a,0,sizeof(a));
	for(i=0;i<m;i++)
		a[p][i]=true;
	while(k--)
	{
		a[p][n]=a[p][0];
		for(i=0;i<n;i++)
		{
			if(a[p][i]==a[p][i+1])
				a[q][i]=0;
			else
				a[q][i]=1;
		}
		p=(p+1)%2;
		q=(q+1)%2;
	}
	for(i=0;i<n;i++)
		if(a[p][i])
			t++;
	printf("%d\n",t);
}

int main()
{
	while(init())
		solve();
	return 0;
}