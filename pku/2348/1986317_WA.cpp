#include <iostream>
using namespace std;
int main()
{
	__int64 a,b,t,p;
	while(scanf("%I64d%I64d",&a,&b)&&(a||b))
	{
		t=p=0;
		if(a<b)
			swap(a,b);
		if(a==b)
			t=1;
		while(a>b)
		{
			if(a/b>1)
			{
				if(p==0)
					t=2;
				else
					t=1;
				break;
			}
			a=a%b;
			if(a==0)
				break;
			swap(a,b);
			p=(p+1)%2;
		}
		if(t==1)
			cout<<"Ollie wins\n";
		else
			cout<<"Stan wins\n";
	}
	return 0;
}
		