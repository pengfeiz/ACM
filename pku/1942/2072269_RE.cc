#include <iostream>
using namespace std;
__int64 com(__int64 a,__int64 b)
{
	if(!a||!b)
		return 1;
	return com(a-1,b)+com(a,b-1);
}
int main()
{
	__int64 n,m;
	while(scanf("%I64d%I64d",&n,&m)&&(n||m))
		printf("%I64d\n",com(n,m));
	return 0;
}