#include <iostream>
#include <math.h>
using namespace std;
#define pi 3.14159265
int main()
{
	double x[3],y[3],r;
	int n,i,t;
	cin>>n;
	while(n-->0)
	{
		t=0;
		cin>>r;
		for(i=0;i<3;i++)
		{
			cin>>x[i]>>y[i];
			if(x[i]*x[i]+y[i]*y[i]>r*r)
				t=3;
			if(x[i]==0&&y[i]==0)
				t=3;
		}
		if(x[0]==x[1]&&y[0]==y[1])
			t=3;
		if(x[1]==x[2]&&y[1]==y[2])
			t=3;
		if(x[0]==x[2]&&y[0]==y[2])
			t=3;
		for(i=0;i<3;i++)
		{
			r=sqrt(x[i]*x[i]+y[i]*y[i]);
			x[i]/=r;
			y[i]/=r;
		}
		if(t==0)
		{
			for(i=0;i<3;i++)
				if(sqrt((y[i]-y[(i+1)%3])*(y[i]-y[(i+1)%3])+(x[i]-x[(i+1)%3])*(x[i]-x[(i+1)%3]))<sqrt(3))
					t++;
		}
		if(t==3)
			cout<<"No\n";
		else
			cout<<"Yes\n";
	}
	return 0;
}

		

