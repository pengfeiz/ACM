#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

#define maxn 2000


char ss[maxn];
int hash[maxn];
int s[maxn];
int h[maxn],lcp[maxn][20];

int n,ll;

int SA[maxn],sa[maxn],rank[maxn],rk[maxn],C[maxn];

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
        for(i=0;i<n;i++)
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


void bulid_lcp()
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

void lcp_rmp_initi()
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

int main()
{
//	freopen("in.txt","r",stdin);
    int i,j,len,maxx,xx,p;
    while(scanf("%s",ss)!=EOF)
    {
        n=maxx=0;
        ll=strlen(ss);
        for(j=0;j<ll;j++)
            hash[n++]=ss[j];
        sort(hash,hash+n);
        len=unique(hash,hash+n)-hash;
        n=0;
        for(j=0;j<ll;j++)
            s[n++]=lower_bound(hash,hash+len,ss[j])-hash+1;
        suffix_array();
        bulid_lcp();
        lcp_rmp_initi();
		printf("%d\n",ll);
		for(i=0;i<ll;i++)
			printf("%3d",SA[i]);
		printf("\n");
		for(i=0;i<ll;i++)
			printf("%3d",h[i]);
		printf("\n");
		for(i=0;i<ll-1;i++)
		{
			xx=get_lcp(i,i+1);
			if(xx>maxx)
			{
				p=SA[i];
				maxx=xx;
			}
		}
		printf("%d\n",maxx);
		ss[p+maxx]='\0';
		printf("%s\n",ss+p);
    }
    return 0;
}

