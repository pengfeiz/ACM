#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;


#define maxm 4010
#define maxn 210

char ss[maxm][maxn];
int hash[maxm*maxn];
int ff[maxm];
struct gao
{
    int n,m;
}s[maxm*maxn];
int h[maxn*maxm],lcp[maxn*maxm][20];

int n,m,ll[maxm];

int SA[maxn*maxm],sa[maxn*maxm],rank[maxn*maxm],rk[maxn*maxm],C[maxn*maxm];

bool cmp(int a,int b)
{return s[a].m<s[b].m;}
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
            rank[k]=s[k].m==s[j].m?rank[j]:rank[j]+1;
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
            for(j=SA[rank[i]+1];s[i+k].m==s[j+k].m;k++);
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
    char cc[210];
    char ccc[210];
    int i,len,j,t,maxx,k;
    while(scanf("%d",&m),m)
    {
        n=0;
        for(i=0;i<m;i++)
        {
            scanf("%s",ss[i]);
            ll[i]=strlen(ss[i]);
            for(j=0;j<ll[i];j++)
                hash[n++]=ss[i][j];
            hash[n++]=-1-i;
        }
        sort(hash,hash+n);
        len=unique(hash,hash+n)-hash;
        n=0;
        for(i=0;i<m;i++)
        {
            for(j=0;j<ll[i];j++)
            {
                s[n].n=i;
                s[n++].m=lower_bound(hash,hash+len,ss[i][j])-hash+1;
            }
            s[n].n=i;
            s[n++].m=lower_bound(hash,hash+len,-1-i)-hash+1;
        }    
        suffix_array();
        bulid_lcp();
        lcp_rmp_initi();
        maxx=0;
        memset(ff,0,sizeof(ff));
        t=0;
        for(i=j=0;i<n&&j<n;)
        {
            while(t<m&&j<n)
            {
                if(!ff[s[SA[j]].n])
                    t++;
                ff[s[SA[j]].n]++;
                j++;
            }
            while(1)
            {
                if(ff[s[SA[i]].n]>1)
                {
                    ff[s[SA[i]].n]--;
                    i++;
                }
                else  break;
            }
            if(i<j-1&&t==m)
                len=get_lcp(i,j-1);
            else len=0;
            if(len>maxx)
            {
                maxx=len;
                for(k=0;k<len;k++)
                {
                    cc[k]=hash[s[SA[i]+k].m-1];
                }
                cc[len]='\0';
            }
            else if(maxx==len)
            {
                for(k=0;k<len;k++)
                {
                    ccc[k]=hash[s[SA[i]+k].m-1];
                }
                ccc[len]='\0';
                if(strcmp(cc,ccc)>0)
                    strcpy(cc,ccc);
            }
            while(t>=m)
            {
                if(ff[s[SA[i]].n]==1)
                    t--;
                ff[s[SA[i]].n]--;
                i++;
            }
        }
        if(maxx)
            printf("%s\n",cc);
        else
            printf("IDENTITY LOST\n");
    }
    return 0;
}

