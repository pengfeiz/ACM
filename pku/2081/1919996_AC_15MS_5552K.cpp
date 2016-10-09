#include <iostream>
using namespace std;
#define MAX 500001
int num[MAX],s[10*MAX];
int main()
{
	long i;
	for(i=0;i<MAX;i++)
		num[i]=s[i]=0;
	s[0]=1;
	for(i=1;i<MAX;i++)
	{
		if(num[i-1]-i>0&&s[num[i-1]-i]==0)
		{
			num[i]=num[i-1]-i;
			s[num[i-1]-i]=1;
		}
		else
		{
			num[i]=num[i-1]+i;
			s[num[i]]=1;
		}
	}
	while(cin>>i&&i!=-1)
		cout<<num[i]<<endl;
	return 0;
}


