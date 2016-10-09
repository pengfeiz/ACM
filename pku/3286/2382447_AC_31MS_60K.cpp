#include <iostream>
#include <math.h>
using namespace std;

__int64 a[12],b[12],c[12];

__int64 dosth(__int64 x,int p,int y)
{
	if(x<10)
	{
		if(x==-1)
			return 0;
		return 1;
	}
	__int64 t;
	if(y)
		t=x/b[p]*a[p-1]+b[p];
	else
		t=(x/b[p]-1)*a[p-1]+c[p-1];
	x%=b[p];
	p--;
	while(p)
	{
		if(x>b[p])
			return t+dosth(x,p,1);
		if(x<10&&p==1)
		{
			t+=1;
			break;
		}
		t+=(x+1);
		p--;
	}
	return t;
}

int main()
{
//	freopen("in.txt","r",stdin);
	__int64 i,n,m,pn,pm;
	a[0]=0;
	c[0]=0;
	b[1]=1;
	b[0]=0;
	for(i=1;i<=11;i++)
		a[i]=(__int64)pow(10,i*1.0-1.0)*i;
	c[1]=1;
	for(i=2;i<=11;i++)
	{
		b[i]=b[i-1]*10;
		c[i]=c[i-1]+9*a[i-1];
	}
	while(scanf("%I64d%I64d",&n,&m),n+1||m+1)
	{
		n-=1;
		for(i=0;i<=11;i++)
			if(b[i]>n)
				break;
		i--;
		pn=i;
		for(i=0;i<=11;i++)
			if(b[i]>m)
				break;
		i--;
		pm=i;
		printf("%I64d\n",dosth(m,pm,0)-dosth(n,pn,0));
	}
	return 0;
}

