#include <stdio.h>

void dv (int a,int *t)
{
    t[0]=a/100;
    a-=t[0]*100;
    t[1]=a/10;
    t[2]=a-t[1]*10; 
}
int main()
{
//    int p[1000];//这行超时
int *p=new int[1000];//这行通过
int n,ps,r=1,rg[10],i; 
    
    int t[3]; 

    for(n=0;scanf("%d",&p[n])!=EOF;n++) 
    {}
    for(i=0;i<10;i++)rg[i]=0;
    ps=0;
    while(p[ps]!=100)
    {
        r++;
        dv(p[ps],t);
        switch(t[0])
        {
            case 2:
                rg[t[1]]=t[2]; 
                break;
            case 3:
                rg[t[1]]+=t[2]; 
                if(rg[t[1]]>=1000 )rg[t[1]]-=1000;
                break;
            case 4:
                rg[t[1]]=rg[t[1]]*t[2]%1000; 
                break;
            case 5:
                rg[t[1]]=rg[t[2]]; 
                break;
            case 6:
                rg[t[1]]+=rg[t[2]]; 
                if(rg[t[1]]>=1000 )rg[t[1]]-=1000;
                break;
            case 7:
                rg[t[1]]=rg[t[1]]*rg[t[2]]%1000; 
                break;
            case 8:
                rg[t[1]]=p[rg[t[2]]]; 
                break;
            case 9:
                p[rg[t[2]]]=rg[t[1]]; 
                break;
            case 0:
                if(rg[t[2]])
                ps=rg[t[1]]-1;
                break;
        }    
        ps++;
    }
    printf("%d",r);
    return 0;    
         
        
         
}