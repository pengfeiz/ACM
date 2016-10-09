#include <iostream>
using namespace std;
int main()
{
	__int64 a[100000],t,max,tt;
	int n,i,j;
	while(cin>>n&&n)
	{
		max=tt=0;
		for(i=0;i<n;i++)
		{
			scanf("%I64d",&a[i]);
			tt+=a[i];
		}
		for(i=0;i<n;i++)
		{
			t=0;
			for(j=i;j<n;j++)
			{
				if(a[j]<a[i])
					break;
				t++;
			}
			for(j=i-1;j>=0;j--)
			{
				if(a[j]<a[i])
					break;
				t++;
			}
			t*=a[i];
			if(t>max)
				max=t;
			if(max>tt-n)
				break;
		}
		printf("%I64d\n",max);
	}
	return 0;
}