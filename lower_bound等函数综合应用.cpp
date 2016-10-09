#include <iostream>
#include <algorithm>
using namespace std;
//void *memset(void *array,  char ch, unsigned sizeof(array)); 把ch的值放到每个字节里 
//iterator lower_bound( iterator first, iterator last,  const TYPE& val );//返回的是地址 
int main()
{
   
    int n,i,a[5],c[5];
    scanf("%d",&n);
    for(i=0;i<5;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    
    memcpy(c,a,sizeof(a));
    
    printf("a is :");
    for(i=0;i<5;i++)
        printf("%d ",a[i]);
    
    printf("\n"); 
       
    printf("c is :");
    for(i=0;i<5;i++)
        printf("%d ",c[i]);
    
    printf("\n");
        
    memset(a,3,sizeof(a));
    printf("a is :");
    for(i=0;i<5;i++)
        printf("%d ",a[i]);
    
    printf("\n"); 
    
    printf("lower:%d\n",lower_bound(c,c+n,3)-c);
    printf("upper:%d\n",upper_bound(c,c+n,3)-c);
    printf("\n\n");
    
    printf("%d",0x03030303);
    system("pause");
    return 0;
}
