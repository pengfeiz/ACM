#include <iostream>
#include <stdio.h>
#define COUNT 1050
#define CT    30
using namespace std;
long a[COUNT][COUNT],b[COUNT][COUNT];
__int64 c[COUNT][COUNT]=
{
    0
};
int main()
{
    int nn,pp,mm;
    scanf("%d%d%d",&nn,&pp,&mm);
    int i,j,k,m,n,l;
    for (i=0;i<nn;i++)
    {
        for (j=0;j<pp;j++)
        {
            scanf("%ld",&a[i][j]);
        }
    }
    for (i=0;i<pp;i++)
    {
        for (j=0;j<mm;j++)
        {
            scanf("%ld",&b[i][j]);
        }
    }
    for (k=0;k<pp;k+=CT)
    {
        for (i=0;i<nn;i+=CT)
            for (j=0;j<mm;j+=CT)
                for (m=i;m<i+CT;m++)
                    for (n=j;n<j+CT;n++)
        for (l=k;l<k+CT;l+=10)
        {
            c[m][n]+=(a[m][l]* b[l][n]+a[m][l+1]* b[l+1][n]+a[m][l+2]* b[l
                      +2][n]+a[m][l+3]* b[l+3][n]+a[m][l+4]* b[l+4][n]+a[m][l
                      +5]* b[l+5][n]+a[m][l+6]* b[l+6][n]+a[m][l+7]* b[l+7][n]
                      +a[m][l+8]* b[l+8][n]+a[m][l+9]* b[l+9][n]);
        }
    }
    bool yes=true;
    __int64 t;
    for (i=0;i<nn;i++)
    {
        for (j=0;j<mm;j++)
        {
            scanf("%I64d",&t);
            if (c[i][j]!=t)
            {
                yes=false;
                printf("No\n");
                printf("%d %d\n%I64d\n",i+1,j+1,c[i][j]);
                break;
            }
        }
        if ( ! yes)
        {
            break;
        }
    }
    if (yes)
    {
        printf("Yes\n");
    }
    return 0;
} 