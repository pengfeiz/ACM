#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
int num[200];
int main()
{
	char s[6];
	int n,i,j,k,t,m,l;
	while(cin>>s>>n)
	{
		num[0]=1;
		for(i=1;i<200;i++)
			num[i]=0;
		for(i=0,m=0;i<6;i++)
		{
			if(s[i]=='.')
				t=5-i;
			else
				m=10*m+s[i]-48;
		}
		for(k=0,l=1;k<n;k++)
		{
			for(i=0;i<l;i++)
				num[i]=num[i]*m;
			for(i=0;i<l;i++)
			{
				num[i+1]+=num[i]/10;
				num[i]=num[i]%10;
			}
			while(num[l]>0)
			{
				num[l+1]=num[l]/10;
				num[l]%=10;
				l++;
			}
		}
		t*=n;
		t--;
		for(i=0;i<l;i++)
			if(num[i]!=0)
				break;
		if(t<i)
		{
			for(j=l-1;j>=i;j--)
				cout<<num[j];
			for(j=i-1;j>t;j--)
				cout<<0;
			cout<<endl;
		}
		else if(t>=i)
		{
			for(j=l-1;j>t;j--)
				cout<<num[j];
			cout<<".";
			for(j=t;j>=i;j--)
				cout<<num[j];
			cout<<endl;
		}
	}
	return 0;
}




