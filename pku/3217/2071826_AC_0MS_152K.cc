#include <iostream>
using namespace std;
struct gao
{
	int a;
	int b;
	int c[2];
}a[101];
bool b[101];
int main()
{
//	freopen("in.txt","r",stdin);
	int x,y,n,i;
	memset(a,0,sizeof(0));
	memset(b,0,sizeof(b));
	scanf("%d%d",&x,&y);
	while(scanf("%d",&n)!=EOF)
	{
		while(scanf("%d",&i)&&(i>0))
		{
			a[i].c[a[i].b]=n;
			a[i].b++;
		}
		a[n].a=i;
	}
	i=0;
	b[x]=1;
	b[a[x].c[0]]=1;
	b[a[x].c[1]]=1;
	b[a[a[x].c[0]].c[0]]=1;
	b[a[a[x].c[0]].c[1]]=1;
	b[a[a[x].c[1]].c[0]]=1;
	b[a[a[x].c[1]].c[1]]=1;
	if(a[x].a==a[y].a)
	{
		printf("same\n");
		return 0;
	}
	b[0]=0;
	if(b[y]==1)
		i=1;
	if(b[a[y].c[0]]==1||b[a[y].c[1]]==1)
		i=1;
	if(b[a[a[y].c[0]].c[0]]==1||b[a[a[y].c[0]].c[1]]==1||b[a[a[y].c[1]].c[0]]==1||b[a[a[y].c[1]].c[1]]==1)
		i=1;
	if(i)
		printf("close\n");
	else
		printf("marriage\n");
	return 0;
}




