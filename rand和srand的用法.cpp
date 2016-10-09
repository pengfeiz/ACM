#include<iostream>
#include<cstdlib>
//int rand(void)返回从0到RAND_MAX的随机数 
//void srand( unsigned seed ); 
int main(void)
{
   int i;
   printf("Ten random numbers from 0 to 99\n\n");
    srand( time(NULL) );//如果不加这一句每次产生的随机数都是一样的   
   for(i=0; i<10; i++)
      printf("%d\t%d\n", i,rand()%100);
   system("pause");
   return 0;
}
