#include <iostream>
#include <math.h>
using namespace std;
int prime(int x)
{
	int i;
	for(i=2;i<=sqrt(x*1.0);i++)
		if(x%i==0)
			return 0;
	return 1;
}
int main()
{
	int n,c,num,i,j;
	int a[1001]={0};	
	for(i=2;i<=1000;i++)
		if(prime(i)==1)
		{
			a[i]=1;
			num++;
		}
	a[1]=1;
	while(cin>>n>>c)
	{
		num=i=0;
		while(1)
		{
			if(a[i]==1)
				num++;
			i++;
			if(i>n)
				break;
		}
		printf("%d %d:",n,c);
		if(num%2==0)
			for(i=j=0;j<=num/2+c&&i<=n;i++)
			{
				if(a[i]==0)
					continue;
				if(a[i]==1)
					j++;
				if(j>=num/2-c+1&&j<=num/2+c&&a[i]==1)
					cout<<" "<<i;
			}
		else
			for(i=j=0;j<=num/2+c&&i<=n;i++)
			{
				if(a[i]==0)
					continue;
				if(a[i]==1)
					j++;
				if(j>=num/2-c+2&&j<=num/2+c)
					cout<<" "<<i;
			}
		cout<<"\n\n";
	}
	return 0;
}
