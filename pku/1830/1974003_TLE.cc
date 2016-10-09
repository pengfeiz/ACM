#include <iostream>
using namespace std;
int a[29],n,b[29],q[29][29],w[29][29],t;
void dosth(int i)
{
	int j,tt=0;
	if(i==n)
	{
		for(i=0;i<n;i++)
			if((a[i]+b[i])%2!=0)
				return;
		t++;
		return;
	}
	else
	{
		dosth(i+1);
		a[i]++;
		for(j=0;j<n;j++)
		{
			a[j]+=q[i][j];
			if((a[j]+b[j])%2==1&&w[i][j]==0)
				tt=1;
		}
		if(tt==0)
			dosth(i+1);
		a[i]--;
		for(j=0;j<n;j++)
			a[j]-=q[i][j];
	}
}
int main()
{
	int nn,i,f,j,g;
	cin>>nn;
	while(nn-->0)
	{
		t=0;
		cin>>n;
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=0;i<n;i++)
			scanf("%d",&b[i]);
		memset(q,0,29*29);
		memset(w,0,29*29);
		while(scanf("%d%d",&f,&g)&&(f||g))
			q[f-1][g-1]=1;
		for(j=0;j<n;j++)
			w[n-1][j]=q[n-1][j];
		for(i=n-1;i>0;i--)
			for(j=0;j<n;j++)
				w[i-1][j]=w[i][j]+q[i-1][j];
		dosth(0);
		if(t)
			cout<<t<<endl;
		else
			cout<<"Oh,it's impossible~!!\n";
	}
	return 0;
}
	