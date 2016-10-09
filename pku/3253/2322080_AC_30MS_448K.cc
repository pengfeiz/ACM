#include <iostream>
#include <queue>
using namespace std;
struct gao
{__int64 n;}k,k1,k2,ans;
priority_queue<gao> dq,q1;
bool operator <(const gao &m1,const gao &m2)
{return m1.n>m2.n;}
int main()
{
	__int64 n,i,sum=0;
	scanf("%I64d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%I64d",&k.n);
		dq.push(k);
	}
	while(1){
		k1=dq.top();
		dq.pop();
		k2=dq.top();
		dq.pop();
		ans.n=k1.n+k2.n;
		sum+=ans.n;
		if(dq.empty())
			break;
		dq.push(ans);
	}printf("%I64d\n",sum);
return 0;}