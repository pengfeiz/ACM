//双向广搜加hash

#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>


//扫描层数为2
#define depth 2

using namespace std;

int n;

__int64 id(vector<int>x)
{
    int i;
    __int64 t=0;
    for(i=0;i<n;i++)
        t=t*15+x[i];
    return t;
}


map<__int64,int>bfs(vector<int>x)
{
    int i,j,k,ii;
    vector<int>y;
    
    map<__int64,int>res;
    res[id(x)]=0;
    queue<vector<int> >q;
    q.push(x);
    
    while(q.empty())
    {
        x=q.front();
        q.pop();
        for(i=0;i<n;i++)
            for(j=i+1;j<=n;j++)
                for(k=1;k<=n-j;k++)
                {
                    //原来可以这么用
                    y=x;
                    for(ii=i;ii<j;ii++)
                        y[ii+k]=x[ii];
                    for(ii=0;ii<k;ii++)
                        y[i+ii]=x[j+ii];
                    //统计有没有被用过
                    if(res.count(id(y)))
                        continue;
                    if((res[id(y)]=res[id(x)]+1)<depth)
                        q.push(y);
                }        
    }
    return res;
}


int main()
{
    int tt,t,i;
    scanf("%d",&tt);
    while(tt--)
    {
        t=5;
        scanf("%d",&n);
        //vector申请大小可以这样申请
        vector<int> x(n);
        for(i=0;i<n;i++)
            scanf("%d",&x[i]);
        vector<int>y=x;
        sort(y.begin(),y.end());
        
        map<__int64,int> d1=bfs(x);
        map<__int64,int> d2=bfs(y);        
        map<long long,int>::iterator it;
        for(it=d1.begin();it!=d1.end();it++) 
            if(d2.count(it->first)) 
                t=t<it->second+d2[it->first]?t:it->second+d2[it->first];
        if(t<5)
            printf("%d\n",t);
        else
            printf("5 or more\n");
    }
    return 0;
}
