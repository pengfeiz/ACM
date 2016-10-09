#include <iostream>
using namespace std;
int main()
{
    int n,m,i,nn,time=0;
    float q;
    cin>>nn;
    for(i=0;i<nn;i++)
    {
        time++;
        cin>>n>>m;
        if((m*n)%2==0)
        q=m*n;
        else
        q=m*n+0.41;
        printf("Scenario #%d:\n%.2f\n\n",time,q);
    }
    return 0;
}
    
