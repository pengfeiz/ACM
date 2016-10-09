#include<iostream>
//continue永远会跳出离他最近的那一层while 
int main(){

    int i = 0;
    int j = 1;
    while(i<5){
        i++;
        j++; 
        if(i < 5)
        {
          
          if(j == 4){
                    printf("i=%d,j=%d\n",i,j);
                   continue;
                    printf("我日");
                    
                    
                   //break;
                }
                 printf("if里面的%d",i);   
        }
        printf("\t%d\n",i)  ;
       
        
    }
    system("pause");
    return 0;    
}    
