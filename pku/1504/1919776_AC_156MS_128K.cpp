#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	long n1,n2,n,i,t1,t2,l1,l2,j;
	cin>>n;
	for(i=0;i<n;i++)
	{
		l1=l2=0;
		cin>>n1>>n2;
		t1=n1;
		t2=n2;
		while(t1>=10)
		{
			l1++;
			t1=t1/10;
		}
		while(t2>=10)
		{
			l2++;
			t2=t2/10;
		}
		t1=t2=0;
		for(j=l1;j>=0;j--)
		{
			t1+=n1%10*(int)(pow(10,(double)j));
			n1=n1/10;
		}
		for(j=l2;j>=0;j--)
		{
			t2+=n2%10*(int)(pow(10,(double)j));
			n2=n2/10;
		}
		t1=t1+t2;
		while(t1%10==0)
			t1=t1/10;
		l1=0;
		n1=t1;
		while(t1>=10)
		{
			l1++;
			t1=t1/10;
		}
		for(j=l1;j>=0;j--)
		{
			cout<<n1%10;
			n1=n1/10;
		}
		cout<<endl;
	}
	return 0;
}
	