#include <iostream>
using namespace std;

void dosth(int a,int *t)
{
    t[0]=a/100;
    a-=t[0]*100;
    t[1]=a/10;
    t[2]=a-t[1]*10; 
}
int main()
{
	int p[1000],n,s,r=1,rg[10],i,t[3]; 
	for(n=0;scanf("%d",&p[n])!=EOF;n++);
    for(i=0;i<10;i++)
		rg[i]=0;
    s=0;
    while(p[s]!=100)
    {
        r++;
        dosth(p[s],t);
        switch(t[0])
        {
            case 2:
                rg[t[1]]=t[2]; 
                break;
            case 3:
                rg[t[1]]+=t[2]; 
                if(rg[t[1]]>=1000 )
					rg[t[1]]-=1000;
                break;
            case 4:
                rg[t[1]]=rg[t[1]]*t[2]%1000; 
                break;
            case 5:
                rg[t[1]]=rg[t[2]]; 
                break;
            case 6:
                rg[t[1]]+=rg[t[2]]; 
                if(rg[t[1]]>=1000 )
					rg[t[1]]-=1000;
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
					s=rg[t[1]]-1;
                break;
        }    
        s++;
    }
    printf("%d\n",r);
    return 0;     
}


