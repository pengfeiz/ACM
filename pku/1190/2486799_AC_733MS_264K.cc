#include<iostream>
using namespace std;

int n,m,ans;

void dfs(int r,int h,int x,int v,int s)
{
	int i,j,l;
	if(s>ans)
		return;
	s+=2*r*h;
	v-=r*r*h;
	if(x==m)
	{
		if(v==0&&s<ans)
			ans=s;
		return;
	}
	if(v<=0)
		return;
    l=m-x;
	if(l*r*r*h<v)
		return;
	x++;
	for(i=l;i<r;i++)
		for(j=l;j<h;j++)
			dfs(i,j,x,v,s);	
}

int main()
{
	long i,j;
	scanf("%d%d",&n,&m);
	ans=999999;	
	for(i=m;i<=25;i++)
		for(j=m;j<=25;j++)
			dfs(i,j,1,n,i*i);
	printf("%d\n",ans);
	return 0;
}