#include <iostream>
#include <math.h>
using namespace std;
__int64 a[23],b[24],c[23],n;

__int64 judge()
{
	__int64 i,j,t=0;
	bool d[23];
	memset(d,0,sizeof(d));
	for(i=0;i<n;i++)
	{
		j=i;
		if(!d[j])
		{
			while(!d[j])
			{
				d[j]=true;
				j=c[j];
			}
			t++;
		}
	}
	return t;
}

int main()
{
	__int64 i,t,m,j,x,mm;
	memset(b,0,sizeof(b));
	for(n=1;n<24;n++)
	{
		t=0;
		for(i=0;i<n;i++)
			a[i]=i;
		for(m=0;m<n;m++)
		{
			for(i=0;i<n;i++)
				c[i]=(i+m)%n;
			t+=(__int64)pow(3.0,judge()*1.0);
		}
		for(mm=0;mm<n;mm++)
		{
			m=mm;
			if(m%2==0)
			{
				m/=2;
				c[m]=m;
				x=(n-1)/2;
				i=(m+1+n)%n;
				j=(m-1+n)%n;
				while(x--)
				{
					c[i]=j;
					c[j]=i;
					i=(i+1+n)%n;
					j=(j-1+n)%n;
				}
				if(n%2==0)
					c[i]=i;
				t+=(__int64)pow(3.0,judge()*1.0);
			}
			else
			{
				x=n/2;
				i=(m+n)%n;
				j=(m-1+n)%n;
				while(x--)
				{
					c[i]=j;
					c[j]=i;
					i=(i+1+n)%n;
					j=(j-1+n)%n;
				}
				if(n%2)
					c[i]=i;
				t+=(__int64)pow(3.0,judge()*1.0);
			}
		}
		b[n]=t/2/n;
	}
	while(scanf("%I64d",&n)&&n!=-1)
		printf("%I64d\n",b[n]);
	return 0;
}

