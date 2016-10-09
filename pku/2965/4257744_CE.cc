#include"stdio.h"
#include"conio.h"
using namespace std;
static long pp[16],vv[16]; 
static int bb[16][2],cc[16][2],h;
void fen(long int m)
{ long h,j,x,y,d[4][4]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
  h=m; 
     while(h>0) 
     {j=15; 
      while(vv[j]>h)j--;
      h-=vv[j]; 
      x=j/4;y=j%4;
      d[x][y]=1; 
      } 
   for(x=0;x<4;x++)
    {for(y=0;y<4;y++)
      printf("%d",d[x][y]);
     printf("%*\n");
     }
     printf("~~~~~~\n");
}/*打印*/             
void tryy(long k,long x,long y)
{int i,j;
 if(x==16)
 {  if(k==0)
    {   if(y<h)
        {   for(i=0;i<y;i++)
              for(j=0;j<2;j++)
                cc[i][j]=bb[i][j];
            h=y;
        }//if
    }//if
    return; 
 }
 bb[y][0]=x/4+1;
 bb[y][1]=x%4+1;  
 tryy(k^pp[x],x+1,y+1);
 tryy(k,x+1,y);    
}          
main()
{ //初始化 
 long  a[4][4]={{0}},i,j,x,y,n;
 char ch;
 vv[0]=1;
 for(i=1;i<16;i++)
    vv[i]=vv[i-1]*2;
 for(i=0;i<16;i++)
 {     x=i/4;
       y=i%4;
       pp[i]=0;
       pp[i]+=vv[i];
       for(j=0;j<4;j++)
       {    if(j!=x)
              pp[i]+=vv[j*4+y];
            if(j!=y)
              pp[i]+=vv[x*4+j];
       }//for   
  }//for
   //input
 n=0;
 h=100;
 for(i=0;i<4;i++)
 {   for(j=0;j<4;j++)
     {   scanf("%c",&ch);
       if(ch=='+')
          n+=vv[i*4+j];
     }//for
  //   getchar();
 }//for          
 //printf("n=%d\n",n);
// printf("%d\n",vv[13]+vv[1]);  
 // tryy 
 tryy(n,0,0);
 //output
 printf("%d\n",h);
 for(i=0;i<h;i++)
    printf("%d %d\n",cc[i][0],cc[i][1]);
 //fen(n);
// for(i=0;i<h;i++)
//    fen(n^=pp[(cc[i][0]-1)*4+cc[i][1]-1]);   
 //getch();                   
} 
