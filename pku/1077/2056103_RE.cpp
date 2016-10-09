#include <iostream>
using namespace std;
bool a[9][8][7][6][5][4][3][2];
int n;
char c[100];
bool judge(int b[])
{
	int i,y[8],j,t;
	for(i=0;i<8;i++)
	{
		t=0;
		for(j=i+1;j<9;j++)
			if(b[i]>b[j])
				t++;
		y[i]=t;
	}
	if(a[y[0]][y[1]][y[2]][y[3]][y[4]][y[5]][y[6]][y[7]])
		return false;
	a[y[0]][y[1]][y[2]][y[3]][y[4]][y[5]][y[6]][y[7]]=true;
	return true;
}
bool dosth(int b[],int x)
{
	int i;
	if(x==8)
	{
		for(i=0;i<8;i++)
			if(b[i]!=i+1)
				break;
		if(i==8)
			return true;
	}
	if(x>2)
	{
		i=b[x-3];
		b[x-3]=b[x];
		b[x]=i;
		x-=3;
		if(judge(b))
		{
			if(dosth(b,x))
			{
				c[n++]='u';
				return true;
			}
		}
		i=b[x+3];
		b[x+3]=b[x];
		b[x]=i;
		x+=3;
	}
	if(x<6)
	{
		i=b[x+3];
		b[x+3]=b[x];
		b[x]=i;
		x+=3;
		if(judge(b))
		{
			if(dosth(b,x))
			{
				c[n++]='d';
				return true;
			}
		}
		i=b[x-3];
		b[x-3]=b[x];
		b[x]=i;
		x-=3;
	}
	if(x%3>0)
	{
		i=b[x-1];
		b[x-1]=b[x];
		b[x]=i;
		x--;
		if(judge(b))
		{
			if(dosth(b,x))
			{
				c[n++]='l';
				return true;
			}
		}
		i=b[x+1];
		b[x+1]=b[x];
		b[x]=i;
		x++;
	}
	if(x%3<2)
	{
		i=b[x+1];
		b[x+1]=b[x];
		b[x]=i;
		x++;
		if(judge(b))
		{
			if(dosth(b,x))
			{
				c[n++]='r';
				return true;
			}
		}
		i=b[x-1];
		b[x-1]=b[x];
		b[x]=i;
		x--;
	}
	return false;
}		

int main()
{
	int i,b[9],x;
	char s;
	memset(a,0,sizeof(a));
	n=0;
	for(i=0;i<9;i++)
	{
		cin>>s;
		if(s=='x')
		{
			b[i]=0;
			x=i;
		}
		else
			b[i]=s-'0';
	}
	judge(b);
	if(!dosth(b,x))
		printf("unsolvable");
	else
		for(i=n-1;i>=0;i--)
			printf("%c",c[i]);
	printf("%\n");
	return 0;
}