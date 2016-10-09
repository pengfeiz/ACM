#include <iostream>
using namespace std;
int main()
{
	int n,d,num[30],l,i;
	while(cin>>n>>d&&!(n==0&&d==0))
	{
		for(i=0;i<30;i++)
			num[i]=0;
		if(n==10)
		{
			num[0]=0;
			num[1]=1;
			l=2;
		}
		else
		{
			num[0]=n;
			l=1;
		}
		if(d==0)
		{
			cout<<"1\n";
			continue;
		}
		while(d-->1)
		{
			for(i=0;i<l;i++)
				num[i]*=n;
			for(i=0;i<l;i++)
			{
				num[i+1]+=num[i]/10;
				num[i]%=10;
			}
			if(num[l]>0)
				l++;
		}
		for(i=l-1;i>=0;i--)
			cout<<num[i];
		cout<<endl;
	}
	return 0;
}