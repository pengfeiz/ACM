#include <iostream>
using namespace std;

int a[30],b[30];
int n;

int main()
{
    int i,m,k,n1,n2;
    n1=n2=0;
    scanf("%d%d%d",&n,&m,&k);
    for(i=0;i<n;i++)
                    scanf("%d",&a[i]);
    for(i=0;i<n;i++)
                    scanf("%d",&b[i]);
    for(i=0;i<n;i++)
    {
                    if(a[i]>b[i])
                                 n1+=(a[i]-b[i];
    }
    printf("%d\n",n1>n2?n1:n2);
    scanf("%d",&n1);
    return 0;
}
