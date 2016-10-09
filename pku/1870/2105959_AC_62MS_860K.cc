#include <iostream>
using namespace std;
int a[400][400],num,b[400][400],c[1000][2],cc[1000][2],l1,l2,q[10002][2];

int main()
{
//	freopen("out.txt","w",stdout);
	int x,y,p,n,xx,x1,x2,y1,y2;
	memset(a,0,sizeof(a));
	a[200][200]=1;
	a[202][200]=2;
	q[1][0]=q[1][1]=200;
	q[2][0]=202;
	q[2][1]=200;
	num=2;
	p=1;
	x=202;
	y=200;
	n=xx=0;
	while(num<=10000)
	{
		if(xx==p||(xx==p-1&&n==0))
		{
			n=(n+1)%6;
			xx=0;
			if(n==5)
				p++;
		}
		num++;
		if(n==0)
		{
			a[x+1][y-1]=num;
			x++;
			y--;
			xx++;
		}
		else if(n==1)
		{
			a[x-1][y-1]=num;
			x--;
			y--;
			xx++;
		}
		else if(n==2)
		{
			a[x-2][y]=num;
			x-=2;
			xx++;
		}
		else if(n==3)
		{
			a[x-1][y+1]=num;
			x--;
			y++;
			xx++;
		}
		else if(n==4)
		{
			a[x+1][y+1]=num;
			x++;
			y++;
			xx++;
		}
		else if(n==5)
		{
			a[x+2][y]=num;
			x+=2;
			xx++;
		}
		q[num][0]=x;
		q[num][1]=y;
	}
//	x=1;
//	for(y=x+1;y<10000;y++)
	while(scanf("%d%d",&x,&y)&&(x||y))
	{
		x1=q[x][0];
		y1=q[x][1];
		x2=q[y][0];
		y2=q[y][1];
		/*
		int i,j;
		for(i=0;i<400;i++)
		{
			for(j=0;j<400;j++)
				if(a[i][j]==x)
				{
					x1=i;
					y1=j;
					break;
				}
			if(j<400)
				break;
		}
		for(i=0;i<400;i++)
		{
			for(j=0;j<400;j++)
				if(a[i][j]==y)
				{
					x2=i;
					y2=j;
					break;
				}
			if(j<400)
				break;
		}
		for(i=0;i<400;i++)
			for(j=0;j<400;j++)
				b[i][j]=999999;
		memset(c,0,sizeof(c));
		b[x1][y1]=0;
		l1=1;
		c[0][0]=x1;
		c[0][1]=y1;
		while(b[x2][y2]==999999)
		{
			memset(cc,0,sizeof(cc));
			l2=0;
			for(i=0;i<l1;i++)
			{
				if(!a[c[i][0]][c[i][1]])
					continue;
				if(b[c[i][0]+2][c[i][1]]>b[c[i][0]][c[i][1]]+1)
				{
					b[c[i][0]+2][c[i][1]]=b[c[i][0]][c[i][1]]+1;
					cc[l2][0]=c[i][0]+2;
					cc[l2][1]=c[i][1];
					l2++;
				}
				if(b[c[i][0]-1][c[i][1]+1]>b[c[i][0]][c[i][1]]+1)
				{
					b[c[i][0]-1][c[i][1]+1]=b[c[i][0]][c[i][1]]+1;
					cc[l2][0]=c[i][0]-1;
					cc[l2][1]=c[i][1]+1;
					l2++;
				}
				if(b[c[i][0]+1][c[i][1]+1]>b[c[i][0]][c[i][1]]+1)
				{
					b[c[i][0]+1][c[i][1]+1]=b[c[i][0]][c[i][1]]+1;
					cc[l2][0]=c[i][0]+1;
					cc[l2][1]=c[i][1]+1;
					l2++;
				}
				if(b[c[i][0]-2][c[i][1]]>b[c[i][0]][c[i][1]]+1)
				{
					b[c[i][0]-2][c[i][1]]=b[c[i][0]][c[i][1]]+1;
					cc[l2][0]=c[i][0]-2;
					cc[l2][1]=c[i][1];
					l2++;
				}
				if(b[c[i][0]-1][c[i][1]-1]>b[c[i][0]][c[i][1]]+1)
				{
					b[c[i][0]-1][c[i][1]-1]=b[c[i][0]][c[i][1]]+1;
					cc[l2][0]=c[i][0]-1;
					cc[l2][1]=c[i][1]-1;
					l2++;
				}
				if(b[c[i][0]+1][c[i][1]-1]>b[c[i][0]][c[i][1]]+1)
				{
					b[c[i][0]+1][c[i][1]-1]=b[c[i][0]][c[i][1]]+1;
					cc[l2][0]=c[i][0]+1;
					cc[l2][1]=c[i][1]-1;
					l2++;
				}
			}
			l1=l2;
			memcpy(c,cc,l2*sizeof(cc[0]));
		}
		printf("The distance between cells %d and %d is %d.\n",x,y,b[x2][y2]);
		*/
		l1=0;
		if(abs(x1-x2)<abs(y1-y2))
		{
			l1+=abs(x1-x2);
			if(y1<y2)
				y1+=abs(x1-x2);
			else
				y1-=abs(x1-x2);
			x1=x2;
		}
		else
		{
			l1+=abs(y1-y2);
			if(x1<x2)
				x1+=abs(y1-y2);
			else
				x1-=abs(y1-y2);
			y1=y2;
		}
		if(x1==x2)
			l1+=abs(y1-y2);
		if(y1==y2)
			l1+=abs(x1-x2)/2;
		printf("The distance between cells %d and %d is %d.\n",x,y,l1);
	}
	return 0;
}

