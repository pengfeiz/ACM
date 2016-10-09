#include<iostream>
#include<algorithm>
using namespace std;

int x[200002],y[200002],z[200002];

bool cmp(int a,int b)
{return a>b;}

int main()
{
	int n,i;
	__int64 res,tmp1,tmp2,tmp3,tmp;
	while(scanf("%d",&n)==1&&n!=0)
	{
		res=tmp=0;
		for(i=0;i<n;i++)
		{
			scanf("%d %d %d",&tmp1,&tmp2,&tmp3);
			x[i]=tmp1-tmp2;
			y[i]=tmp2-tmp3;
			z[i]=tmp3-tmp1;
		}
		sort(x,x+n,cmp);
		sort(y,y+n,cmp);
		sort(z,z+n,cmp);
        for(i=1;i<n;i++)
		{
            tmp+=i*(x[i-1]+y[i-1]+z[i-1]-x[i]-y[i]-z[i]);
            res+=tmp;
        }
		printf("%I64d\n",res/2);
	}
	return 0;
}