#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
int hehe(const void *a, const void *b)
{
	return *(long *)b-*(long *)a;
}
int main()
{
	long tt,n,nn,f,i,j,num[10000];
	cin>>nn;
	for(j=1;j<=nn;j++)
	{
		if(j-1)
			cout<<endl;
		cout<<"Scenario #"<<j<<":\n";
		cin>>n>>f;
		for(i=0;i<f;i++)
			scanf("%ld",&num[i]);
		qsort(num,f,sizeof(long),hehe);
		tt=0;
		for(i=0;i<f;i++)
		{
			tt+=num[i];
			if(tt>=n)
				break;
		}
		if(i==f)
			cout<<"impossible\n";
		else
			cout<<i+1<<endl;
	}
	return 0;
}
