
#include <iostream>
using namespace std;

__int64 minn(__int64 a,__int64 b)
{return a<b?a:b;}
int main()
{
	__int64 a,b,c,d,dd,cc;
	__int64 t1,t2,h;
	while(scanf("%I64d%I64d%I64d%I64d",&a,&b,&c,&d)!=EOF)
	{
		h=0;
		t1=0;
		dd=d;
		while(dd>a)
		{
			dd=(dd+1)/2;
			h++;
		}
		t1+=h;
		cc=c;
		h=0;
		while(cc>b)
		{
			cc=(cc+1)/2;
			h++;
		}
		t1+=h;

		h=0;
		t2=0;
		dd=d;
		while(dd>b)
		{
			dd=(dd+1)/2;
			h++;
		}
		t2+=h;
		cc=c;
		h=0;
		while(cc>a)
		{
			cc=(cc+1)/2;
			h++;
		}
		t2+=h;
		printf("%I64d\n",minn(t1,t2));
	}
	return 0;
}