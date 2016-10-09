#include <stdio.h>
#include <string.h>
#include<stdlib.h>
//void *memset(void *s, char ch, unsigned n);
//void *memcpy(void *dest, void *src, unsigned n);
int main(void)
{
   char src[] = "******************************";
   char dest[] = "abcdefghijlkmnopqrstuvwxyz0123456709";
   char buffer[] = "Hello world\n";
   
   printf("destination before memcpy: %s\n", dest);
    memcpy(dest, src, strlen(src));
   if (dest)
      printf("destination after memcpy:  %s\n", dest);
   else
      printf("memcpy failed\n");
      
      
    printf("\n\n\n");
   printf("Buffer before memset: %s\n", buffer);
   memset(buffer, '*', strlen(buffer) - 1);
   printf("Buffer after memset:  %s\n", buffer);  
         
   system("pause");
   return 0;
}
