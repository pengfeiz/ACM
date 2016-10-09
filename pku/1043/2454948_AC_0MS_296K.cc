#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

struct gao
{
	char name[21];
	int id;
}c[20];

int n,m;
char id[20][21],op,str[21];
bool in[20],g[20][20];

bool com(gao a,gao b)
{return strcmp(a.name,b.name)<0;}


int dosth(bool vc[][20],int nv1,int nv2)
{
	int i,j,x,n;
	int q[20],prev[20],qs,qe;
	int vm1[20],vm2[20];

	n=0;
	for(i=0;i<nv1;i++)
		vm1[i]=-1;
	for(i=0;i<nv2;i++)
		vm2[i]=-1;
	for(i=0;i<nv1;i++)
	{
		for(j=0;j<nv2;j++)
			prev[j]=-2;
		qs=qe=0;
		for(j=0;j<nv2;j++)
			if(vc[i][j])
			{
				prev[j]=-1;
				q[qe++]=j;
			}
		while(qs<qe)
		{
			x=q[qs];
			if(vm2[x]==-1)
				break;
			qs++;
			for(j=0;j<nv2;j++)
				if(prev[j]==-2&&vc[vm2[x]][j])
				{
					prev[j]=x;
					q[qe++]=j;
				}
		}
		if(qs==qe)
			continue;
		while(prev[x]>-1)
		{
			vm1[vm2[prev[x]]]=x;
			vm2[x]=vm2[prev[x]];
			x=prev[x];
		}
		vm2[x]=i;
		vm1[i]=x;
		n++;
	}
	return n;
}

int main()
{
	int i,j;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>id[i];
	m=0;
	cin>>op;
	std::fill(g[0],g[0]+20*n,true);
	std::fill(in,in+n,false);
	while(op!='Q')
	{
		cin>>str;
		if (op=='E')
		{
			for(i=0;i<m&&strcmp(c[i].name, str);i++);
			if(i==m){
				strcpy(c[i].name, str);
				c[i].id=-1;
				m++;
			}
			in[i]=true;
		}
		else if(op=='L')
		{
			for(i=0;i<m&&strcmp(c[i].name,str);i++);
			in[i]=false;
		}
		else
		{
			for(i=0;i<n&&strcmp(id[i], str); i++);
			for(j=0;j<n;j++)
				if(!in[j])
					g[i][j]=false;
		}
		cin>>op;
	}
	for(i=0;i<m;i++)
	{
		c[i].id=-1;
		for(j=0;j<n&&c[i].id==-1;j++)
		{
			if(g[j][i])
			{
				g[j][i]=false;
				if(dosth(g,n,m)<m)
					c[i].id=j;
				g[j][i]=true;
			}
		}
	}
	sort(c,c+m,com);
	for(i=0;i<n;i++)
	{
		cout<<c[i].name<<":";
		if(c[i].id==-1)
			cout<<"???";
		else
			cout<<id[c[i].id];
		cout<<endl;
	}
	return 0;
}