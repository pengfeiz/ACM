#include <iostream>
using namespace std;
#define MAX 500
long a[MAX]={0};
int main()
{
	long i,t,j,n,x;
	a[0]=a[1]=1;
	x=2;
	for(j=2;j<20000;j++)
	{
		t=0;
		for(i=j+1;i<MAX;i++)
		{
			if(a[i]==0)
				t++;
			if(t==j)
			{
				a[i]=1;
				t=0;
			}
		}
		for(i=j+1;i<MAX;i++)
			if(a[i]==0)
			{
				j=i-1;
				break;
			}
	}
	while(cin>>n&&n)
	{
		for(i=t=0;i<MAX;i++)
		{
			if(a[i]==0)
				t++;
			if(t==n)
				break;
		}
		cout<<i<<endl;
	}
	return 0;
}



