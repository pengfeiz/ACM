#include <iostream>
using namespace std;
int main()
{
	char c[1000];
	int s[27],n,i,l,t,tt,p;
	while(cin>>n&&n)
	{
		cin>>c;
		l=strlen(c);
		t=tt=p=0;
		for(i=0;i<l;i++)
			s[c[i]-'A']=0;
		for(i=0;i<l;i++)
		{
			if(s[c[i]-'A']==0)
			{
				s[c[i]-'A']=1;
				t++;
			}
			else if(s[c[i]-'A']==1)
			{
				if(t>n)
					tt++;
				t--;
				s[c[i]-'A']=0;
			}
		}
		if(tt==0)
			cout<<"All customers tanned successfully.\n";
		else 
			cout<<tt<<" customer(s) walked away.\n";
	}
	return 0;
}
