#include<cstdio>
#include<list>
#include<string>

#define maxn 10001

struct	tnode
{
	int				parents;
	std::string		name;	
	std::list<int>	children;
};

tnode tree[maxn];
int	ttail;

int	tsearch(std::string	name)
{
//	return(table.lower_bound(nnode(name,0))->index);
	int	i;
	for(i=0;i<=ttail;i++)
		if(tree[i].name==name)
			return(i);
}

void engage(std::string	boss,std::string employee)
{
	int	t;	
	t=tsearch(boss);
	ttail++;
	tree[ttail].name=employee;
	tree[ttail].parents=t;
	tree[ttail].children.clear();
	tree[t].children.push_back(ttail);
}

void print(int v,int total)
{
	std::list<int>::iterator	iter;
	int							i;
	
	for (i=1;i<=total;i++)
		printf("+");
	printf("%s\n",tree[v].name.c_str());
	for(iter=tree[v].children.begin();iter!=tree[v].children.end();iter++)
		print(*iter,total+1);		
}

void fire(std::string employee)
{
	int							current,t;
	std::list<int>::iterator	iter;
	
	current=tsearch(employee);
	while(!tree[current].children.empty())
	{		
		t=*tree[current].children.begin();
		tree[current].name=tree[t].name;
		current=t;
	}
	t=tree[current].parents;
	for(iter=tree[t].children.begin();iter!=tree[t].children.end();iter++)
		if(*iter==current)
			break;
	tree[t].children.erase(iter);
}

char t[100];
void init()
{
	std::string	s;	
	tree[0].name="root";
	tree[0].children.clear();
	ttail=0;	
	gets(t);
	s=t;
	engage("",s);
}

void starmain()
{
	std::string	s,s1;
	while(!feof(stdin))
	{
		scanf("%s\n",t);
		s=t;
		if(s=="print")
		{
			print(1,0);
			printf("------------------------------------------------------------\n");
			continue;
		}
		if(s=="fire")
		{
			scanf("%s\n",t);
			s=t;
			fire(s);
			continue;
		}
		scanf("%s\n",t);
		scanf("%s\n",t);
		s1=t;
		engage(s,s1);
	}
}

int	main()
{
	init();
	starmain();
	return(0);
}
