#include <iostream>
using namespace std;
int main()
{
	__int64 n,m,i,t,p,q;
	while(scanf("%I64d%I64d",&n,&m)&&(n||m))
	{
		t=1;
		p=2;
		q=m;
		if(m>n/2)
			m=n-m;
		for(i=0;i<m;i++)
		{
			t*=n-i;
			while(p<=m&&t%p==0)
			{
				t/=p;
				p++;
			}
		}
		printf("%I64d things taken %I64d at a time is %I64d exactly.\n",n,q,t);
	}
	return 0;
}


