#include<iostream>
using namespace std;
int n,m,ans;
void dfs(int r,int h,int x,int v,int s)
{
	if(s>ans)
		return;
	int i,j,l;
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
	x++;
	if(l*r*r*h<v)
		return;
	for(i=r-1;i>=l;i--)
		for(j=h-1;j>=l;j--)
			dfs(i,j,x,v,s);	
}
int main()
{
	long i,j;
	scanf("%d%d",&n,&m);
	ans=999999;	
	for(i=25;i>=m;i--)
		for(j=25;j>=m;j--)
			dfs(i,j,1,n,i*i);
	printf("%d\n",ans);
	return 0;
}