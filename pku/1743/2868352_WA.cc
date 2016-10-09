#include<cstdio>
#include<cstdlib>
#include<cstring>
#include <iostream>
using namespace std;
#define LimitN 300000
#define TC 300000
typedef struct  node    *point;
struct  node
{
        point   pl,sl;
        point   chd,bro;
        int     l,r,dep;
        int     max,min;
};
char    s[LimitN+1];
int     n;
int     ans;
point   root;
void    init()
{
        int     i,x,y;
        //scanf("%d",&n);
        scanf("%d",&x);
        for (i=1;i<n;i++)
        {
                scanf("%d",&y);
                s[i]=y-x;
                x=y;
        }
        s[n]=TC;
}
void    AddChild(point &p,point q)
{
        q->bro=p;
        p=q;
}
point   FindChild(point p,char x)
{
        if (!p->chd)
                return  0;
        for (p=p->chd;p&&s[p->l]!=x;p=p->bro);
        return  p;
}
void    RemoveChild(point &p,char x)
{
        if (s[p->l]==x)
        {
                point   q=p->bro;
                p->bro=0;
                p=q;
        }
        else    RemoveChild(p->bro,x);
}
point   ST_NewNode()
{
        point   q;
        q=new struct node;
        q->pl=q->sl=q->chd=q->bro=0;
        return  q;
}
point   ST_Split(point p,int j)
{
        point   q;
        q=ST_NewNode();
        q->l=p->l;
        q->r=j-1;
        q->pl=p->pl;
        RemoveChild(q->pl->chd,s[q->l]);
        AddChild(q->pl->chd,q);
        q->dep=q->pl->dep+j-q->l;
        AddChild(q->chd,p);
        p->pl=q;
        p->l=j;
        return  q;
}
point   ST_Insert(point p,int l,int r)
{
        point   q;
        int     j;
        while ((l<=r)&&(q=FindChild(p,s[l])))
        {
                for (j=q->l;l<=r&&j<=q->r&&s[l]==s[j];l++,j++);
                if (j>q->r)
                        p=q;
                else
                {
                        p=ST_Split(q,j);
                        break;
                }
        }
        if (l<=r)
        {
                q=ST_NewNode();
                q->l=l;
                q->r=r;
                q->pl=p;
                q->dep=p->dep+r-l+1;
                AddChild(p->chd,q);
        }
        return  p;
}
point   ST_Find(point p,int l,int r)
{
        while (l<=r)
        {
                p=FindChild(p,s[l]);
                if (r-l<p->r-p->l)
                        return  ST_Split(p,p->l+r-l+1);
                l+=p->r-p->l+1;
        }
        return  p;
}
void    ST_Construction()
{
        point   p;
        int     i;
        root=ST_NewNode();
        root->l=0;
        root->r=-1;
        root->dep=0;
        p=root;
        for (i=1;i<n;i++)
        {
                if (p==root)
                        p=ST_Insert(p,i,n);
                else
                {
                        if (!p->sl)
                        {
                                if (p->pl==root)
                                        p->sl=ST_Find(root,p->l+1,p->r);
                                else    p->sl=ST_Find(p->pl->sl,p->l,p->r);
                        }
                        p=p->sl;
                        p=ST_Insert(p,i+p->dep,n);
                }
        }
}
void    dfs(point i)
{
        if (i->r==n)
        {
                i->min=i->max=i->dep;
        }
        else
        {
                point   j,k;
                i->max=0x80808080;
                i->min=0x7f7f7f7f;
                for (j=i->chd;j;k=j->bro,delete j,j=k)
                {
                        dfs(j);
                        if ((j->max)>(i->max))
                                i->max=j->max;
                        if ((j->min)<(i->min))
                                i->min=j->min;
                }
                if ((i->max)-(i->min)>(i->dep))
                        if ((i->dep)>ans)
                                ans=i->dep;
        }
}
void    show()
{
        printf("%d\n",ans>3?ans+1:0);
}
int     main()
{

        while(cin>>n&&n!=0)
        {
        init();
        ST_Construction();
        dfs(root);
        show();
        }//system("pause");

        
        
        return  0;
}
