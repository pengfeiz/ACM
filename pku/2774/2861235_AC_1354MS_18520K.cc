#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

#define maxn 200100

char ss[2][maxn];
char hash[maxn];
int s[maxn];
int h[maxn],lcp[maxn][20];


int n,m,ll[maxn];

int SA[maxn],sa[maxn],rank[maxn],rk[maxn],C[maxn];//SA存储排名

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
		return n-a;
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
	int i,len,j,t,maxx;
        m=2;
//	while(scanf("%d",&m)!=EOF)
                n=0;
		for(i=0;i<m;i++)
		{
			scanf("%s",&ss[i]);
                        ll[i]=strlen(ss[i]);
                        for(j=0;j<=ll[i];j++)
                            hash[n++]=ss[i][j];
		}
		sort(hash,hash+n);
		len=unique(hash,hash+n)-hash;
                n=0;
		for(i=0;i<m;i++)
                {
                    for(j=0;j<=ll[i];j++)
			s[n++]=lower_bound(hash,hash+len,ss[i][j])-hash+1;
                }
		suffix_array();		
                bulid_lcp();
		lcp_rmq_initi();
		maxx=0;
                for(i=0;i<n;i++)
                {
                    if(SA[i]<=ll[0]&&SA[i+1]<=ll[0])
                        continue;
                    else if(SA[i]>=ll[0]&&SA[i+1]>=ll[0])
                        continue;
                    else
                    {			
                       t=get_lcp(i,i+1);
			if(t>maxx)
				maxx=t;
                    }
                }
 //               for(i=0;i<n;i++)
   //                 printf("%c%d ",hash[s[SA[i]]-1],SA[i]);
  //              printf("\n");
                printf("%d\n",maxx);
	return 0;
}
