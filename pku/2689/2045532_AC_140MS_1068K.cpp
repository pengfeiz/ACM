#include <iostream>
#include <math.h>
using namespace std;
#define MAX 1000001
unsigned int n,a[6542];
bool he[MAX];
bool prime(unsigned int num)
{
	unsigned int i;
	for(i=0;a[i]<=sqrt(num*1.0);i++)
		if(num%a[i]==0)
			return false;
	return true;
}

int main()
{
//	freopen("in.txt","r",stdin);
	unsigned int i,n1,n2,min,max,p1,p2,q1,q2,j;
	n=1;
	a[0]=2;
	for(i=3;i<65536;i++)
		if(prime(i))
			a[n++]=i;
	while(scanf("%d%d",&n1,&n2)!=EOF)
	{
		memset(he,0,sizeof(he));
		p1=0;
		max=j=0;
		min=999999;
		while(n1<2)
			n1++;
		i=n1;
		if(n1%2)
			i++;
		for(i;i<=n2;i+=2)
		{
			if(i==2)
				continue;
			he[i-n1]=true;
		}
		for(i=1;a[i]<=sqrt(n2);i++)
		{
			j=n1/a[i]*a[i];
			if(j<n1)
				j+=a[i];
			if(j==a[i])
				j+=a[i];
			j-=n1;
			for(;j<=n2-n1;j+=a[i])
				he[j]=true;
		}
		while(he[p1]&&p1<=n2-n1)
			p1++;
		if(p1>n2-n1)
		{
			printf("There are no adjacent primes.\n");
			continue;
		}
		j=p2=p1;
		for(i=p1+1;i<=n2-n1;i++)
		{
			if(!he[i])
			{
				if(i-j>max)
				{
					max=i-j;
					q1=j;
					q2=i;
				}
				if(i-j<min)
				{
					min=i-j;
					p1=j;
					p2=i;
				}
				j=i;
			}
		}
		if(p1==p2)
			printf("There are no adjacent primes.\n");
		else
			printf("%d,%d are closest, %d,%d are most distant.\n",p1+n1,p2+n1,q1+n1,q2+n1);
	}
	return 0;
}

