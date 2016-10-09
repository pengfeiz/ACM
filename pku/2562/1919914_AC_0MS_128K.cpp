#include <iostream>
using namespace std;
int main()
{
	long n1,n2,i,t,x=0;
	while(cin>>n1>>n2&&(n1!=0||n2!=0))
	{
		t=0;
		for(i=0;i<10;i++)
		{
			if(n1%10+n2%10+x>=10)
			{
				t++;
				x=1;
			}
			else
				x=0;
			n1=n1/10;
			n2=n2/10;
		}
		if(t==0)
			cout<<"No carry operation.\n";
		else if(t==1)
			cout<<"1 carry operation.\n";
		else 
			cout<<t<<" carry operations.\n";
	}
	return 0;
}

		