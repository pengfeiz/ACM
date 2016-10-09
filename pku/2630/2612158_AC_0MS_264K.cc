#include <iostream>
using namespace std;

const int maxl=1<<25;

int n,m,task,E;
char C[3][3],d[5][5];

const int maxk=30;

int k,ans;
int a[maxk][maxk+1],b[maxk],c[maxk];
int f[maxk];


bool readdata()
{
	scanf("%i%i",&n,&m);
	k=n*m;
	return n||m;
}

void reduce(int x[])
{
	int i;
	for(i=0;i<=k;i++)
		x[i]=((x[i]%2)+2)%2;
}

void gcd(int a[], int b[], int i)
{
	int d;
	while(b[i])
	{
		if(a[i]>b[i])
		{
			for(d=0;d<=k;d++)
				a[d]-=b[d];
			reduce(a);
		}
		else
		{
			for(d=0;d<=k;d++)
				b[d]-=a[d];
			reduce(b);
		}
	}
}

void search(int p,int v)
{
	int i;
	if(ans<=v)
		return;
	if(p ==-1)
	{
		ans=v;
		for(i=0;i<k;i++)
			f[i]=c[i];
		return;
	}
	if(b[p]==-1)
		for(c[p]=0;c[p]<2;c[p]++)
			search(p-1,v+c[p]);
	else
	{
		int t=0;
		for(i=p+1;i<k;i++)
			t+=c[i]*a[b[p]][i];
		for(c[p]=0;c[p]<2;c[p]++)
			if((c[p]*a[b[p]][p]+t)%2==a[b[p]][k])
				search(p-1,v+c[p]);
	}
}

int process()
{
	int i,j,v=0,x,t;
	ans=0xfffffff;
	for(i=0;i<k;i++)
	{
		for(j=v;j < k;j++)
			if(a[j][i])
				break;
		if(j==k)
		{
			b[i]=-1;
			continue;
		}
		b[i]=v;
		if(j!=v)
			for(x=0;x<=k;x++)
				t=a[j][x],a[j][x]=a[v][x],a[v][x]=t;
		for(j=v+1;j<k;j++)
			gcd(a[v],a[j],i);
		++v;
	}
	for(;v<k;++v)
		if(a[v][k])
			break;
	if(v>=k)
		search(k-1,0);
	return ans;
}

void mark(int k)
{
	int x=k/m,y=k%m;
	for(int i=-1;i<=1;++i)
		for(int j=-1;j<=1;++j)
			if(C[i + 1][j + 1] == '*')
			{
				if(x + i < 0 || x + i >= n)continue;
				if(y + j < 0 || y + j >= m)continue;
				if(d[x + i][y + j])
					++E;
				else
					--E;
				d[x + i][y + j] = 1 - d[x + i][y + j];
			}
}

void solve()
{
	int i,j,k=1<< (n * m),ans, z, min = 0;
	memset(a, 0, sizeof(a));
	for(i = 0; i < 3; ++i)
		for(j = 0; j < 3; ++j)
		{
			scanf(" %c", &C[i][j]);
			if(C[i][j] == '*')
			{
				z = -1;
				for(int x = 0; x < n; ++x)for(int y = 0; y < m; ++y)
				{
					++z;
					int dx = x + i - 1;
					int dy = y + j - 1;
					if(dx < 0 || dy < 0 || dx >= n || dy >= m)continue;
					a[dx * m + dy][z] = 1;
				}
			}
		}
	for(i=n*m-1;i>=0;i--)
		a[i][n*m]=1;
	ans=n*m+1;
	min=process();
	printf("Case #%i\n",++task);
	if(min<=n*m)
	{
		for(i=0;i<n*m;i++)
			if(f[i])
				printf("%i ",i+1);
		putchar('\n');
	}
	else
		printf("Impossible.\n");
}

int main()
{
	while(readdata())
		solve();
	return 0;
}
