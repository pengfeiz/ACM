#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
const __int64 maxn=10001;
__int64 a,b,c,n,x[maxn];

int main()
{
	__int64 i,j,k;
	n=0;
	scanf("%I64d%I64d%I64d",&a,&b,&c);
	double w=pow(10,18),q;
	for(i=0;pow(a,i*1.0)<w;i++)
		for(j=0;pow(b,j*1.0)<w;j++)
			for(k=0;pow(c,k*1.0)<w;k++)
			{
				q=pow(a,i*1.0)*pow(b,j*1.0)*pow(c,k*1.0);
				if(q>=w)
					break;
				x[n++]=(__int64)(q+0.5);
			}
	sort(x,x+n);
	scanf("%I64d",&i);
	printf("%I64d\n",x[i]);
	return 0;
}