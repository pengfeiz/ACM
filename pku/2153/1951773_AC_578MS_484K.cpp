#include <iostream>
#include <string.h>
#include <algorithm>
#define MAX 10000
using namespace std;
struct node
{
    char c[31];
    int n;
}s[MAX];
int n,m;
bool com(const node &a,const node &b)
{
    return strcmp(a.c,b.c)<0;
}

void swap(int i,int j)
{
	char c[31];
	strcpy(c,s[i].c);
	strcpy(s[i].c,s[j].c);
	strcpy(s[j].c,c);
}
void qsort(int left,int right)
{ 
	int i=left,j=right,tmp=(left+right)/2;
    do{
        while(strcmp(s[i].c,s[tmp].c)<0&&i<right)
			i++;
        while(strcmp(s[j].c,s[tmp].c)>0&&j>left) 
			j--;
        if(i<=j)
		{
			swap(i,j);
            i++;
            j--;              
		}
    }while(i<=j);
    if(left<j) 
		qsort(left,j);
    if(i<right) 
		qsort(i,right);
}
int search(char c[31])
{
	int mid,l,r;
	l=0;
	r=n;
	mid=(l+r)/2;
	while(strcmp(c,s[mid].c)!=0)
	{
		if(strcmp(c,s[mid].c)>0)
			l=mid+1;
		else if(strcmp(c,s[mid].c)<0)
			r=mid;
		mid=(l+r)/2;
	}
	return mid;
}
int main()
{
	int i,num,x,t;
	char c[31];
	cin>>n;
	getchar();
	for(i=0;i<n;i++)
	{
		gets(s[i].c);
		s[i].n=0;
	}
	//qsort(0,n);
	sort(s,s+n,com);
	x=search("Li Ming");
	cin>>m;
	while(m-->0)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&num);
			getchar();
			gets(c);
			s[search(c)].n+=num;
		}
		for(i=t=0;i<n;i++)
			if(s[i].n>s[x].n)
				t++;
		cout<<t+1<<endl;
	}
	return 0;
}
