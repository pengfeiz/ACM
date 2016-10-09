#include <iostream>
using namespace std;

long jc(long n)
{
    long i,m=1;
    for(i=2;i<=n;i++)
        m*=i;
    return m;
}

long tjc(long n)
{
    long i,m=0;
    for(i=0;i<=n;i++)
        m+=jc(i);
    return m;
}

int dosth(long n)
{
    long m=0,i=0;
    if(n<=4)
        return 1;
    while(jc(i)<=n)
        i++;
    i--;
    if(n>tjc(i))
        return 0;
    m=dosth(n-jc(i));
    return m;
}

int main()
{
    long n=0;
    while(cin>>n&&n>=0)
    {
        if(n==0)
    	{
            cout<<"NO\n";
            continue;
    	}
        if(dosth(n)==1)
            cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
