#include <iostream>
using namespace std;
char s[100];
int main()
{
	int num,p,n,m,i,q;
	while(cin>>n>>m&&!(n==0&&m==0))
	{
		num=q=0;
		for(i=0;i<n;i++)
		{
			scanf("%s %d",s,&p);
			num+=p%3;
			q+=p/3;
		}
		if(num%2==1)
		{
			num+=3;
			q--;
		}
		cout<<(m-q-num/2)*3+num/2<<endl;
	}
	return 0;
}
			

