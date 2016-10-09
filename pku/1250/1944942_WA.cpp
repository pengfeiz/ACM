#include <iostream>
using namespace std;
int main()
{
	char c[1000];
	int s[500],n,i,l,t,tt;
	while(cin>>n&&n)
	{
		cin>>c;
		l=strlen(c);
		t=tt=0;
		for(i=0;i<l;i++)
			s[c[i]]=0;
		for(i=0;i<l;i++)
		{
			if(s[c[i]]==0)
			{
				s[c[i]]=1;
				t++;
			}
			else if(s[c[i]]==1)
			{
				t--;
				s[c[i]]=0;
			}
			if(t>n)
			{
				t--;
				tt++;
			}
		}
		if(tt==0)
			cout<<"All customers tanned successfully.\n";
		else 
			cout<<tt<<" customer(s) walked away.\n";
	}
	return 0;
}
