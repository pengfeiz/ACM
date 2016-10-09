#include <stdio.h>
#include <algorithm>

using namespace std;

char w[1000][11];
int button[26],ans,best[27],n,B,L,flag[26];
__int64 a[1000];

void clac(int &s1,int &s2) 
{
	int i,j;
	__int64 t;
	s1=0;
	s2=0;
	flag[B]=100;
	for(i=0,j=0;i<L;i++) 
	{
		if(i==flag[j])
			j++;
		button[i]=j+1;
	}
	for(i=0;i<n;i++) 
	{
		t=0;
		for(j=0;w[i][j];j++)
			t=((t<<5)|button[w[i][j]-'A']);
		a[i]=t;
	}
	sort(a,a+n);
	for(i=0;i<n;i=j) 
	{
		for(j=i+1;j<n&&a[i]==a[j];j++)
			;
		s1++;
		s2+=(j==i+1);
	}
	return ;
}

void search(int k,int ch) 
{
	int s1,s2,i;
	if(ans==n)
		return;
	if(k==B-1) 
	{
		clac(s1,s2);
		if(s2>ans) 
		{
			ans=s2;
			for(i=0;i<L;i++)
				best[i]=button[i];
		}
		return;
	}
	for(i=L-(B-k);i>=ch;i--) 
	{
		flag[k]=i+1;
		search(k+1,i+1);
	}
}

int main() 
{
	int i;
	scanf("%d%d%d",&B,&L,&n);	
	for(i=0;i<n;i++ )
		scanf("%s",w+i);	
	ans=0;
	search(0,0);
	printf("%d\n",ans);
	for(i=0;i<L;i++) 
	{
		printf("%c",'A'+i);
		if(best[i]!=best[i+1])
			printf("\n");
	}
	return 0;
}