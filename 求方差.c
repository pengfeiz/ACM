#include<stdio.h>
#include<stdlib.h>

int main(){

    int n,i;
    float data1[20],data2[20],datas[20];
    int memcp(float *,float *, float *,int,int);
    float avg(float *,int);
    float func(float *,int);
    
    printf("input n:");
    scanf("%d",&n);
    printf("input array1:");
    for(i=0;i<n;i++)
        scanf("%f",&data1[i]);
    printf("input array2:");
    for(i=0;i<n;i++)
        scanf("%f",&data2[i]);
        
    memcp(datas,data1,data2,n,n);
    printf("\n第一个所求%f",func(datas,2*n));
    printf("\n第二个所求%f",func(data1,n)+func(data2,n));
     
    system("pause");
    return 0;
}    

int memcp(float *dest,float *src1, float *src2,int n1,int n2){

    int pos,i,j;
    for(i=0;i<n1;i++)
       dest[i] = src1[i];
   
    for(pos=n1,j=0;pos<n2+n1,j<n2;pos++,j++)
           dest[pos] = src2[j];
       
    return 0;
} 

float avg(float *data,int n){

    int i;
    float s = 0.0;
    for(i=0;i<n;i++)
        s += data[i];
    return s/n;
}
float func(float *data,int n){
    
    int i;
    float s = .0;
    float avgt = avg(data,n);
    for(i=0;i<n;i++)
        s += (data[i]-avgt)*(data[i]-avgt);
    return s;
        
}
       

