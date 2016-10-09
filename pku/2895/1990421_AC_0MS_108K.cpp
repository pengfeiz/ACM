#include <iostream>
using namespace std;
char s[1000];
int h[26][2]={1,1,1,2,1,3,2,1,2,2,2,3,3,1,3,2,3,3,4,1,4,2,4,3,5,1,5,2,5,3,6,1,6,2,6,3,6,4,7,1,7,2,7,3,8,1,8,2,8,3,8,4};
int main()
{
	int n,a,b,l,i,t,m;
	cin>>n;
	while(n-->0)
	{
		t=0;
		m=-2;
		cin>>a>>b;
		getchar();
		gets(s);
		l=strlen(s);
		for(i=0;i<l;i++)
		{
			if(s[i]==' ')
			{
				t+=a;
				m=-1;
				continue;
			}
			if(h[s[i]-'A'][0]==m)
				t+=b;
			else
				m=h[s[i]-'A'][0];
			t+=a*h[s[i]-'A'][1];
		}
		cout<<t<<endl;
	}
	return 0;
}


