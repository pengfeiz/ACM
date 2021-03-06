#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

#define maxn 20100

int ss[maxn];
int hash[maxn];
int s[maxn];
int h[maxn],lcp[maxn][20];


int n,m,ll[maxn];

int SA[maxn],sa[maxn],rank[maxn],rk[maxn],C[maxn];//SA存储排名,rank是第i个排名多少

bool cmp(int a,int b)
{return s[a]<s[b];}
int minn(int a,int b)
{return a<b?a:b;}


void suffix_array()
{
	int i,j,k,r,a,b;
	for(i=0;i<n;i++)
		SA[i]=i;
	sort(SA,SA+n,cmp);
	rank[SA[0]]=0;
	for(i=1;i<n;i++)
	{
		j=SA[i-1],k=SA[i];
		rank[k]=s[k]==s[j]?rank[j]:rank[j]+1;
	}
	r=rank[SA[n-1]]+1;
	for(k=1;r<n;k*=2)
	{
		memset(C,0,sizeof(*C)*r);
		memcpy(rk,rank,sizeof(*rank)*n);
		for(i=0;i<n;i++)
			++C[rank[i]];
		for(i=1;i<r;i++)
			C[i]+=C[i-1];
		for(j=0;j<k;j++)
			sa[j]=n-j-1;
		for(i=0;i<n;i++ )
			if(SA[i]>=k)
				sa[j++]=SA[i]-k;
		for(i=n-1;i>=0;i--)
			SA[--C[rank[sa[i]]]]=sa[i];
		a=-1,b=-1,r=-1;
		for(i=0;i<n;i++)
		{
			if(rk[SA[i]]!=a||rk[SA[i]+k]!=b)
			{
				++r;
				a=rk[SA[i]];
				b=SA[i]+k<n?rk[SA[i]+k]:-1;
			}
			rank[SA[i]]=r;
		}
		++r;
	}
}

void bulid_lcp(void)
{
	int i,j,k;
	for(k=0,i=0;i<n;i++)
	{
		if(rank[i]==n-1)
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
    for(i=0;i<n;i++)
        lcp[i][0]=h[i];
    for(j=1;(1<<j)<=n;j++)
    {
        for(i=0;i+(1<<j)-1<n;i++)
            lcp[i][j]=minn(lcp[i][j-1],lcp[i+(1<<(j-1))][j-1]);
    }
}

int get_lcp(int a,int b)
{
    int tmp,k;
    if(a==b)
	return n-SA[a];
    if(a>b)
    {
	tmp=a;
	a=b;
	b=tmp;
    }
    k=(int)(log(b-a)/log(2));
    return minn(lcp[a][k],lcp[b-(1<<k)][k]);
}

bool judge(int mid)
{
    int i,l,t;
    l=n-mid;
    for(i=0;i<l-1;i++)
    {
        if(get_lcp(i,i+mid)>=mid)
            return true;
    }
    return false;
}

int main()
{
    int i,len,j,a,b,mid;
    while(scanf("%d",&n),n)
    {
	for(i=0;i<n;i++)
            scanf("%s",&ss[i]);
        for(i=1;i<n;i++)
            ss[i-1]=ss[i]-ss[i-1];
        for(j=0;j<n;j++)
            hash[j]=ss[j];
	sort(hash,hash+n);
	len=unique(hash,hash+n)-hash;
        for(j=0;j<n;j++)
            s[j]=lower_bound(hash,hash+len,ss[j])-hash+1;
       //这里将多个字符串结尾处理成不同
	suffix_array();	
        bulid_lcp();
	lcp_rmq_initi();
        a=4,b=n;
        while(a<b)
        {
            mid=(a+b)/2;
            if(judge(mid))
                a=b+1;
            b=mid;
        }
        printf("%d\n",a+1);
    }
    return 0;
}
    

