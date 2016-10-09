#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;
int main()
{
	double r,x,y,x2,y2,t1,t2;
	while(cin>>r&&r!=-1)
	{
		t1=t2=-1;
		cin>>x>>y>>x2>>y2;
		x2-=x;
		y2-=y;
		if(fabs(y2)>fabs(x2))
		{
			if(y2>0)
				t1=0;
			else
				t1=2;
		}
		else if(fabs(y2)<fabs(x2))
		{
			if(x2>0)
				t1=1;
			else
				t1=3;
		}
		if(y2>0&&x2>0)
			t2=0;
		else if(y2<0&&x2>0)
			t2=1;
		else if(y2<0&&x2<0)
			t2=2;
		else if(y2>0&&x2<0)
			t2=3;
		if(t1==0)
		{
			if((y+y2)*(y+y2)+x*x<=r*r)
			{
				printf("north %.10lf\n",fabs(fabs(y2)-fabs(x2)));
				if(t2==0)
					printf("northeast %.10lf\n",fabs(x2)*pow(2,0.5));
				else if(t2==3)
					printf("northwest %.10lf\n",fabs(x2)*pow(2,0.5));
			}
		}
		else if(t1==1)
		{
			if((x+x2)*(x+x2)+y*y<=r*r)
			{
				printf("east %.10lf\n",fabs(fabs(y2)-fabs(x2)));
				if(t2==0)
					printf("northeast %.10lf\n",fabs(y2)*pow(2,0.5));
				else if(t2==1)
					printf("southeast %.10lf\n",fabs(y2)*pow(2,0.5));
			}
		}
		else if(t1==2)
		{
			if((y+y2)*(y+y2)+x*x<=r*r)
			{
				printf("south %.10lf\n",fabs(fabs(y2)-fabs(x2)));
				if(t2==1)
					printf("southeast %.10lf\n",fabs(x2)*pow(2,0.5));
				else if(t2==2)
					printf("southwest %.10lf\n",fabs(x2)*pow(2,0.5));
			}
		}
		else if(t1==3)
		{
			if((x+x2)*(x+x2)+y*y<=r*r)
			{
				printf("west %.10lf\n",fabs(fabs(y2)-fabs(x2)));
				if(t2==2)
					printf("southwest %.10lf\n",fabs(y2)*pow(2,0.5));
				else if(t2==1)
					printf("southeast %.10lf\n",fabs(y2)*pow(2,0.5));
			}
		}
		else 
		{
			if(t2==0)
				printf("northeast %.10lf\n",fabs(y2)*pow(2,0.5));
			else if(t2==1)
				printf("southeast %.10lf\n",fabs(y2)*pow(2,0.5));
			else if(t2==2)
				printf("southwest %.10lf\n",fabs(x2)*pow(2,0.5));
			else if(t2==3)
				printf("northwest %.10lf\n",fabs(x2)*pow(2,0.5));
		}
		cout<<endl;
	}
	return 0;
}
			

		




