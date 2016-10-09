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
			if(!d[j])
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
	int i,j;
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	char cc;
	while(scanf("%d",&a[0])!=EOF)
	{
		memset(d,0,sizeof(d));
		m=a[0];
		d[m]++;
		n=1;
		while((cc=getchar())!='\n'&&cc!=EOF)
		{
			scanf("%d",&a[n]);
			d[a[n]]++;
			if(m<a[n])
				m=a[n];
			n++;
		}
		j=1;
		for(i=1;i<=m;i++)
			if(d[i]>d[j])
				j=i;
		solve();
		out(j);
		printf("\n");
	}
	return 0;
}



