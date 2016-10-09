#include <iostream>
#include <stdlib.h>
using namespace std;
int com(const void *a,const void *b)
{
	return *(long *)a-*(long *)b;
}
int main()
{
	long nn,num[100000],i;
	char c[3];
	cin>>nn;
	i=0;
	while(i<nn)
	{
		cin>>num[i];
		i++;
	}
	qsort(num,nn,sizeof(long),com);
	cin>>c;
	cin>>nn;
	while(nn-->0)
	{
		cin>>i;
		cout<<num[i-1]<<endl;
	}
	return 0;
}

