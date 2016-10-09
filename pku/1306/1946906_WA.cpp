#include <iostream>
using namespace std;
int main()
{
	__int64 n,m,i,t,p;
	while(scanf("%I64d%I64d",&n,&m)&&(n||m))
	{
		t=1;
		p=2;
		if(m>n/2)
			m=n/2;
		for(i=0;i<m;i++)
		{
			t*=n-i;
			while(p<=m&&t%p==0)
			{
				t/=p;
				p++;
			}
		}
		printf("%I64d things taken %I64d at a time is %I64d exactly.\n",n,m,t);
	}
	return 0;
}


