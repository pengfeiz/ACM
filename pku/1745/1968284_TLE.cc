#include <iostream>
using namespace std;
long a[10000],n,k;
int find(long num,long i)
{
	if(num==n)
	{
		if(i%k==0)
			return 1;
		return 0;
	}
	if(find(num+1,i-a[num])==1)
		return 1;
	return find(num+1,i+a[num]);
}
int main()
{
	long i,tt;
	while(cin>>n>>k)
	{
		for(i=0;i<n;i++)
		{
			scanf("%ld",&a[i]);
			a[i]=abs(a[i]);
		}
		for(i=tt=0;i<n;i++)
			tt+=a[i];
		for(i=0;i<tt;i+=k)
		{
			if(find(0,i)==1)
			{
				printf("Divisible\n");
				break;
			}
		}
		if(i>=tt)
			printf("Not divisible\n");
	}
	return 0;
}


		