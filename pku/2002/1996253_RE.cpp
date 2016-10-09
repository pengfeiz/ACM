#include <iostream>
#include <math.h>
#include <algorithm>  
using namespace std;
int a[1010][2],t;
float c[1010][1010];
struct gao
{
	float l;
	float k;
	int first;
	int last;
	int id;
}b[500010];
bool less(gao x,gao y)
{
	return x.l>y.l;
}
bool judge(gao x,gao y)
{
	float aa,bb,cc,dd;
	aa=c[x.first][y.last];
	bb=c[x.last][y.last];
	cc=c[x.first][y.first];
	dd=c[x.last][y.first];
	if(aa!=bb||aa!=cc||aa!=dd)
		return false;
	return true;
}
int main()
{
	int n,i,j,k,tt,p;
	while(cin>>n&&n)
	{
		t=tt=0;
		memset(a,0,sizeof(a));
		memset(c,0,sizeof(c));
		for(i=0;i<n;i++)
			scanf("%d%d",&a[i][0],&a[i][1]);
		for(i=0;i<n-1;i++)
			for(j=i+1;j<n;j++)
			{
				b[t].l=sqrt(pow(a[i][1]-a[j][1],2)+pow(a[i][0]-a[j][0],2));
				c[i][j]=c[j][i]=b[t].l;
				if(a[j][0]!=a[i][0])
					b[t].k=(a[j][1]-a[i][1])*1.0/((a[j][0]-a[i][0])*1.0);
				else
					b[t].k=999999;
				b[t].first=i;				
				b[t].last=j;
				b[t].id=0;
				t++;
			}
		sort(b,b+t*sizeof(gao),less);
		b[t].l=98712;
		for(i=0;i<t;i++)
		{
			if(b[i].id==1)
				continue;
			b[i].id=1;
			k=i;
			while(b[k].l==b[k+1].l)
				k++;
			for(p=i+1;p<=k;p++)
			{
				if(fabs(b[i].k*b[p].k+1)<1e-5||(b[i].k==0&&b[p].k==999999)||(b[p].k==0&&b[i].k==999999))
					if(judge(b[i],b[p]))
					{
						b[p].id=1;
						tt++;
						break;
					}
			}
		}
		cout<<tt<<endl;
	}
	return 0;
}
