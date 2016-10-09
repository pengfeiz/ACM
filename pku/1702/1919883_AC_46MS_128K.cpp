#include <iostream>
#include <math.h>
using namespace std;
long num[21],np[21];
int main()
{
	long nn,n,i,j,k1,k2;
	cin>>nn;
	for(i=0;i<21;i++)
		num[i]=pow(3,double(i-1));
	while(nn-->0)
	{
		cin>>n;
		j=0;
		while(n>0)
		{
			j++;
			if(n%3==2)
			{
				np[j]=-1;
				n++;
			}
			else if(n%3==1)
				np[j]=1;
			else
				np[j]=0;
			n/=3;
		}
		for(i=k1=k2=0;i<=j;i++)
		{
			if(np[i]==-1)
				k1=i;
			else if(np[i]==1)
				k2=i;
		}
		if(k1==0)
			cout<<"empty";
		else
		{
			i=0;
			while(i<k1)
			{
				i++;
				if(np[i]==-1)
				{
					cout<<num[i];
					if(i-k1)
						cout<<",";
				}
			}
		}
		cout<<" ";
		if(k2==0)
			cout<<"empty";
		else
		{
			i=0;
			while(i<k2)
			{
				i++;
				if(np[i]==1)
				{
					cout<<num[i];
					if(i-k2)
						cout<<",";
				}
			}
		}
		cout<<endl;
	}
	return 0;
}


