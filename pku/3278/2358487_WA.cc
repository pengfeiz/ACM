#include <iostream>
using namespace std;

#define MAX 200000

int a[MAX],aa[MAX];
bool b[MAX];

int main()
{
	int n,m,i,t,n1,n2;
	scanf("%d%d",&n,&m);
	n1=1;
	a[0]=n;
	t=0;
	while(!b[m])
	{
		t++;
		n2=0;
		for(i=0;i<n1;i++)
		{
			if(a[i]<m)
			{
				if(!b[a[i]+1])
				{
					aa[n2++]=a[i]+1;
					b[a[i]+1]=true;
				}
				if(!b[a[i]*2])
				{
					aa[n2++]=a[i]*2;
					b[a[i]*2]=true;
				}
			}
			if(!b[a[i]-1])
			{
				aa[n2++]=a[i]-1;
				b[a[i]-1]=true;
			}
		}
		n1=n2;
		for(i=0;i<n1;i++)
			a[i]=aa[i];
	}
	printf("%d\n",t);
	return 0;
}