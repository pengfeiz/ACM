#include <iostream>
#include <queue>
using namespace std;
char s[10005];int l,m,y;queue<int> v[10005];void dfs(int d)
{if(d>y)y=d;v[d].push(l);if(s[l]>='a'&&s[l]<='z'){l--;return;}l--;dfs(d+1);dfs(d+1);}int main(){int n,i;scanf("%d",&n);while(n--){m=y=0;scanf("%s",s);l=strlen(s)-1;dfs(1);for(i=y;i>0;i--)while(!v[i].empty()){printf("%c",s[v[i].front()]);v[i].pop();}printf("\n");}return 0;}

