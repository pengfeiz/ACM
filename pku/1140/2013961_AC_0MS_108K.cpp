#include <iostream>
using namespace std;
long gcd(long a,long b)
{
	long c;
	if(a<b)
		swap(a,b);
	while(a%b!=0)
	{
		c=a;
		a=b;
		b=c%b;
	}
	return b;
}
int main()
{
	long a,b,i,r,num[1000],j,p,t;
	while(scanf("%d%d",&a,&b)&&(a||b))
	{
		printf(".");
		i=gcd(a,b);
		a/=i;
		b/=i;
		i=b;
		while(i%2==0)
			i/=2;
		while(i%5==0)
			i/=5;
		if(i==1)
		{
			while(a!=0)
			{
				a*=10;
				cout<<a/b;
				a%=b;
			}
			printf("\nThis expansion terminates.\n");
			continue;
		}
		r=9;
		j=1;
		while(r%i)
		{
			r=r*10+9;
			r%=i;
			j++;
		}
		i=0;
		t=1;
		while(1)
		{
			a*=10;
			for(p=0;p<i;p++)
				if(a==num[p])
					break;
			if(p==i)
			{
				if(t==50)
				{
					t=0;
					printf("\n");
				}
				num[i++]=a;
				printf("%d",a/b);
				t++;
				a%=b;
				continue;
			}
			break;
		}
		printf("\nThe last %d digits repeat forever.\n",j);
	}
	return 0;
}
			
