#include <iostream>
using namespace std;
int main()
{
	long a[100000],n,k,i,b[10000],t,tt,j;
	cin>>n>>k;
	t=0;
	tt=1;
	for(i=0;i<n;i++)
		scanf("%ld",&a[i]);
	for(i=0;i<k;i++)
		b[i]=0;
	for(i=0;i<n;i++)
	{
		if(b[a[i]-1]==0)
		{
			b[a[i]-1]=1;
			t++;
		}
		if(t==k)
		{
			for(j=0;j<k;j++)
				b[j]=0;
			t=0;
			tt++;
		}
	}
	cout<<tt<<endl;
	return 0;
}

