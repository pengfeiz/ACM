#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

#define maxn 50300

char ss[maxn];
int hash[maxn],sta[maxn];
int s[maxn],l;
int h[maxn],lcp[maxn][20];


int n;

int SA[maxn],sa[maxn],rank[maxn],rk[maxn],C[maxn];//SA存储排名



int main()
{
	int i,len,j,p,q,tt,t;
        char c[2];
        scanf("%s",&ss);
        l=strlen(ss);
        for(i=0;i<=l;i++)
            sta[i]=i;
        scanf("%d",&tt); 
	while(tt--)
        {
            scanf("%s",&c);
            if(c[0]=='I')
            {
                scanf("%s",&c);
                scanf("%d",&p);
                if(p>l)
                    p=l+1;
                for(i=l;i>=p-1;i--)
                    ss[i+1]=ss[i];
                ss[p-1]=c[0];
                l++;
                for(i=0;i<l;i++)
                    if(sta[i]>=p-1)
                        sta[i]++;
            }
            else
            {
                scanf("%d%d",&p,&q);
                p--;
                q--;
                if(p==q)
                    t=l-sta[p];
                else
                {
                    for(t=0;;t++)
                        if(ss[sta[p]+t]!=ss[sta[q]+t])
                            break;
                }
                printf("%d\n",t);

            }
        }
        return 0;
}

