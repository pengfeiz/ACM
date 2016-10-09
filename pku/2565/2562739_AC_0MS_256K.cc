#include <iostream>
#include <math.h>
using namespace std;

int main ()
{
	int n,t,i,tt,hh,mm,ss,average;
	double d;
	bool f;
	char s[20];
	scanf("%d%lf",&n,&d);
	while(scanf("%d",&t)!=EOF)
	{
		printf("%3d: ",t);
		f=false;
		tt=0;
		for(i=0;i<n;i++)
		{
			scanf("%s",s);
			if(sscanf(s,"%d:%d:%d",&hh,&mm,&ss)!=3)
				f=true;
			else
				tt+=3600*hh+60*mm+ss;
		}
		average=(int)(floor(tt/d+0.5));
		if(f)
			printf("-\n");
		else
			printf("%d:%02d min/km\n",average/60,average%60);
	}
	return 0;
}
