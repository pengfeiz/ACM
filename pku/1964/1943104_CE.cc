#include <stdafx.h>
#include <stdio.h>
#include <memory.h>
int h[1002];
int l[1001];
int r[1002];
int MaxRect(int n)
   { h[0] = -1;
      l[0] = -1;
      int i,j;
      for (i=1; i<=n; ++i) {  j = i-1; 
          while(h<=h[j]) 
                  j = l[j];  l = j;
            }
       h[n+1] = -1;
       r[n] = n + 1;
       for (i=n; i>=1; --i)
            {  j = i+1; 
                while(h<=h[j]) 
                      j = r[j];  
                     r = j; 
          }
      int size,max = 0; 
     for (i=1; i<=n; ++i) 
       {  size = h*(r-l-1);
               if(max<size)   max = size;
      } return max;}



void main()
   { int k,m,n,i,j,no,max,cur; 
     char c;
    scanf("%d",&k); 
   for (no=0; no<k; ++no) {
      scanf("%d%d",&m,&n);  
      memset( h, 0, sizeof(h) ); 
      max = 0; 
          for (i=0; i<m; ++i)  {
              for (j=1; j<=n; ++j)   {  
                 scanf("%c",&c);   
                           while(c!='R' && c!='F') 
                              scanf("%c",&c);    
                                 if (c=='R')     
                                    h[j] = 0;    
                                else     
                                    ++h[j];
               }  
             cur = MaxRect(n);  
                   if(max<cur)   
                       max = cur; 
       } 
           printf("%d\n",max*3); 
    }
  }