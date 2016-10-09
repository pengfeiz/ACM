#include <iostream>
using namespace std;
long a[32];
int main()
{
	long n,j,i;
	while(cin>>n)
	{
		j=0;
		memset(a,0,sizeof(long)*32);
		if(n==0)
			cout<<0<<endl;
		else if(n>0)
		{
			while(n>3)
			{
				if(n%4==1)
				{
					a[j]=1;
					a[j+1]=0;
					n=n/4;
				}
				else if(n%4==2)
				{
					a[j]=0;
					a[j+1]=1;
					n=(n+2)/4;
				}
				else if(n%4==3)
				{
					a[j]=1;
					a[j+1]=1;
					n=(n+1)/4;
				}
				else if(n%4==0)
				{
					a[j]=0;
					a[j+1]=0;
					n/=4;
				}
				j+=2;
			}
			if(n==1)
			{
				a[j]=1;
				j+=1;
			}
			else if(n==2)
			{
				a[j]=0;
				a[j+1]=1;
				a[j+2]=1;
				j+=3;
			}
			else if(n==3)
			{
				a[j]=1;
				a[j+1]=1;
				a[j+2]=1;
				j+=3;
			}
			for(i=j-1;i>=0;i--)
				cout<<a[i];
			cout<<endl;
		}
		if(n<0)
		{
			while(n<-3)
			{
				if(n%4==-1)
				{
					a[j]=1;
					a[j+1]=1;
					n=(n+1)/4;
				}
				else if(n%4==-2)
				{
					a[j]=0;
					a[j+1]=1;
					n=(n+2)/4;
				}
				else if(n%4==-3)
				{
					a[j]=1;
					a[j+1]=0;
					n=(n-1)/4;
				}
				else if(n%4==0)
				{
					a[j]=0;
					a[j+1]=0;
					n/=4;
				}
				j+=2;
			}
			if(n==-1)
			{
				a[j]=1;
				a[j+1]=1;
				j+=2;
			}
			else if(n==-2)
			{
				a[j]=0;
				a[j+1]=1;
				j+=2;
			}
			else if(n==-3)
			{
				a[j]=1;
				a[j+1]=0;
				a[j+2]=1;
				a[j+3]=1;
				j+=4;
			}
			for(i=j-1;i>=0;i--)
				cout<<a[i];
			cout<<endl;
		}	
	}
	return 0;
}


