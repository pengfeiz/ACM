#include"stdio.h"
//#include"conio.h"
main()
{int p,e,i,d,k,j=0;
 scanf("%d %d %d %d",&p,&e,&i,&d);
 while(p!=-1||e!=-1||i!=-1||d!=-1)
 {
       k=1;
       j++;
       while(k+d<p&&k+d<e&&k+d<i)
       {
              k++;
       }
       while((k+d-p)%23!=0||(k+d-e)%28!=0||(k+d-i)%33!=0)
       {    
              k++;  
       }//while
       if(k>21252)
          k-=21252;
       printf("Case %d: the next triple peak occurs in %d days.\n",j,k);
       scanf("%d %d %d %d",&p,&e,&i,&d);
 }
//getch();
}//main
        
