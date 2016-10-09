#include <iostream>
using namespace std;
int a[2000],b[10];
int main()
{
	int n,i,j;
	while(cin>>n&&n)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		a[0]=1;
		a[1]=1;
		j=n;
		while(n>1)
		{
			for(i=1;i<=a[0];i++)
				a[i]*=n;
			for(i=1;i<a[0];i++)
			{
				a[i+1]+=a[i]/10;
				a[i]%=10;
			}
			while(a[a[0]]>9)
			{
				a[a[0]+1]+=a[a[0]]/10;
				a[a[0]]%=10;
				a[0]++;
			}
			n--;
		}
		for(i=1;i<=a[0];i++)
			b[a[i]]++;
		cout<<j<<"! --\n";
		for(i=0;i<10;i++)
		{
			if(i&&i-5)
				cout<<" ";
			cout<<"   ("<<i<<")    "<<b[i];
			if(i==4)
				cout<<endl;
		}
		cout<<endl;
	}
	return 0;
}

