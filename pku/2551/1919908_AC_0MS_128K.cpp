#include <iostream>
#define MAX 100000;
using namespace std;
int dosth(int n)
{
	int i,m=0;
	i=1;
	while(1)
	{
		m=(1+10*m)%n;
		if(m==0)
			return i;
		else
			i++;
	}
}
int main()
{
	int n;
	while(cin>>n&&n%2!=0&&n%5!=0)
	{
		cout<<dosth(n)<<endl;
	}
	return 0;
}


