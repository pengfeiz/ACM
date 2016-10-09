#include <iostream>
#include <math.h>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
using namespace std;
#define MAX 13
long a[MAX],b[MAX];
int main()
{
//	ifstream cin("input.txt");
//	ofstream cout("output.txt");
	long i,j,t,q;
	memset(a,0,sizeof(long)*MAX);
	memset(b,0,sizeof(long)*MAX);
	a[0]=a[1]=a[2]=b[0]=b[1]=0;
	
	for(i=3;i<MAX;i++)
	{
		t=j=0;
		t=a[i-1]*9+a[i-2]*9;
		b[i-1]=(long)pow(10,(i-3)*1.0);
		a[i]=t+b[i-1];
	}
	long n,nn;
	scanf("%ld",&nn);
//	nn=97500;
	while(nn-->0)
	{
		scanf("%ld",&n);
//		n=nn;
		j=t=0;		
		while(a[j]<n)
			j++;
		j--;
		q=j;
		while(j>=0)
		{
			if(n<=6*a[j])
			{
				i=0;
				while(n>a[j])
				{
					i++;
					n-=a[j];
				}
				cout<<i;
				j--;
				t=0;
				q=j;
				continue;
			}
			n-=6*a[j];
			if(t==0)
			{
				if(n<=9*a[j-1]+9*a[j-2]+b[j])
				{
					cout<<6;
					t++;
					j--;
					continue;
				}
				n-=9*a[j-1]+9*a[j-2]+b[j];
			}
			if(t==1)
			{
				if(n<=9*a[j-1]+b[j+1])
				{
					cout<<6;
					j--;
					t++;
					continue;
				}
				n-=9*a[j-1]+b[j+1];
			}
			if(t==2)
			{
				if(n<=b[j+2])
				{
					cout<<6;
					if(q-2)
						cout<<setw(j)<<setfill('0')<<n-1;
					break;
				}
				n-=b[j+2];
			}
			i=7;
			while(n>a[j])
			{
				i++;
				n-=a[j];
			}
			cout<<i;
			j--;
			t=0;
			q=j;
		}				
		cout<<endl;
	}
	return 0;
}
	