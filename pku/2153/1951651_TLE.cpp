#include <iostream>
#include <string.h>
#define MAX 10000
using namespace std;
char s[MAX][31];
int n,m;
void swap(int i,int j)
{
	char c[31];
	strcpy(c,s[i]);
	strcpy(s[i],s[j]);
	strcpy(s[j],c);
}
void qsort(int left,int right)
{ 
	int i=left,j=right,tmp=(left+right)/2;
    do{
        while(strcmp(s[i],s[tmp])<0&&i<right)
			i++;
        while(strcmp(s[j],s[tmp])>0&&j>left) 
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
	while(strcmp(c,s[mid])!=0)
	{
		if(strcmp(c,s[mid])>0)
			l=mid+1;
		else if(strcmp(c,s[mid])<0)
			r=mid;
		mid=(l+r)/2;
	}
	return mid;
}
int main()
{
	int i,num,a[MAX]={0},x,t;
	char c[31];
	cin>>n;
	getchar();
	for(i=0;i<n;i++)
		gets(s[i]);
	qsort(0,n-1);
	x=search("Li Ming");
	cin>>m;
	while(m-->0)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&num);
			getchar();
			gets(c);
			a[search(c)]+=num;
		}
		for(i=t=0;i<n;i++)
			if(a[i]>a[x])
				t++;
		cout<<t+1<<endl;
	}
	return 0;
}
