#include <iostream>
#include <cstring>
using namespace std;
char a[1000],b[1000];
int p[2];
void dosth(int n,int m)
{
	int i,t;
	p[0]=n;
	p[1]=m;
	t=n;
	for(i=2;i<=t;i++)
		if(p[0]%i==0&&p[1]%i==0)
		{
			p[0]/=i;
			p[1]/=i;
			i--;
		}
}

int main()
{
	int i,j,t,l1,l2,max;
	while(cin>>a&&strcmp(a,"-1")!=0)
	{
		cin>>b;
		l1=strlen(a);
		l2=strlen(b);
		max=0;
		for(i=0;i<l1;i++)
		{
			t=0;
			for(j=i;j<l1;j++)
				if(a[j]==b[j-i])
					t++;
			if(t>max)
				max=t;
		}
		for(i=0;i<l2;i++)
		{
			t=0;
			for(j=i;j<l2;j++)
				if(b[j]==a[j-i])
					t++;
			if(t>max)
				max=t;
		}
		cout<<"appx("<<a<<","<<b<<") = ";
		if(max==l1&&max==l2)
			cout<<1<<endl;
		else if(max==0)
			cout<<0<<endl;
		else
		{
			dosth(2*max,l1+l2);	
			cout<<p[0]<<"/"<<p[1]<<endl;
		}
	}
	return 0;
}


