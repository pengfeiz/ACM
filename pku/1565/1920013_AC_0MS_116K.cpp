#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	char he[32],c;
	int n,i,t;
	while((c=getchar())!='0')
	{
		he[0]=c;
		t=n=0;
		while((c=getchar())!='\n')
		{
			t++;
			he[t]=c;
		}
		for(i=0;i<=t;i++)
			n+=(int)(pow(2,(double)(t-i+1))-1)*(he[i]-48);
		cout<<n<<endl;
	}
	return 0;
}
