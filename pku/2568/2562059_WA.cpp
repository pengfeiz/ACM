#include <iostream>
using namespace std;

const int maxn=101;


int a[maxn],n,m;
int d[maxn];

bool c[maxn];
bool b[maxn][maxn];


void solve()
{
	int i,j;
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	for(i=0;i<n;i++)
	{
		for(j=1;j<=m;j++)
			if(d[j]==0)
				break;
		b[j][a[i]]=b[a[i]][j]=true;
		d[j]--;
		d[a[i]]--;
	}
}


void out(int x)
{
	int i;
	printf("(%d",x);
	c[x]=true;
	for(i=1;i<=m;i++)
		if(b[x][i]&&!c[i])
		{
			printf(" ");
			out(i);
		}
	printf(")");
}


int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	char cc,ss[5];
	while(scanf("s",ss)!=EOF)
	{
		if(strcmp(ss,"")==0)
		{
			printf("(1)\n");
			continue;
		}
		memset(d,0,sizeof(d));
		a[0]=atoi(ss);
		d[a[0]]++;
		n=1;
		while((cc=getchar())!='\n'&&cc!=EOF)
		{
			scanf("%d",&a[n]);
			d[a[n]]++;
			n++;
		}
		m=n+1;
		solve();
		out(a[n-1]);
		printf("\n");
	}
	return 0;
}