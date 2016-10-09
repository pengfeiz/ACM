#include <iostream>
using namespace std;

int b[35];
int a,p;

int main()
{
    char s[33][11];
    int q,l,i,j;
    while(1)
    {
        memset(b,0,sizeof(b));
        p=a=0;
        for(i=0;i<32;i++)
        {
            if(scanf("%s",s[i])==EOF)
                break;
            for(j=0;j<8;j++)
                s[i][j]-='0';
            for(j=0;j<8;j++)
                b[i]+=s[i][j]<<(7-j);
        }
        if(i<32)
            break;
        while(1)
        {
            q=(b[p]>>5);
            l=b[p]&31;
            p++;
            if(q==0)
                b[l]=a%256;
            else if(q==1)
                a=b[l]%256;
            else if(q==2)
            {
                if(a==0)
                    p=l%32;
            }
            else if(q==4)
                a=(a+255)%256;
            else if(q==5)
                a=(a+1)%256;
            else if(q==6)
                p=l%32;
            else if(q==7)
            {
                printf("%d%d%d%d%d%d%d%d\n",(a&128)==128,(a&64)==64,(a&32)==32,(a&16)==16,(a&8)==8,(a&4)==4,(a&2)==2,a&1);
                break;
            }
        }
    }
    return 0;
}
