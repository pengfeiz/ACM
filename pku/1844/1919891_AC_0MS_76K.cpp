#include<iostream.h>
void main()
{
	int s=0,i,n;
	cin>>n;
	for(i=1;s<n||(s-n)%2==1;i++)
		s+=i;
	cout<<i-1<<endl;
}
