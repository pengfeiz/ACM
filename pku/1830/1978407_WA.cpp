#include <iostream>
using namespace std;
int a[29],b[29],q[29][29],w[29][2],n;
int cc(int a,int b)
{
	int i,t;
	if(a>=b/2)
		a=b-a;
	t=1;
	for(i=1;i<=a;i++)
		t=t*(b-i+1)/i;
	return t;
}
int dosth(int x,int f)
{
	int t=0,i,p=0;
	if(x==f)
	{
		for(i=0;i<n;i++)
			if((a[i]+b[i])%2==1)
				return 0;
		return 1;
	}
	p+=dosth(x+1,f);
	for(i=0;i<n;i++)
		a[i]+=q[x][i];
	for(i=1;i<=w[x][1];i+=2)
		t+=cc(i,w[x][1]);
	p+=t*dosth(x+1,f);
	for(i=0;i<n;i++)
		a[i]-=q[x][i];
	return p;
}
int main()
{
	int nn,i,f,j,g,tt;
	cin>>nn;
	while(nn-->0)
	{
		cin>>n;
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=0;i<n;i++)
			scanf("%d",&b[i]);
		memset(q,0,29*29);
		while(scanf("%d%d",&f,&g)&&(f||g))
			q[f-1][g-1]=1;
		for(j=0;j<n;j++)
			q[j][j]=1;
		f=1;
		w[0][0]=0;
		w[0][1]=1;
		for(g=1;g<n;g++)
		{
			for(i=0;i<f;i++)
			{
				for(j=0;j<n;j++)
					if(q[g][j]!=q[i][j])
						break;
				if(j<29)
					break;
			}
			if(i==f)
			{
				w[f][0]=g;
				w[f][1]=1;
				f++;
			}
			else
				w[i][1]++;
		}
		tt=dosth(0,f);
		if(tt)
			cout<<tt<<endl;
		else
			cout<<"Oh,it's impossible~!!\n";
	}
	return 0;
}
	