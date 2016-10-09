#include <iostream>
using namespace std;
int a[6],time;
int main()
{
	int i,t,b[5];
	time=0;
	while(cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]&&(a[0]||a[1]||a[2]||a[3]||a[4]||a[5]))
	{
		if(time)
			cout<<endl;
		time++;
		cout<<"Collection #"<<time<<":\n";
		t=0;
		for(i=1;i<6;i++)
		{
			a[i]%=12;
			t+=a[i]*(i+1);
		}
		t+=a[0];
		if(t%2==1)
		{
			cout<<"Can't be divided.\n";
			continue;
		}
		t=0;
		for(b[0]=0;b[0]<=a[1]&&t==0;b[0]++)
			for(b[1]=0;b[1]<=a[2]&&t==0;b[1]++)
				for(b[2]=0;b[2]<=a[3]&&t==0;b[2]++)
					for(b[3]=0;b[3]<=a[4]&&t==0;b[3]++)
						for(b[4]=0;b[4]<=a[5]&&t==0;b[4]++)
							if(abs(2*(b[0]*2+b[1]*3+b[2]*4+b[3]*5+b[4]*6)-a[1]*2-a[2]*3-a[3]*4-a[4]*5-a[5]*6)<=a[0])
								t=1;
		if(t==0)
			cout<<"Can't be divided.\n";
		else
			cout<<"Can be divided.\n";
	}
	return 0;
}
