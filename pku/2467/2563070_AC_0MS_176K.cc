#include <stdio.h>
#include <math.h>

int main()
{
	double d=0;
	int x,xx,y,yy,t;
	scanf("%*d%*d");
	while(scanf("%d%d%d%d",&x,&y,&xx,&yy)!=EOF)
	//计算三角形斜边长度 hypot(x,y)
		d+=hypot(x-xx,y-yy);
	t=(int)(d/1000*2/20*60+0.5); 
	printf("%d:%0.2d\n",t/60,t%60);
	return 0;
}