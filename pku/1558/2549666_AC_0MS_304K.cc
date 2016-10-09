#include <iostream>
#include <algorithm>
using namespace std;


struct gao
{
	int x,y;
}z[8]={-1,-1,-1,0,-1,1,0,1,1,1,1,0,1,-1,0,-1};


char s[10][10];
int m;
struct gao2
{
	char s[10];
}ss[10000];
int n=8;
char c;


bool com(gao2 a,gao2 b)
{return strcmp(a.s,b.s)<0;}


void judge(int x,int y)
{
	int i,j,xx,yy,count;
	for(j=0;j<8;j++)
	{
		count=1;
		xx=x+z[j].x;
		yy=y+z[j].y;
		while(xx>=0&&xx<n&&yy>=0&&yy<n)
		{
			if(s[xx][yy]!='.')
				count++;
			xx+=z[j].x;
			yy+=z[j].y;
			if(xx<0||xx>=n||yy<0||yy>=n)
				break;
		}
		xx=x+z[(j+4)%8].x;
		yy=y+z[(j+4)%8].y;
		while(xx>=0&&xx<n&&yy>=0&&yy<n)
		{
			if(s[xx][yy]!='.')
				count++;
			xx+=z[(j+4)%8].x;
			yy+=z[(j+4)%8].y;
			if(xx<0||xx>=n||yy<0||yy>=n)
				break;
		}
		xx=x+z[j].x*count;
		yy=y+z[j].y*count;
		if(xx<0||xx>=n||yy<0||yy>=n)
			continue;
		for(i=0;i<count;i++)
		{
			xx=x+z[j].x*i;
			yy=y+z[j].y*i;
			if(s[xx][yy]!=c&&s[xx][yy]!='.')
				break;
		}
		if(i<count)
			continue;
		xx=x+z[j].x*count;
		yy=y+z[j].y*count;
		if(s[xx][yy]!=c)
		{
			ss[m].s[0]=x+'A';
			ss[m].s[1]=y+1+'0';
			ss[m].s[2]='-';
			ss[m].s[3]=xx+'A';
			ss[m].s[4]=yy+1+'0';
			ss[m].s[5]='\0';
			m++;
		}
	}
}



int main()
{
	int i,j;
	while(scanf("%s",s[0])!=EOF)
	{
		m=0;
		for(i=1;i<8;i++)
			scanf("%s",s[i]);
		getchar();
		scanf("%c",&c);
		for(i=0;i<8;i++)
			for(j=0;j<8;j++)
			{
				if(s[i][j]==c)
					judge(i,j);
			}
		if(!m)
			printf("No moves are possible\n");
		else
		{
			sort(ss,ss+m,com);
			for(i=0;i<m;i++)
				printf("%s\n",ss[i].s);
		}
		printf("\n");
	}
	return 0;
}