#include<iostream>
#include<algorithm>
using namespace std;

int x[200002],y[200002],z[200002],q[200002];

bool cmp(int a,int b)
{return a>b;}

int main()
{
	int n,i,z1,z2,z3;
	__int64 sum;
	while(scanf("%d",&n)==1&&n!=0)
	{
		sum=0;
		for(i=0;i<n;i++)
		{
			scanf("%d %d %d",&z1,&z2,&z3);
			x[i]=z1-z2;y[i]=z2-z3;z[i]=z3-z1;
		}
		sort(x,x+n,cmp);
		sort(y,y+n,cmp);
		sort(z,z+n,cmp);
		q[n]=0;
		for(i=n-1;i>=0;i--)
			q[i]=x[i]+y[i]+z[i]+q[i+1];
		for(i=0;i<n;i++)
		{
			sum+=(x[i]+y[i]+z[i])*(n-i-1);
			sum-=q[i+1];
		}
		printf("%I64d\n",sum/2);
	}
	return 0;
}