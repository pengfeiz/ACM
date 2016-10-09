#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

bool b[16000001]={0};
int x[10000001];

int main()
{
	int a,c,r,m,i,ma=0,q,n;
	scanf("%d%d%d%d",&a,&c,&m,&r);
	b[r]=true;
	x[0]=r;
	n=1;
	while(1)
	{
		q=(a*r+c);
		if(q>=m)
			q%=m;
		if(b[q])
			break;
		b[q]=true;
		x[n++]=q;
		r=q;
	}
	sort(x,x+n);
	for(i=1;i<n;i++)
	{
		m=x[i]-x[i-1];
		if(m>ma)
			ma=m;
	}
	printf("%d\n",ma);
	return 0;
}