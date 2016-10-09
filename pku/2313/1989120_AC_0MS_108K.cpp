#include <iostream>
using namespace std;
int a[100],b[100];
int dosth(int a,int b,int c)
{
	if(a>b)
		swap(a,b);
	if(a>c)
		swap(a,c);
	if(b>c)
		swap(b,c);
	return b;
}
int main()
{
	int n,i,t;
	while(cin>>n)
	{
		for(i=t=0;i<n;i++)
			cin>>a[i];
		b[0]=a[0];
		if(n==1)
		{
			cout<<0<<endl;
			continue;
		}
		for(i=1;i<n-1;i++)
		{
			b[i]=dosth(a[i],b[i-1],a[i+1]);
			t+=abs(a[i]-b[i]);
			t+=abs(b[i]-b[i-1]);
		}
		t+=abs(a[n-1]-b[n-2]);
		cout<<t<<endl;
	}
	return 0;
}