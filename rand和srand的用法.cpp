#include<iostream>
#include<cstdlib>
//int rand(void)���ش�0��RAND_MAX������� 
//void srand( unsigned seed ); 
int main(void)
{
   int i;
   printf("Ten random numbers from 0 to 99\n\n");
    srand( time(NULL) );//���������һ��ÿ�β��������������һ����   
   for(i=0; i<10; i++)
      printf("%d\t%d\n", i,rand()%100);
   system("pause");
   return 0;
}
