#include <iostream>
#include <math.h>
using namespace std;

bool b[16000001];

int main()
{
	int a,c,r,m,i,ma=0,n1,n2;
	scanf("%d%d%d%d",&a,&c,&m,&r);
	b[r]=true;
	n1=n2=r;
	while(1)
	{
		r=(a*r+c);
		if(b[r])
			break;
		if(r>=m)
			r%=m;
		if(r>n2)
			n2=r;
		if(r<n1)
			n1=r;
		b[r]=true;
	}
	r=n1;
	for(i=r+1;i<=n2;i++)
	{
		if(b[i])
		{
			if(i-r>ma)
				ma=i-r;
			r=i;
		}
	}
	printf("%d\n",ma);
	return 0;
}
