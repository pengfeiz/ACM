#include<iostream>
#include<cmath>
#define dis(a,b) (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)
using namespace std;
const double eps=1e-6;
struct Point{
	double x,y;
}p[350];

int main() {
	int n,i,j,k,cnt,best;
	double x,y,r,t;
	Point c;
	while(scanf("%d",&n)!=EOF&&n) {
		for(i=0;i<n;i++)
			scanf("%lf%lf",&p[i].x,&p[i].y);
		best=1;
		for(i=0;i+1<n;i++)
			for(j=i+1;j<n;j++) 
				if(dis(p[i],p[j])<4||fabs(dis(p[i],p[j])-4)<eps){
				x=(p[i].x+p[j].x)/2,y=(p[i].y+p[j].y)/2;
				r=sqrt(dis(p[i],p[j]));
				t=sqrt(1-r*r/4);
				c.x=x-t*(p[j].y-p[i].y)/r,
				c.y=y+t*(p[j].x-p[i].x)/r;
				for(k=0,cnt=0;k<n;k++)
					if((dis(p[k],c)<1||fabs(dis(p[k],c)-1)<eps)&&
					fabs(p[k].x-c.x)>eps&&fabs(p[k].y-c.y)>eps)
						cnt++;
				if(best<cnt) best=cnt;
			}
		printf("%d\n",best);
	}
	return 0;
}