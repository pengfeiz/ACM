#include <iostream>
using namespace std;
int main()
{
	double n1,n2,l1,l2,p1,p2,p3,p4,min;
	while(cin>>n1>>n2>>l1>>l2&&!(n1==0&&n2==0&&l1==0&&l2==0))
	{
		min=0;
		if(n1<=l1&&n2<=l2||n1<=l2&&n2<=l1)
		{
			cout<<"100%\n";
			continue;
		}
		p1=l1/n1;
		p2=l2/n1;
		p3=l1/n2;
		p4=l2/n2;
		if(n2*p1>l2)
			p1=0;
		if(n2*p2>l1)
			p2=0;
		if(n1*p3>l2)
			p3=0;
		if(n1*p4>l1)
			p4=0;
		if(p1<p2)
			min=p2;
		else min=p1;
		if(p3>min)
			min=p3;
		if(p4>min)
			min=p4;
		cout<<int(100*min)<<"%\n";
	}
	return 0;
}






