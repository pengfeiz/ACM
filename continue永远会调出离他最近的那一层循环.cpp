#include<iostream>
//continue��Զ�����������������һ��while 
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
                    printf("����");
                    
                    
                   //break;
                }
                 printf("if�����%d",i);   
        }
        printf("\t%d\n",i)  ;
       
        
    }
    system("pause");
    return 0;    
}    
