#include <iostream>
using namespace std;
unsigned long num[46];
int main()
{
	unsigned long nn,n,i,time=0;
	num[0]=1;
	num[1]=2;
	num[2]=3;
	for(i=3;i<46;i++)
		num[i]=num[i-1]+num[i-2];
	cin>>nn;
	while(nn-->0)
	{
		cin>>n;
		time++;
		if(time-1)
			cout<<endl;
		cout<<"Scenario #"<<time<<":\n"<<num[n]<<endl;
	}
	return 0;
}