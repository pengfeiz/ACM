#include<iostream>
#include<algorithm>
using namespace std;

int x[200002],y[200002],z[200002];

bool cmp(int a,int b)
{return a>b;}

int main()
{
	int n,i;
	__int64 res,tmp1,tmp2,tmp3;
	while(scanf("%d",&n)==1&&n!=0)
	{
		res=0;
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
		tmp1=tmp2=tmp3=0;
        for(i=1;i<n;i++)
		{
            tmp1=tmp1+i*(x[i-1]-x[i]);
            res+=tmp1;
            tmp2=tmp2+i*(y[i-1]-y[i]);
            res+=tmp2;
            tmp3=tmp3+i*(z[i-1]-z[i]);
            res+=tmp3;
        }
		printf("%I64d\n",res/2);
	}
	return 0;
}