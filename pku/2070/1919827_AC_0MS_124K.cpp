#include <iostream>
using namespace std;
int main()
{
    float num[3][3],n[3],t;
    int i;
    num[0][0]=4.5;
    num[1][0]=6.0;
    num[2][0]=5.0;
    num[0][1]=150;
    num[1][1]=300;
    num[2][1]=200;
    num[0][2]=200;
    num[1][2]=500;
    num[2][2]=300;
    while(cin>>n[0]>>n[1]>>n[2]&&n[0]!=0&&n[1]!=0&&n[2]!=0)
    {
        t=0;
        if(n[0]<=num[0][0]&&n[1]>=num[0][1]&&n[2]>=num[0][2])
        {
            cout<<"Wide Receiver";
            t=1;
        }
        if(n[0]<=num[1][0]&&n[1]>=num[1][1]&&n[2]>=num[1][2])
        {
            if(t==1)
            cout<<" ";
            else
            t=1;
            cout<<"Lineman";
        }
        if(n[0]<=num[2][0]&&n[1]>=num[2][1]&&n[2]>=num[2][2])
        {
            if(t==1)
            cout<<" ";
            else
            t=1;
            cout<<"Quarterback";
        }
        if(t!=1)
        cout<<"No positions";
        cout<<endl;
    }
    return 0;
}
