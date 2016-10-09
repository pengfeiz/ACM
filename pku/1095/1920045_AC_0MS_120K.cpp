#include <iostream>
using namespace std;
int num[20]={-1,0,1,3,8,22,64,196,625,2055,6917,23713,82499,290511,1033411,3707851,13402696,48760366,178405156,656043856};
int no[20] = {1,1,2,5,14,42,132,429, 1430,4862,16796,58786,208012,742900,2674440,9694845,35357670,129644790,477638700}; 
void disp(int n)
{
	int i,j,t=n,l,r,ll,rr;
	for(i=0;i<20;i++)
	{
		if(no[i]>t)
			break;
		t-=no[i];
	}
	for(j=0;j<i;j++)
	{
		if(t<no[j]*no[i-1-j])
			break;
		t-=no[j]*no[i-1-j];		
	}
	l=j;
	r=i-1-j;
	ll=t/no[r]+num[l]+1;
	rr=t%no[r]+num[r]+1;
	if(ll!=0)
	{
		cout<<"(";
		disp(ll);
		cout<<")";
	}
	cout<<"X";
	if(rr!=0)
	{
		cout<<"(";
		disp(rr);
		cout<<")";
	}
}

int main()
{
	int n;
	while(cin>>n&&n!=0)
	{
		disp(n);
		cout<<endl;
	}
	return 0;
}

		