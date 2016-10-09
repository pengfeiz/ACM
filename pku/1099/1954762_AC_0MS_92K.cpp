#include <iostream>
using namespace std;
int main()
{
	int m,i,j,t,a[11][11],b[11],p=0;
	while(cin>>m&&m)
	{
		p++;
		cout<<"Case "<<p<<":\n\n";
		for(i=0;i<m;i++)
		{
			b[i]=0;
			for(j=0;j<m;j++)
				cin>>a[i][j];
		}
		for(i=1;i<4*m+4;i++)
			cout<<"*";
		cout<<endl;
		for(i=0;i<m-1;i++)
		{
			cout<<"*";
			for(j=t=0;j<m;j++)
			{
				t+=a[i][j];
				b[j]+=a[i][j];
				if(t==0&&a[i][j]==0)
					cout<<"H-O";
				else if(t==0&&a[i][j]==-1)
					cout<<"O";
				else if(t==1&&a[i][j]==1)
					cout<<"H-O-H";
				else if(t==1)
					cout<<"O-H";
				if(j!=m-1)
					cout<<" ";
				else
					cout<<"*\n";
			}
			cout<<"*";
			for(j=0;j<m;j++)
			{
				cout<<"  ";
				if(b[j]==0)
					cout<<"|";
				else cout<<" ";
				cout<<" ";
			}
			cout<<" *\n";
			cout<<"*";
			for(j=0;j<m;j++)
				cout<<"  H ";
			cout<<" *\n";
			cout<<"*";
			for(j=0;j<m;j++)
			{
				if(b[j]==1)
					cout<<"  | ";
				else
					cout<<"    ";
			}
			cout<<" *\n";
		}
		cout<<"*";
		for(j=t=0;j<m;j++)
		{
			t+=a[i][j];
			b[j]+=a[i][j];
			if(t==0&&a[i][j]==0)
				cout<<"H-O";
			else if(t==1&&a[i][j]==1)
				cout<<"H-O-H";
			else if(t==1)
				cout<<"O-H";
			if(j!=m-1)
				cout<<" ";
			else
				cout<<"*\n";
		}
		for(i=1;i<4*m+4;i++)
			cout<<"*";
		cout<<endl<<endl;
	}
	return 0;
}


