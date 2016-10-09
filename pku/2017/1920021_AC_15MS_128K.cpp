#include <iostream>
using namespace std;
int main()
{
    int a[12][2],i,n,tt;
    while(cin>>n&&n!=-1)
    {
        tt=0;
        for(i=0;i<n;i++)
        a[i][0]=a[i][1]=0;
        for(i=0;i<n;i++)
        cin>>a[i][0]>>a[i][1];
        for(i=0;i<n;i++)
        {
            if(i==0)
            tt+=a[i][1]*a[i][0];
            else
            tt+=(a[i][1]-a[i-1][1])*a[i][0];
        }
        cout<<tt<<" miles\n";
    }
    return 0;
} 
            
        
        
            
                        
