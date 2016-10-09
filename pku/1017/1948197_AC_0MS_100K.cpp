#include <iostream>
using namespace std;
int main()
{
    int n[6],t,x,y;
	while(scanf("%d%d%d%d%d%d",&n[0],&n[1],&n[2],&n[3],&n[4],&n[5])&&(n[0]||n[1]||n[2]||n[3]||n[4]||n[5]))
	{
		t=n[5];
		t+=n[4];
		x=11*n[4];
		y=0;
		while(n[0]>0&&x>0)
		{
			n[0]--;
			x--;
		}
		t+=n[3];
		x=n[3]*20;
		while(n[1]>0&&x>3)
		{
			n[1]--;
			x-=4;
		}
		while(n[0]>0&&x>0)
		{
			n[0]--;
			x--;
		}
		t+=n[2]/4;
		if(n[2]%4!=0)
		{
			t++;
			x=36-n[2]%4*9;
		}
		else
			x=0;
		if(x==27)
			y=20;
		else if(x==18)
			y=12;
		else if(x==9)
			y=4;
		while(n[1]>0&&y>3)
		{
			n[1]--;
			y-=4;
			x-=4;
		}
		while(n[0]>0&&x>0)
		{
			n[0]--;
			x--;
		}
		t+=n[1]/9;		
		if(n[1]%9!=0)
		{
			t++;
			x=36-n[1]%9*4;
		}
		else
			x=0;		
		while(n[0]>0&&x>0)
		{
			n[0]--;
			x--;
		}
		t+=(n[0]+35)/36;
		printf("%d\n",t);
	}
	return 0;
}

