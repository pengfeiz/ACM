#include<cstdio>
#include<algorithm>

const	int		rule[3][2]={{0,1},{0,-1},{1,0}};
const	int		maxn=1000001;


int		n;
int		graph[2][maxn][3];
int		sx,sy,ex,ey;

void	init()
{
	int	i;
	
	scanf("%d\n",&n);
	
	if (!n)
		exit(0);	
	
	scanf("%d %d %d %d\n",&sx,&sy,&ex,&ey);

	for (i=0;i<n;i++)
		scanf("%d",&graph[0][i][0]);
	scanf("\n");
	for (i=1;i<=n;i++)
		graph[0][i][1]=graph[0][i-1][0];
	
	for (i=0;i<=n;i++)
	{
		scanf("%d",&graph[0][i][2]);
		graph[1][i][2]=graph[0][i][2];
	}
	
	for (i=0;i<n;i++)
		scanf("%d",&graph[1][i][0]);
	scanf("\n");
	for (i=1;i<=n;i++)
		graph[1][i][1]=graph[1][i-1][0];
}

struct	hnode
{
	int		x,y,w;	
};

hnode	heap[maxn*2];
int		htail;
int		index[2][maxn];

inline	void	affirm(int	pos)
{
	index[heap[pos].x][heap[pos].y]=pos;
}

void	up(int	pos)
{
	hnode	t;
	t=heap[pos];
	
	while (t.w<heap[pos>>1].w)
	{
		heap[pos]=heap[pos>>1];
		affirm(pos);
		pos>>=1;
	}
	heap[pos]=t;
	affirm(pos);
}

void	erase()
{
	int		current,next;
	hnode	t;
	
	index[heap[1].x][heap[1].y]=-1;
	
	if (htail==1)
	{
		htail--;
		return;
	}
	
	t=heap[htail];	
	current=1;
	htail--;
	
	while (current*2<=htail)
	{
		next=current*2;
		
		if ((next+1<=htail)&&(heap[next+1].w<heap[next].w))
			next++;
		
		if (heap[next].w<t.w)
		{
			heap[current]=heap[next];
			affirm(current);
			current=next;
		}
		else
			break;
	}	
	heap[current]=t;
	affirm(current);	
}

void	starmain()
{
	hnode	head;
	int		i,x,y,w;
	
	
	memset(index,0,sizeof(index));	
	htail=1;
	heap[0].w=-1;
	heap[1].x=sx;
	heap[1].y=sy;
	heap[1].w=0;
	affirm(1);
	
	while ((heap[1].x!=ex)||(heap[1].y!=ey))
	{
		head=heap[1];
		erase();
		
		for (i=0;i<3;i++)
		{
			x=(head.x+rule[i][0])&1;
			y=head.y+rule[i][1];
			if ((y>=0)&&(y<=n))
			{
				w=head.w+graph[head.x][head.y][i];
				if (!index[x][y])
				{
					htail++;
					heap[htail].x=x;
					heap[htail].y=y;
					heap[htail].w=w;
					up(htail);
				}
				else	if ((index[x][y]>0)&&(w<heap[index[x][y]].w))
				{
					heap[index[x][y]].w=w;
					up(index[x][y]);
				}	
			}
		}		
	}
	
	printf("%d\n",heap[1].w);
}
int		main()
{
//	freopen("c:\\in.txt","r",stdin);
	
	while (true)
	{
		init();
		starmain();
	}
	
	return(0);
}

