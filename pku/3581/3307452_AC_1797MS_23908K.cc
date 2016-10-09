#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

#define maxn 200200


int ss[maxn],sss[maxn];
int hash[maxn];
int s[maxn];
int h[maxn],lcp[maxn][20],nn,n;

int ll;

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


int main()
{
//	freopen("in.txt","r",stdin);
    int i,j,len;
    scanf("%d",&nn);

	for(i=nn-1;i>=0;i--)
		scanf("%d",&sss[i]);
//

		ll=nn-2;
		for(i=0;i<ll;i++)
			ss[i]=sss[i+2];
		n=0;

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

	for(i=SA[0];i<n;i++)
		printf("%d\n",ss[i]);

//	
		ll=nn-(n-SA[0])-1;
		for(i=0;i<ll;i++)
			ss[i]=sss[i+1];	
		ss[ll]=sss[0];
		ll++;
		n=0;

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


//		printf("\n");
		if(SA[0]!=n-1)
		{
			for(i=SA[0];i<n-1;i++)
				printf("%d\n",ss[i]);

			printf("%d\n",sss[0]);
			for(i=0;i<SA[0];i++)
				printf("%d\n",ss[i]);
		}
		else
		{
			for(i=SA[1];i<n-1;i++)
				printf("%d\n",ss[i]);		
			printf("%d\n",sss[0]);
			for(i=0;i<SA[1];i++)
				printf("%d\n",ss[i]);
		}

    return 0;
}

