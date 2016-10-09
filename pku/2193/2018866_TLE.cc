#include <iostream>
#include <math.h>
using namespace std;
int m,t;
int dosth(int n,int x)
{
	int i,p=0;
	if(x==1)
		return m-2*n+1;
	for(i=2*n;;i++)
	{
		if(i*pow(2,x-1)<=m)
			p+=dosth(i,x-1);
		else
			break;
	}
	return p;
}
int main()
{
	int n,l,i,k=0;
	cin>>l;
	while(l-->0)
	{
		t=0;
		k++;
		cin>>n>>m;
		if(n==1)
			t=m;
		else
		{
			for(i=1;;i++)
			{
				if(i*pow(2,n-1)<=m)
					t+=dosth(i,n-1);
				else
					break;
			}
		}
		printf("Case %d: n = %d, m = %d, # lists = %d\n",k,n,m,t);
	}
	return 0;
}
		