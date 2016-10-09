#include <iostream>
using namespace std;
int main()
{
	int n,i,j,t;
	while(cin>>n&&n)
	{
		cout<<"Printing order for "<<n<<" pages:\n";
		if(n==1)
		{
			cout<<"Sheet 1, front: Blank, 1\n";
			continue;
		}
		if(n%4!=0)
			t=n+4-n%4;
		else
			t=n;
		for(i=1,j=t;i<=t/2;i++,j--)
		{
			if(i%2==1)
			{
				cout<<"Sheet "<<(i+1)/2<<", front: ";
				if(j<=n||i<=n)
				{
					if(j>n)
						cout<<"Blank, ";
					else
						cout<<j<<", ";
					if(i>n)
						cout<<"Blank\n";
					else
						cout<<i<<endl;
				}
			}
			else
			{
				cout<<"Sheet "<<(i+1)/2<<", back : ";
				if(i>n)
					cout<<"Blank, ";
				else
					cout<<i<<", ";
				if(j>n)
					cout<<"Blank\n";
				else
					cout<<j<<endl;
			}
		}
	}
	return 0;
}
				
		