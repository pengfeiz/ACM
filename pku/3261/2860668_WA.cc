#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

#define MAXN 20010

int s[MAXN],hash[MAXN];
int h[MAXN],lcp[MAXN][80];

int N, K;

int SA[MAXN],sa[MAXN],rank[MAXN],rk[MAXN],C[MAXN];

bool cmp(int a,int b)
{return s[a]<s[b];}
int minn(int a,int b)
{return a<b?a:b;}

void suffix_array()
{
	int i,j,k,r;
	for(i=0;i<N;i++)
		SA[i]=i;
	sort(SA,SA+N,cmp);
	rank[SA[0]]=0;
	for(i=1;i<N;i++)
	{
		j=SA[i-1],k=SA[i];
		rank[k]=s[k]==s[j]?rank[j]:rank[j]+1;
	}
	r=rank[SA[N-1]]+1;
	for(k=1;r<N;k*=2)
	{
		memset(C,0,sizeof(*C)*r);
		memcpy(rk,rank,sizeof(*rank)*N);
		for(i=0;i<N;i++)
			++C[rank[i]];
		for(i=1;i<r;i++)
			C[i]+=C[i-1];
		for(j=0;j<k;j++)
			sa[j]=N-j-1;
		for(i=0;i<N;i++ )
			if(SA[i]>=k)
				sa[j++]=SA[i]-k;
		for(i=N-1;i>=0;i--)
			SA[--C[rank[sa[i]]]]=sa[i];
		int a=-1,b=-1;
		r=-1;
		for(i=0;i<N;i++)
		{
			if(rk[SA[i]]!=a||rk[SA[i]+k]!=b)
			{
				++r;
				a=rk[SA[i]];
				b=SA[i]+k<N?rk[SA[i]+k]:-1;
			}
			rank[SA[i]]=r;
		}
		++r;
	}
}

void bulid_lcp(void)
{
	int i,j,k;
	for(k =0,i=0;i<N;i++)
	{
		if(rank[i]==N-1)
			h[rank[i]]=k=0;
		else
		{
			if(k>0)
				k--;
			for(j=SA[rank[i]+1];s[i+k]==s[j+k];k++);
			h[rank[i]]=k;
		}
	}
}


void lcp_rmq_initi()
{
	int i,j;
	for(i=0;i<N;i++)
		lcp[i][0]=h[i];
	for(j=1;(1<<j)<=N;j++)
	{
		for(i=0;i+(1<<j)-1<N;i++)
			lcp[i][j]=minn(lcp[i][j-1],lcp[i+(1<<(j-1))][j-1]);
	}
}

int get_lcp(int a,int b)
{
	int tmp,k;
	if(a==b)
		return N-a;
	if(a>b)
	{
		tmp=a;
		a=b;
		b=tmp;
	}
	k=(int)(log(b-a)/log(2));
	return minn(lcp[a][k],lcp[b-(1<<k)][k]);
}

int main()
{
	int i,res,max,len;
	while(scanf("%d%d",&N,&K)!=EOF)
	{
		for(i=0;i<N;i++)
		{
		//	scanf("%d",&s[i]);
                    s[i]=1;
			hash[i]=s[i];
		}
		sort(hash,hash+N);
		len=unique(hash,hash+N)-hash;
		for(i=0;i<N;i++)
			s[i]=lower_bound(hash,hash+len,s[i])-hash+1;
		suffix_array();
		bulid_lcp();
		lcp_rmq_initi();
		max=-1;
		for(i=0;i+K-1<N;i++)
		{
			res=get_lcp(i,i+K-1);
			if(res>max)
				max=res;
		}
		printf("%d\n",max);
	}
	return 0;
}
