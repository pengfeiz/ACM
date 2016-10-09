#include <iostream>
using namespace std;

int Div(int a,int b)
{
    if(!b) 
		return INT_MAX;
    return a%b?a/b+1:a/b;
}

int main()
{
    int k,next_k,d,n,m;
	__int64 sum;
    while(scanf("%d%d",&n,&m),n||m)
    {
		sum=0;
        k=1;
        while(k<=m)
        {
            d=Div(n,k);
            next_k=Div(n,d-1);
            if(next_k>m)
                next_k=m+1;
            sum+=d*(next_k-k);
            k=next_k;
        }
        printf("%I64d\n",sum);
    }
	return 0;
} 