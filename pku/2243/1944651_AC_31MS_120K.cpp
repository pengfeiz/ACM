#include <iostream>
using namespace std;
int main()
{
	char c[2],s[2];
	int x1,x2,y1,y2,t,a[8][8],i,j,k,he[8][2]={1,2,2,1,1,-2,2,-1,-1,-2,-2,-1,-1,2,-2,1};
	while(cin>>c>>s)
	{
		t=0;
		x1=c[0]-'a';
		y1=c[1]-'1';
		x2=s[0]-'a';
		y2=s[1]-'1';
		for(i=0;i<8;i++)
			for(j=0;j<8;j++)
				a[i][j]=-1;
		a[x1][y1]=t;
		while(a[x2][y2]==-1)
		{
			for(i=0;i<8;i++)
				for(j=0;j<8;j++)
				{
					if(a[i][j]==t)
					    for(k=0;k<8;k++)
							if(i+he[k][0]>=0&&i+he[k][0]<8&&j+he[k][1]>=0&&j+he[k][1]<8&&a[i+he[k][0]][j+he[k][1]]==-1)
								a[i+he[k][0]][j+he[k][1]]=t+1;
				}
			t++;
		}
		cout<<"To get from "<<c<<" to "<<s<<" takes "<<t<<" knight moves."<<endl;
	}
	return 0;
}


		
