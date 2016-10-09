#include <iostream>
#include <queue>
using namespace std;
struct gao
{int n;}k;
priority_queue<gao> dq,q1;
bool operator <(const gao &m1,const gao &m2)
{return m1.n>m2.n;}
int main()
{
	int n,i,sum=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&k.n);
		dq.push(k);
	}
	gao k1,k2,ans;
	while(1)
	{
		k1=dq.top();
		dq.pop();
		k2=dq.top();
		dq.pop();
		ans.n=k1.n+k2.n;
		sum+=ans.n;
		if(dq.empty())
			break;
		dq.push(ans);
	}
	printf("%d\n",sum);
	return 0;
} 