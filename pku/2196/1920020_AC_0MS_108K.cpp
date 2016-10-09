#include <iostream>
using namespace std;
int judge(int n)
{
	int i,m16,m12,m10,n16,n10,n12;
	m16=m12=m10=n;
	n10=n12=n16=0;
	for(i=0;i<4;i++)
	{
		n10+=m10%10;
		n16+=m16%16;
		n12+=m12%12;
		m10/=10;
		m12/=12;
		m16/=16;
	}
	if(n10==n12&&n12==n16)
		return 1;
	return 0;
}

int main()
{
	int n;
	for(n=2992;n<10000;n++)
		if(judge(n)==1)
			cout<<n<<endl;
	return 0;
}