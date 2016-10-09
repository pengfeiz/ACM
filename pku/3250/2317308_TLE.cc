#include <iostream>
using namespace std;
#define MAX 80001


int n,t;
int a[MAX];


void solve(int x,int y)
{
	int i;
	if(x==y)
		return;
	for(i=x+1;i<y;i++)
		if(a[i]>a[x])
			break;
	t+=i-x-1;
	solve(x+1,i);
	solve(i,y);
}


int main()
{
	int i;
	t=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	solve(0,n);
	printf("%d\n",t);
	return 0;
}