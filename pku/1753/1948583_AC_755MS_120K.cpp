#include <iostream>
using namespace std;
int judge(int p[16],int b[16])
{
	int i;
	for(i=0;i<16;i++)
	{
		if(p[i]==1)
		{
			if(i>3)
				b[i-4]=(b[i-4]+1)%2;
			if(i<12)
				b[i+4]=(b[i+4]+1)%2;
			if(i%4>0)
				b[i-1]=(b[i-1]+1)%2;
			if(i%4<3)
				b[i+1]=(b[i+1]+1)%2;
			b[i]=(b[i]+1)%2;
		}
	}
	for(i=0;i<15;i++)
		if(b[i]!=b[i+1])
			return 1;
	return 0;
}
int main()
{
	int a[16],b[16],i,t,p[16],max=17;
	long n,q;
	char c;
	for(i=0;i<16;i++)
	{
		cin>>c;
		if(c=='w')
			a[i]=0;
		else
			a[i]=1;
	}
	for(n=0;n<65536;n++)
	{
		for(i=0;i<16;i++)
			b[i]=a[i];
		q=n;
		t=0;
		for(i=0;i<16;i++)
		{
			if(q%2==0)
				p[i]=0;
			else
			{
				p[i]=1;
				t++;
			}
			q/=2;
		}
		if(judge(p,b)==0)
			if(t<max)
				max=t;
	}
	if(max==17)
		cout<<"Impossible\n";
	else
		cout<<max<<endl;
		system("PAUSE");
	return 0;
}


		
