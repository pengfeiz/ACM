#include <iostream>
using namespace std;

bool a[24][24];
bool b[24][24];
int c[24];
bool f[24];

int main()
{
//	freopen("in.txt","r",stdin);
	int n,m,N,M,i,j,k,x,xx,y,tt,t;
	char s[24];
	for(i=0;i<24;i++)
		c[i]=1<<i;
//	while(scanf("%d%d",&n,&m)!=EOF){
	scanf("%d%d",&n,&m);
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	for(i=0;i<n;i++)
	{
		scanf("%s",s);
		for(j=0;j<m;j++)
		{
			if(s[j]=='1')
				a[i][j]=true;
		}
	}
	scanf("%d%d",&N,&M);
	for(i=0;i<N;i++)
	{
		scanf("%s",s);
		for(j=0;j<M;j++)
		{
			if(s[j]=='1')
				b[i][j]=true;
		}
	}
	tt=N-n;
	x=1<<N;
	for(k=0;k<x;k++)
	{
		t=0;
		memset(f,0,sizeof(f));
		for(i=0;i<N;i++)
		{
			if(k&c[i])
			{
				f[i]=true;
				t++;
			}
		}
		if(t!=tt)
			continue;
		for(i=j=0;i<m&&j<M;)
		{
			for(xx=y=0;xx<n&&y<N;xx++,y++)
			{
				while(f[y])
					y++;
				if(a[i][xx]^b[j][y])
					break;
			}
			if(xx<n)
				j++;
			else
			{
				i++;
				j++;
			}
		}
		if(i==m)
			break;
	}
	if(k<x)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}
