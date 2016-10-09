#include <iostream>
using namespace std;
int main()
{
	int h[100][100],a[100],b[100],n,i,j,t1,t2,p1,p2;
	while(cin>>n&&n)
	{
		t1=t2=p1=p2=0;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%d",&h[i][j]);
		for(i=0;i<n;i++)
		{
			a[i]=0;
			for(j=0;j<n;j++)
				a[i]+=h[i][j];
			if(a[i]%2!=0)
			{
				p1=i;
				t1++;
			}
		}
		for(i=0;i<n;i++)
		{
			b[i]=0;
			for(j=0;j<n;j++)
				b[i]+=h[j][i];
			if(b[i]%2!=0)
			{
				t2++;
				p2=i;
			}
		}
		if(t1>1||t2>1||t1%2!=t2%2)
			cout<<"Corrupt\n";
		else if(t1==0&&t2==0)
			cout<<"OK\n";
		else
			cout<<"Change bit ("<<p1+1<<","<<p2+1<<")\n";
	}
	return 0;
}

