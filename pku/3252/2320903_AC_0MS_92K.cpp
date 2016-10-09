#include <iostream>
using namespace std;

__int64 cc(__int64 a,__int64 b)
{
	__int64 i,t=1,q=2;

	for(i=b;i>b-a;i--)
	{
		t*=i;
		while(q<=a&&t%q==0)
		{
			t/=q;
			q++;
		}
	}
	return t;
}

__int64 dosth(__int64 a)
{
	if(a<=1)
		return 0;
	int i,j,n,num=0,t,aa;
	int s[100];
	n=0;
	while(a)
	{
		n++;
		s[n]=a&1;
		a=a>>1;
	}
	aa=(1<<n-1)-1;
	num=dosth(aa);
	t=1;
	for(i=n-1;i>0;i--)
	{
		if(s[i])
		{
			for(j=0;j<=n/2-t;j++)
				num+=cc(j,i-1);
			t++;
		}
		else
			continue;
	}
	if(t<=n/2)
		num++;
	return num;
}





int main()
{
//	freopen("in.txt","r",stdin);
	__int64 a,b;
	scanf("%I64d%I64d",&a,&b);
	a--;
	printf("%I64d\n",dosth(b)-dosth(a));
	return 0;
}
