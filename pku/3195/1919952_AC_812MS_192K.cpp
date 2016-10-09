#include <iostream>
using namespace std;
int main()
{
	long num[10000][2],t,l,i,j,p,tt;
	char c;
	while(cin>>num[1][0]&&num[1][0]!=0)
	{
		tt=num[1][0];
		i=2;
		while((c=getchar())!='\n')
		{
			cin>>num[i][0];
			tt+=num[i][0];
			i++;
		}
		l=i;
		p=0;
		if(tt!=0)
			p=1;
		for(i=0;i<l;i++)
			num[i][1]=0;
		for(i=1;i<l&&p==0;i++)
		{
			if(num[i][0]>0)
				continue;
			t=num[i][0];
			for(j=i+1;j<l&&p==0;j++)
			{
				t+=num[j][0];
				if(t==0)
				{
					num[i][1]=j;
					break;
				}
				if(t>0)
					p=1;
			}
		}
		for(i=1;i<l&&p==0;i++)
		{
			t=0;
			for(j=i+1;j<num[i][1];)
			{
				if(num[j][1]==0)
				{
					j++;
					continue;
				}
				t+=num[num[j][1]][0];
				j=num[j][1];
			}
			if(t>=num[num[i][1]][0]&&num[i][1]!=0)
				p=1;
		}
		if(p==0)
			cout<<":-) Matrioshka!\n";
		else
			cout<<":-( Try again.\n";
	}
	return 0;
}



