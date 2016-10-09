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
	for(i=0;i<n;i++)
	{
		for(j=1;j<=m;j++)
			if(!d[j])
				break;
		b[j][a[i]]=b[a[i]][j]=true;
		d[j]--;
		d[a[i]]--;
	}
	memset(c,0,sizeof(c));
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
	char cc;
	while(scanf("%d",&a[0])!=EOF)
	{
		memset(d,0,sizeof(d));
		m=a[0];
		d[m]++;
		n=1;
		while((cc=getchar())!='\n')
		{
			scanf("%d",&a[n++]);
			d[a[n-1]]++;
			if(m<a[n-1])
				m=a[n-1];
		}
		solve();
		out(m);
		printf("\n");
	}
	return 0;
}



