// by  wpt


#include <iostream>
using namespace std;

const int maxm=40;
const int mm=1000010;

int n;
int a1[maxm],a2[maxm],b[maxm];
int tim[mm],next[mm],q[mm];
bool mark[mm],mb[maxm];

void flip(int *a,int k)
{
    for(int i=0,j=k-1;i<j;i++,j--)
    {
        int temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }
}

void put(int *a,int state,int k)
{
    int pp[maxm],kt[maxm],pom,i,j;
    memset(pp,0,sizeof(pp));
    for(i=k-1;i>-1;i--)
    {
        kt[i]=state%(k-i);
        state/=k-i;
    }
    for(i=0;i<k;i++)
    {
	pom=kt[i];
	for(j=0;j<k && pom>0;j++) 
            if(!pp[j]) 
                pom--;
	while(pp[j])
            j++;
	a[i]=j;
	pp[j]=1;
    }
}    
int get(int a[],int k)
{
    int pp[maxm];
    memset(pp,0,sizeof(pp));
    int ans=0;
    for(int i=0;i<k;i++)
    {
        int pop=0;
        for(int j=0;j<a[i];j++) 
            if(!pp[j]) 
                pop++;
        ans=ans*(k-i)+pop;
        pp[a[i]]=1;
    }     
    return ans;
}

void set()
{
    int v=0,qe=0,qs=0;
    int a[9]={1,2,3,4,5,6,7,8,9};
    memset(mark,0,sizeof(mark));
    mark[v]=true;
    next[v]=-1;
    q[qe++]=v;
    while(qs<qe)
    {
        int t=q[qs++];
        put(a,t,9);
        for(int i=1;i<=9;i++)
        {
            flip(a,i);
            int temp=get(a,9);
            if(!mark[temp])
            {
                q[qe++]=temp;
                next[temp]=t;
                tim[temp]=i;
                mark[temp]=true;
              
            }
            flip(a,i);
        }
    }
}

bool ini()
{
    int i;
    scanf("%d",&n);
    if(n==0)
        return false;
    for(i=0;i<n;i++)
        scanf("%d",&a1[i]);
    for(i=0;i<n;i++)
        scanf("%d",&a2[i]);
    return true;
}
void solve()
{
    int i,j,tt;
    memset(mb,0,sizeof(mb));
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            if(!mb[j]&&a1[i]==a2[j])
                break;
        mb[j]=true;
        b[i]=j;
    }
    while(n!=9&&n>0)
    {
        
        for(i=0;i<n;i++)
            if(b[i]==n-1)
                break;
        
        flip(b,i+1);
        flip(b,n);
        if(i+1!=1)
            printf("%d ",i+1);
        if(n!=1)
            printf("%d ",n);
        n--;
    }
    if(n==9)
    {
        tt=get(b,n);
        while(next[tt]!=-1)
        {
            if(tim[tt]>1)
                printf("%d ",tim[tt]);
            tt=next[tt];
        }
    }
    printf("\n");
}
int main()
{
    set();
    while(ini())
        solve();
    return 0;
}
