#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	long n,i,m;
	while(cin>>n>>m&&!(n==0&&m==0))
	{
		i=0;
		while((long)pow((double)i,(double)m)<=n)
			i++;
		if((long)pow((double)i,(double)m)==n)
			cout<<i;
		else if((long)pow((double)i,(double)m)-n>n-(long)pow((double)i-1,(double)m))
			cout<<i-1;
		else
			cout<<i;
		cout<<endl;
	}
	return 0;
}