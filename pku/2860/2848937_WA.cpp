#include <iostream>
using namespace std;

int a[30],b[30];
int n;

int main()
{
    int i,m,k,nn;
    nn=0;
    scanf("%d%d%d",&n,&m,&k);
    for(i=0;i<n;i++)
                    scanf("%d",&a[i]);
    for(i=0;i<n;i++)
                    scanf("%d",&b[i]);
    for(i=0;i<n;i++)
    {
                    if(a[i]>b[i])
                                 nn+=(a[i]-b[i]);
    }
    printf("%d\n",nn);
    return 0;
}
