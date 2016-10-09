#include <iostream>
#include <math.h>
using namespace std;
long num[10];
int main()
{
	long n,i,m,q;
	num[0]=0;
	for(i=1;i<10;i++)
		num[i]=num[i-1]*9+(long)pow(10,(double)(i-1));
	while(cin>>n&&n!=0)
	{
		q=n;
		m=0;
		for(i=1;i<10;i++)
		{
			if(n%10>4)
			{
				m+=(long)pow(10,(double)i-1);
				m+=(n%10-1)*num[i-1];
			}
			else
				m+=n%10*num[i-1];
			n=n/10;
		}
		cout<<q<<": "<<q-m<<endl;
	}
	return 0;
}

