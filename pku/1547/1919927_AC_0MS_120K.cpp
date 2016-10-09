#include <iostream>
using namespace std;
char s[10][100];
int main()
{
	int num[10][3],n,i,m1,m2;
	while(cin>>n&&n!=-1)
	{
		for(i=0;i<n;i++)
			cin>>num[i][0]>>num[i][1]>>num[i][2]>>s[i];
		m1=m2=0;
		for(i=1;i<n;i++)
		{
			if(num[i][0]*num[i][1]*num[i][2]>num[m1][0]*num[m1][1]*num[m1][2])
				m1=i;
			else if(num[i][0]*num[i][1]*num[i][2]<num[m2][0]*num[m2][1]*num[m2][2])
				m2=i;
		}
		cout<<s[m1]<<" took clay from "<<s[m2]<<".\n";
	}
	return 0;
}