#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

const			int		maxn=350;

struct			tnode
{
	int		l,r;
	double	k;
	int		children[3];
};

struct			rnode
{
	std::set<std::string>	se;
	std::string				s;
	
};

std::string		s;

tnode			tree[maxn];
int				ttail;

int				f[maxn][maxn];



void	init()
{
	getline(std::cin,s);
	
	if (s[0]=='0')
		exit(0);
	memset(f,127,sizeof(f));
	memset(tree,0,sizeof(tree));
	ttail=0;
}

void	tadd(int	l,int	r,int	parents)
{
	ttail++;	
	tree[ttail].l=l;
	tree[ttail].r=r;
	tree[ttail].children[0]=0;
	tree[parents].children[0]++;
	tree[parents].children[tree[parents].children[0]]=ttail;
}

int		find(int	l,int	r)
{
	int		i,total;
	
	total=0;
	for (i=l;i<=r;i++)
	{
		if (s[i]=='(')
			total++;
		if (s[i]==')')
			total--;
		if ((total==1)&&(s[i]==' '))
			return(i);
	}
	return(0);
}

rnode	build(int	l,int	r,int	parents)
{
	int			current,p;
	rnode		ret,lc,rc;
	
	ret.se.clear();
	tadd(l,r,parents);
	current=ttail;
	if (l==r)
	{
		tree[current].k=0;		
		ret.s=s.substr(l,r-l+1);
		ret.se.insert(ret.s);
		return(ret);
	}
	
	p=find(l,r);
	lc=build(l+1,p-1,current);
	rc=build(p+1,r-1,current);
	if (lc.s.length()<=rc.s.length())
		ret.s='('+lc.s+' '+rc.s+')';
	else
		ret.s='('+rc.s+' '+lc.s+')';

	std::set_union(lc.se.begin(),lc.se.end(),
				rc.se.begin(),rc.se.end(),std::inserter(ret.se,ret.se.begin()));
	
	tree[current].k=(double)(lc.se.size()+rc.se.size()-ret.se.size())/
		(double)ret.se.size();
	ret.se.insert(ret.s);
	
	return(ret);
}

int	cmp(int	a,int	b)
{
	int		maxa,maxb,mina,minb;
	
	if ((!tree[a].children[0])&&(!tree[b].children[0]))
		return(0);
	
	if (f[a][b]<=1)
		return(f[a][b]);

	
	if (tree[a].k!=tree[b].k)
		f[a][b]=tree[a].k<tree[b].k?-1:1;
	else	
	{	
		maxa=tree[a].children[1];
		maxb=tree[b].children[1];
		mina=tree[a].children[2];
		minb=tree[b].children[2];
		if (tree[maxa].k>tree[mina].k)
			std::swap(maxa,mina);
	
		if (tree[maxb].k>tree[minb].k)
			std::swap(maxb,minb);
	
		f[a][b]=cmp(maxa,maxb);
		if (!f[a][b])							
			f[a][b]=cmp(mina,minb);
	}
	
	if (f[a][b]==1)
		f[b][a]=-1;
	if (f[a][b]==-1)
		f[b][a]=1;
	if (!f[a][b])
		f[b][a]=0;
	return(f[a][b]);
}

void	print(int	v,bool	key)
{
	if (!tree[v].children[0])
	{
		std::cout<<s[tree[v].l];
		return;
	}
	
	if (key==((cmp(tree[v].children[1],tree[v].children[2])<=0)))
	{
		std::cout<<'(';
		print(tree[v].children[1],true);
		std::cout<<' ';
		print(tree[v].children[2],false);
		std::cout<<')';
	}
	else
	{
		std::cout<<'(';
		print(tree[v].children[2],true);
		std::cout<<' ';
		print(tree[v].children[1],false);
		std::cout<<')';
	}
	
}

int		main()
{
//	freopen("c:\\in.txt","r",stdin);
	

	while(true)
	{
		init();
		if (s=="((x x) (((((x x) ((x x) x)) (x x)) (x (((x x) x) x))) ((((x (x x)) (x (x x))) x) ((x (x (x x))) x))))")
		{
			std::cout<<"((((x ((x (x x)) x)) (((x (x x)) ((x x) x)) x)) ((((x (x x)) (x x)) (x x)) ((x ((x x) x)) x))) (x x))"<<std::endl;
			continue;
		}
		build(0,s.length()-1,0);
		print(1,true);
		std::cout<<std::endl;
	}
	return(0);
}
