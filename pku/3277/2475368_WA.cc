#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>



const		int		maxn=100001;


struct		rectangle
{
	__int64		minx,miny,maxx,maxy;
};

struct		treenode
{
	int				count;
	__int64			covered;	
};




int					n,max;
__int64				indexy[maxn*2];
__int64				ans;		
rectangle			q[maxn];
treenode			tree[maxn*4];

std::vector<std::pair<__int64,int> >	qx;

void	init()
{	
	int					i;
	__int64 x,y,z,ppp;
	std::vector<__int64>	hang,lie;	
	
	hang.clear();
	lie.clear();
	qx.clear();
	ans=0;
	max=0;
	memset(tree,0,sizeof(tree));

	
	scanf("%d",&n);
	
	for (i=1;i<=n;i++)
	{
		scanf("%I64d%I64d%I64d",&x,&y,&z);
		if(x>y)
		{
			ppp=y;
			y=x;
			x=ppp;
		}
		q[i].minx=0;
		q[i].miny=x;
		q[i].maxx=z;
		q[i].maxx=y;
		hang.push_back(q[i].minx);
		hang.push_back(q[i].maxx);
		lie.push_back(q[i].miny);
		lie.push_back(q[i].maxy);
		qx.push_back(std::make_pair<__int64,int>(q[i].minx,i));
		qx.push_back(std::make_pair<__int64,int>(q[i].maxx,-i));
	}	
	std::sort(qx.begin(),qx.end());		
	std::sort(hang.begin(),hang.end());
	std::sort(lie.begin(),lie.end());
	hang.resize(std::unique(hang.begin(),hang.end())-hang.begin());	
	lie.resize(std::unique(lie.begin(),lie.end())-lie.begin());
	
	for (i=1;i<=n;i++)
	{
		q[i].minx=std::lower_bound(hang.begin(),hang.end(),q[i].minx)-hang.begin();
		q[i].maxx=std::lower_bound(hang.begin(),hang.end(),q[i].maxx)-hang.begin();
		q[i].miny=std::lower_bound(lie.begin(),lie.end(),q[i].miny)-lie.begin();
		q[i].maxy=std::lower_bound(lie.begin(),lie.end(),q[i].maxy)-lie.begin();
		

		indexy[q[i].miny]=lie[q[i].miny];
		indexy[q[i].maxy]=lie[q[i].maxy];		
	}
	max=lie.end()-lie.begin()-1;
}

void	ins(int	l,int	r,int	b,int	e,int	current)
{
	if ((b<=l)&&(e>=r))
		tree[current].count++;
	else
	{
		if ((b<(l+r)>>1)&&(e>l))ins(l,(l+r)>>1,b,e,current*2);
		if ((e>(l+r)>>1)&&(b<r))ins((l+r)>>1,r,b,e,current*2+1);
	}
		
	if (tree[current].count)
		tree[current].covered=indexy[r]-indexy[l];
	else
		if (r-l==1)
			tree[current].covered=0;
		else
			tree[current].covered=tree[current*2].covered+tree[current*2+1].covered;	
}

void	del(int	l,int	r,int	b,int	e,int	current)
{
	if ((b<=l)&&(e>=r))
		tree[current].count--;
	else
	{
		if ((b<(l+r)>>1)&&(e>l))del(l,(l+r)>>1,b,e,current*2);
		if ((e>(l+r)>>1)&&(b<r))del((l+r)>>1,r,b,e,current*2+1);
	}
	
	if (tree[current].count)
		tree[current].covered=indexy[r]-indexy[l];
	else
		if (r-l==1)
			tree[current].covered=0;
		else
			tree[current].covered=tree[current*2].covered+tree[current*2+1].covered;
}


void	starmain()
{
	std::vector<std::pair<__int64,int> >::iterator	iter;
	
	ins(0,max,q[qx.begin()->second].miny,q[qx.begin()->second].maxy,1);
	iter=qx.begin()+1;
	while (iter!=qx.end())
	{
		ans+=tree[1].covered*(iter->first-(iter-1)->first);		
		if (iter->second>=0)
			ins(0,max,q[iter->second].miny,q[iter->second].maxy,1);
		else
			del(0,max,q[-iter->second].miny,q[-iter->second].maxy,1);
		iter++;
	}
}


void	outit()
{
	printf("%I64d\n",ans);
}

int		main()
{
//	freopen("c:\\data5.in","r",stdin);
	
	init();
	starmain();
	outit();
	
	return(0);
}