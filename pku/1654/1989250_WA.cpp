#include<stdio.h>
#include<iostream.h>
#include<math.h>

void main()
{
	int time;
	cin>>time;
	__int64 result[99];
	char a;
	int x=0;
	int y=0;
	int j=0;
	int dx=0;
	int dy=0;
	__int64 area1=0;
	for(int i=0;i<time;i++)
	{
		while(1)
		{
			
			cin>>a;
			if(a=='5') break;
			switch(a)
			{
				case'9':dx=1;  dy=1;break;
				case'6':dx=1;  dy=0;break;
				case'3':dx=1; dy=-1;break;
				case'2':dx=0; dy=-1;break;
				case'1':dx=-1;dy=-1;break;
				case'4':dx=-1; dy=0;break;
				case'7':dx=-1; dy=1;break;
				case'8':dy=0;  dx=1;break;
				case'5':break;
				default:break;
			}
			area1 += x*(y+dy)-y*(x+dx);
			x=x+dx;
			y=y+dy;
		}
			if((x==0)&&(y==0))
			{
				result[i]=((area1>0) ? area1:-1*area1);
				area1=0;
				x=0,dx=0;
				y=0,dy=0;
			}
			else
			{
				result[i]=0;
				area1=0;
				x=0,dx=0;
				y=0,dy=0;
			}
		
	}
	for(int p=0;p<time;p++)
	{
		if(result[p]%2)
		{
			printf("%d",result[p]/2);
			cout<<".5"<<endl;
		}
		else
			printf("%d\n",result[p]/2);			

	}
}
