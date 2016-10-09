#include<cstdio>
#include<algorithm>
#include<cmath>
const int mn=100001;
struct pt
{
	double x,y;
}a[mn];
int s[mn],n,sp;
bool u[mn];

bool cmp(const pt& a,const pt& b)
{
	if(a.y!=b.y)return a.y<b.y;
	return a.x<b.x;
}

double cross(pt& p1,pt& p2,pt& p3)
{
	return (p2.x-p1.x)*(p3.y-p2.y)-(p3.x-p2.x)*(p2.y-p1.y);
}
double dis(pt& p1,pt& p2)
{
	double dx=p1.x-p2.x,dy=p1.y-p2.y;
	return dx*dx+dy*dy;
}

bool init()
{
	scanf("%d",&n);
	if(n==0)
		return false;
	for(int i=1;i<=n;i++)
	{
		scanf("%lf%lf",&a[i].x,&a[i].y);
		u[i]=0;
	}
	std::sort(a+1,a+1+n,cmp);
	return true;
}
void graham_scan()
{
	int i;
	s[1]=1,s[2]=2,u[2]=1,sp=2;
	for(i=3;i<=n;i++)
	{
		while(sp>1 && cross(a[s[sp-1]],a[s[sp]],a[i])>=0)u[s[sp--]]=0;
		s[++sp]=i,u[i]=1;
	}
	for(i=n;i>=1;i--)
		if(!u[i])
		{
			while(cross(a[s[sp-1]],a[s[sp]],a[i])>=0)u[s[sp--]]=0;
			s[++sp]=i,u[i]=1;
		}
}

void findmax()
{
	double maxd=0,d1,d2;
	int i,j;
	for(i=1,j=1;i<=sp;i++)
	{
		d1=dis(a[s[i]],a[s[j]]);
		while(1)
		{
			d2=dis(a[s[i]],a[s[j%sp+1]]);
			if(d1<d2)
			{
				j=j%sp+1;
				d1=d2;
			}
			else
				break;
		}
		if(maxd<d1)
			maxd=d1;
	}
	printf("%.2lf\n",sqrt(maxd));
}

int main()
{
//	freopen("in.txt","r",stdin);
	while(init())
	{
		graham_scan();
		findmax();
	}
	return 0;
}
