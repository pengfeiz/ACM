#include <iostream>
using namespace std;

bool a[105][105];
char b[2][105];
char s[105];

int l,n;

int main()
{
 //   freopen("c:\\in.txt","r",stdin);
    int tt,i,j,k;
    scanf("%d",&tt);
    while(tt--)
    {
        scanf("%s",s);
        scanf("%s%s",b[0]+1,b[1]+1);
        l=strlen(b[0]+1);
        n=strlen(s);
        memset(a,0,sizeof(a));
        a[0][0]=true;
        for(i=0;i<n;i++)
        {
            for(j=0;j<=l;j++)
            {
                if(a[i][j])
                {
                    for(k=j+1;k<=l;k++)
                    {
                        if(b[0][k]=='*'
                           ||b[1][k]=='*'
                           ||b[0][k]==s[i]
                           ||b[1][k]==s[i])
                            a[i+1][k]=true;
                    }
                }
            }
        }
        for(i=0;i<=l;i++)
            if(a[n][i])
                break;
        if(i<=l)
            printf("win\n");
        else
            printf("lose\n");
     }
    return 0;
}

