#include <iostream>
using namespace std;
int main()
{
	int t,n,m;
	float p,q;
	cin>>t;
	while(t>0)
	{
		t--;
		cin>>m>>n;
		if(n>m)
			cout<<"impossible\n";
		else
		{
			q=m+n;
			q=q/2;
			p=(m-n)/2;
			if((n=q*10)%10!=0)
				cout<<"impossible\n";
			else
				cout<<q<<" "<<p<<endl;
		}
	}
	return 0;
}

	