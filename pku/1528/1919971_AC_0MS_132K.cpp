#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int n,tt,i,j;
	cout<<"PERFECTION OUTPUT\n";
	while(cin>>n&&n!=0)
	{
		tt=0;
		for(i=1;i<=n/2;i++)
			if(n%i==0)
				tt+=i;
		j=0;
		while(1)
		{
			if(n/(long)pow(10,(double)j)==0)
				break;
			j++;
		}
		for(i=0;i<5-j;i++)
			cout<<" ";
		cout<<n<<"  ";
		if(tt<n)
			cout<<"DEFICIENT\n";
		else if(tt==n)
			cout<<"PERFECT\n";
		else
			cout<<"ABUNDANT\n";
	}
	cout<<"END OF OUTPUT\n";
	return 0;
}
