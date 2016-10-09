#include <stdio.h> 
int n,i; 
int f[110]; 
int main() 
{ 
    scanf("%d",&n); 
    if (n==1){ printf("0\n");return 0;} 
    if (n==2) printf("1\n"); else printf("%d\n",n/2+1); 
    printf("%d %d %d\n",n/2+1,n/2,0); 

    for (i=1;i<=n/2;i++) 
    { 
        if (n==2) break; 
        printf("%d %d %d\n",n/2+1-i,2,n-i-1); 
    } 
} 
