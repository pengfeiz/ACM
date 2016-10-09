#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct gao
{
    char s[15];
    int c[1010];
}a[1010];

int out[1010];
vector<int> tre[1010];
int n,m,t;


void dfs(int x)
{
    int i;
    vector<int>::iterator p;
    for(p=tre[x].begin();p<tre[x].end();p++)
    {
        dfs(*p);
        for(i=1;i<=t;i++)
            a[x].c[i]+=a[*p].c[i-1];
    }
}

bool com(gao a,gao b)
{
    if(a.c[t]!=b.c[t])
        return a.c[t]>b.c[t];
    return strcmp(a.s,b.s)<0;
}


int main()
{
  //  freopen("in.txt","r",stdin);
    int tt,i,j,p,q,k,tim=0;
    char cc[15];
    
    scanf("%d",&tt);
    while(tt--)
    {
        
        for(i=0;i<1010;i++)
            tre[i].clear();
        m=0;
        memset(out,0,sizeof(out));
        scanf("%d%d",&n,&t);
        for(i=0;i<n;i++)
        {
            scanf("%s",cc);
            for(k=0;k<m;k++)
                if(strcmp(cc,a[k].s)==0)
                    break;
            q=k;
            if(k==m)
            {
                memset(a[m].c,0,sizeof(*a[m].c)*(t+1));
                a[m].c[0]=1;
                strcpy(a[m++].s,cc);
            }
            scanf("%d",&p);
            for(j=0;j<p;j++)
            {
                scanf("%s",cc);
                for(k=0;k<m;k++)
                    if(strcmp(a[k].s,cc)==0)
                        break;
                out[k]++;
                if(k==m)
                {
                    memset(a[m].c,0,sizeof(*a[m].c)*(t+1));
                    a[m].c[0]=1;
                    strcpy(a[m++].s,cc);
                }
                tre[q].push_back(k);
            }
        }    
        
        if(m>t)
        {
            for(i=0;i<m;i++)
                if(out[i]==0)
                    dfs(i);
            sort(a,a+m,com);
            a[m].c[t]=-1;

            printf("Tree %d:\n",++tim);
            for(i=0;i<3&&i<m;i++)
            {
                if(a[i].c[t]==0)
                    break;
                printf("%s %d\n",a[i].s,a[i].c[t]);
                while(i>=2&&a[i].c[t]==a[i+1].c[t])
                {
                    i++;
                    printf("%s %d\n",a[i].s,a[i].c[t]);
                }
            }
            printf("\n");
        }
        else
            printf("Tree %d:\n\n",++tim);
    }
    return 0;
}

