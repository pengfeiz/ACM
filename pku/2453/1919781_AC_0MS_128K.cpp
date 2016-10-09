#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	long n,i,j,tt,t,num[30];
	while(cin>>n&&n!=0)
	{
		t=0;
		while(n>0)
		{
			num[t]=n%2;
			n/=2;
			t++;
		}
		num[t]=0;
		t++;
		tt=0;
		for(i=0;i<t;i++)
		{
			if(num[i]==1&&tt==0)
				tt=1;
			if(tt==1&&num[i]==0)
				break;
		}
		num[i]=1;
		n=0;
		for(j=t-1;j>=i;j--)
			n+=(long)pow(2,double(j))*num[j];
		for(j=tt=0;j<i;j++)
			if(num[j]==1)
				tt++;
		for(i=0;i<tt-1;i++)
			n+=(long)pow(2,double(i));
		cout<<n<<endl;
	}
	return 0;
}