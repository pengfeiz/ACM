#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;
long num[10050],num2[10050];
int main()
{
	long nn,n,i,t;
	cin>>nn;
	while(nn-->0)
	{
		cin>>n;
		t=0;
		num[0]=0;
		for(i=1;i<=n;i++)
		{
			cin>>num[i];
			num2[num[i]]=i;
		}
		for(i=1;i<=n;i++)
			if(num[i]!=i)
			{
				t++;
				num2[num[i]]=num2[i];
				swap(num[num2[i]],num[i]);
				num2[i]=i;
			}
		cout<<t<<endl;
	}
	return 0;
}
