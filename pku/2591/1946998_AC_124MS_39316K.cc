#include <iostream>
using namespace std;
#define MAX 10000000
int num[MAX];
int main()
{
	int n,t2,t3,i;
	num[0]=1;
	t2=t3=0;
	for(i=1;i<MAX;i++)
	{
		if(2*num[t2]>num[t3]*3)
		{
			num[i]=num[t3]*3+1;
			t3++;
		}
		else if(2*num[t2]==num[t3]*3)
		{
			num[i]=num[t2]*2+1;
			t2++;
			t3++;
		}
		else
		{
			num[i]=num[t2]*2+1;
			t2++;
		}
	}
	while(cin>>n)
		cout<<num[n-1]<<endl;
	return 0;
}
	