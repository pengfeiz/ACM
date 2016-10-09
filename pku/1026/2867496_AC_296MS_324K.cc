#include<iostream.h>
const int M=201;
int place[M];
int n,m;
int tim[M];
char out[M];
void k()
{
	int i;
		for(i=1;i<n+1;i++)
			cin>>place[i];
		for(i=1;i<n+1;i++)tim[i]=0;
		for(i=1;i<n+1;i++)
		{
			int k0=i,k=place[i],t0=1;
			if(tim[i])continue;
	 	    while(k!=k0)
			{
		     	k=place[k];
			    t0++;
			}
		    tim[k]=t0;
	    	k=place[k];
	    	while(k!=k0)
			{
		    	tim[k]=t0;
				k=place[k];
			}
		}
}
int main()
{
	while(cin>>n&&n)
	{
		int i;k();
		while(cin>>m&&m)
		{
			for(i=1;i<n+1;i++)
			{
				out[i-1]=' ';
			}
			char c;
			c=cin.get();
                        int k=1;
			c=cin.get();
			while(c!='\n')
			{
				int m0=m%tim[k];
				int q,k0=k;
				for(q=0;q<m0;q++)
				{
					k0=place[k0];
				}
				out[k0-1]=c;
				c=cin.get();
				k++;
			}
			out[n]=0;
			cout<<out<<endl;
		}
		cout<<endl;
	}
	return 0;
}

