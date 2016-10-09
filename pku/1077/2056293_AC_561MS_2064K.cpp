#include <iostream>
using namespace std;
bool a[362880];
int n,b[9],w[]={1,1,2,6,24,120,720,5040,40320},he[362880][2];
char c[362880];

int change(int n)
{
	int i,t,ju,aa[9],j;
	memset(aa,0,sizeof(aa));
	for(i=0;i<9;i++)
	{
		t=n/w[8-i];
		ju=0;
		for(j=0;j<9;j++)
		{
			if(aa[j]==1)
				continue;
			if(ju==t)
				break;
			if(aa[j]==0)
				ju++;
		}
		aa[j]=1;
		b[i]=j;
		n%=w[8-i];
	}
	for(i=0;i<9;i++)
		if(b[i]==8)
			return i;
	return -1;
}

int judge()
{
	int y=0,t,i,j;
	for(i=0;i<8;i++)
	{
		for(j=i+1,t=0;j<9;j++)
			if(b[i]>b[j])
				t++;
		y+=t*w[8-i];
	}
	return y;
}

int dosth()
{
	int t,x=0,p,q,i,j;
	n=1;
	while(!a[0])
	{
		t=0;
		for(i=x;i<n;i++)
		{
			p=change(he[i][1]);
			if(p>2)
			{
				j=b[p-3];
				b[p-3]=b[p];
				b[p]=j;
				q=judge();
				if(!a[q])
				{
					a[q]=true;
					he[n+t][0]=i;
					he[n+t][1]=q;
					c[n+t]='u';
					t++;
				}
				if(q==0)
					return n+t;
				j=b[p-3];
				b[p-3]=b[p];
				b[p]=j;
			}
			if(p<6)
			{
				j=b[p+3];
				b[p+3]=b[p];
				b[p]=j;
				q=judge();
				if(!a[q])
				{
					a[q]=true;
					he[n+t][0]=i;
					he[n+t][1]=q;
					c[n+t]='d';
					t++;
				}
				if(q==0)
					return n+t;
				j=b[p+3];
				b[p+3]=b[p];
				b[p]=j;
			}
			if(p%3>0)
			{
				j=b[p-1];
				b[p-1]=b[p];
				b[p]=j;
				q=judge();
				if(!a[q])
				{
					a[q]=true;
					he[n+t][0]=i;
					he[n+t][1]=q;
					c[n+t]='l';
					t++;
				}
				if(q==0)
					return n+t;
				j=b[p-1];
				b[p-1]=b[p];
				b[p]=j;
			}
			if(p%3<2)
			{
				j=b[p+1];
				b[p+1]=b[p];
				b[p]=j;
				q=judge();
				if(!a[q])
				{
					a[q]=true;
					he[n+t][0]=i;
					he[n+t][1]=q;
					c[n+t]='r';
					t++;
				}
				if(q==0)
					return n+t;
				j=b[p+1];
				b[p+1]=b[p];
				b[p]=j;
			}
		}
		if(t==0)
			return -1;
		x=n;
		n+=t;
	}
	return -1;
}		

int main()
{
//	freopen("in.txt","r",stdin);
	char s,ss[1000];
	int i,j;
	memset(a,0,sizeof(a));
	for(i=0;i<9;i++)
	{
		cin>>s;
		if(s=='x')
			b[i]=8;
		else
			b[i]=s-'1';
	}
	w[judge()]=true;
	he[0][1]=judge();
	he[0][0]=-1;
	j=dosth();
	if(j==-1)
	{
		printf("unsolvable\n");
		return 0;
	}
	j--;
	n=0;
	while(j!=0)
	{
		ss[n++]=c[j];
		j=he[j][0];
	}
	for(i=n-1;i>=0;i--)
		printf("%c",ss[i]);
	printf("%\n");
	return 0;
}