#include <iostream>
using namespace std;
int main()
{
	int a,b,n,i,tt,t;
	while(cin>>n&&n!=0)
	{
		tt=t=0;
		for(i=1;i<=n;i++)
		{
			cin>>a>>b;
			if(a+b>tt)
			{
				tt=a+b;
				t=i;
			}
		}
		if(tt<9)
			cout<<"0\n";
		else
			cout<<t<<endl;
	}
	return 0;
}
