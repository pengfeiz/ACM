#include <iostream>
using namespace std;


struct gao
{
	int b[54];
	long n;
}c[51][12][12][21];

struct gao2
{
	int x,y;
}z[4]={1,0,0,1,-1,0,0,-1};



bool p[51][12][12][21];
int a[12][12];
int n,m,s,e;


bool dosth(gao &a,gao &b,int l,int q)
{
	int i;
	bool f=false;
	for(i=1;i<l;i++)
	{
		if(a.b[i]>b.b[i])
			break;
		else if(a.b[i]<b.b[i])
		{
			f=true;
			break;
		}
	}
	if(i==l)
	{
		a.n+=b.n;
		return true;
	}
	if(!f||a.b[l]>q)
	{
		for(i=1;i<l;i++)
			a.b[i]=b.b[i];
		a.b[l]=q;
		a.n=b.n;
		return true;
	} 
	return false;

}



int main()
{
	freopen("in.txt","r",stdin);
	int tt,i,j,tim=0,x,y,ww,q,l,k;
	int bb[54];
	long ll;
	scanf("%d",&tt);
	while(tt--)
	{
		tim++;
		scanf("%d%d%d%d",&n,&m,&s,&e);
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
				scanf("%d",&a[i][j]);
			memset(p,0,sizeof(p));
			memset(c,127,sizeof(c));
			for(i=1;i<=n;i++)
				for(j=1;j<=m;j++)
				{
					p[1][i][j][a[i][j]%e]=true;
					c[1][i][j][a[i][j]%e].b[1]=a[i][j];
					c[1][i][j][a[i][j]%e].n=1;
				}

			for(k=2;k<=s;k++)
			{
				for(i=1;i<=n;i++)
					for(j=1;j<=m;j++)
					{
						for(l=0;l<e;l++)
						{
							if(!p[k-1][i][j][l])
								continue;
							for(ww=0;ww<4;ww++)
							{
								x=i+z[ww].x;
								y=j+z[ww].y;
								if(x<=0||y<=0||x>n||y>m)
									continue;
								q=(l*10+a[x][y])%e;
								if(dosth(c[k][x][y][q],c[k-1][i][j][l],k,a[x][y]))
									p[k][x][y][q]=true;
							}
						}
					}
			}
			memset(bb,127,sizeof(bb));
			ll=0;
			for(i=1;i<=n;i++)
				for(j=1;j<=m;j++)
				{
					if(!p[s][i][j][0])
						continue;
					ww=0;
					for(k=1;k<=s;k++)
					{
						if(bb[k]>c[s][i][j][0].b[k])
						{
							ww=1;
							break;
						}
						if(bb[k]<c[s][i][j][0].b[k])
							break;
					}
					if(k<=s&&ww)
					{
						ll=c[s][i][j][0].n;
						for(k=1;k<=s;k++)
							bb[k]=c[s][i][j][0].b[k];
					}
					else if(k>s)
						ll+=c[s][i][j][0].n;
				}
		printf("Case %d: ",tim);
		if(ll)
		{
			ww=0;
			for(i=1;i<=s;i++)
			{
				if(!ww&&bb[i]==0)
					continue;
				if(bb[i])
					ww=1;
				printf("%d",bb[i]);
			}
			if(!ww)
				printf("0");
			printf(" %lld\n",ll);
		}
		else
		{
			printf("-1 -1\n");
		}
	}

	return 0;
}
