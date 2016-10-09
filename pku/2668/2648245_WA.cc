#include <iostream>
using namespace std;

inline int Div(int a,int b)
{
    if(!b) 
		return INT_MAX;
    return a%b?a/b+1:a/b;
}

int main()
{
    int k,next_k,d,N,D,sum;
    while(cin>>D>>N,D||N)
    {
		sum=0;
        k=1;
        while (k<=N)
        {
            d=Div(D,k);
            next_k=Div(D,d-1);
            if (next_k>N)
                next_k=N+1;
            sum+=d*(next_k-k);
            k=next_k;
        }
        printf("%d\n",sum);
    }
} 