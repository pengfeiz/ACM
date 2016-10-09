#include <iostream>
using namespace std;
 
int r,c,n,maxx,dx,dy,len,cx,cy,i,j,absdy; 
  
struct Point
{   
    int x,y;   
}p[5000];   

bool table[5000][5000]={0};  
 
int com(const void *a,const void *b)   
{   
    if(((Point*)a)->x>((Point*)b)->x)return 1;   
    if(((Point*)a)->x<((Point*)b)->x)return -1;   
    return ((Point*)a)->y-((Point*)b)->y;   
}   

int main()   
{   
    scanf("%d%d%d",&r,&c,&n);
	maxx=0;
    for(i=0;i<n;i++)   
    {
        scanf("%d%d",&p[i].x,&p[i].y);
        p[i].x--;p[i].y--;   
        table[p[i].x][p[i].y]=true;   
    }   
    qsort(p,n,sizeof(Point),com);   
    for(i=0;i<n;i++)   
        for(j=i+1;j<n;j++)   
            {   
                dx=p[j].x-p[i].x;   
                if(dx&&dx*maxx>r)
					continue;   
                absdy=dy=p[j].y-p[i].y;   
                cx=p[i].x-dx;cy=p[i].y-dy;   
                if(cx>=0&&cy>=0&&cy<c)
					continue;   
				cx=p[j].x+dx;cy=p[j].y+dy;   
                len=2;   
                while(cy>=0&&cx<r&&cy<c)   
                {   
                    if(!table[cx][cy])
						break;
                    len++;   
                    cx+=dx;cy+=dy;   
                }   
                if(len>=3&&len>maxx)
					maxx=len;
              }
    printf("%d\n",maxx);  
	return 0;
}   