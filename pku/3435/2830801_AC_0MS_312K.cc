#include <iostream>
using namespace std;

int a[101][101];
int n;
bool b[101];

int main()
{
    int i,j,k,ii;
    bool f;
    scanf("%d",&n);
    for(i=0;i<n*n;i++)
        for(j=0;j<n*n;j++)
            scanf("%d",&a[i][j]);
    for(i=0;i<n*n;i++)
    {
        memset(b,0,sizeof(b));
        for(j=0;j<n*n;j++)
        {
            if(b[a[i][j]])
                f=false;
            b[a[i][j]]=true;
            b[0]=false;
        }
    }
    for(i=0;i<n*n;i++)
    {
        memset(b,0,sizeof(b));
        for(j=0;j<n*n;j++)
        {
            if(b[a[j][i]])
                f=false;
            b[a[j][i]]=true;
            b[0]=false;
        }
    }
    for(i=0;i<n;i++)
    {
        for(ii=0;ii<n;ii++)
        {
            memset(b,0,sizeof(b));
            for(j=i*n;j<i*n+n;j++)
            {
                for(k=ii*n;k<ii*n+n;k++)
                {
                    if(b[a[j][k]])
                        f=false;
                    b[a[j][k]]=true;
                    b[0]=false;
                }
            }
        }
    }
    if(f)
        printf("CORRECT\n");
    else
        printf("INCORRECT\n");
    return 0;    
}
