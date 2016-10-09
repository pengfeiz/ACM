#include<cstdio>
#include<string>
const int M=1<<17;
bool flag[M<<1]={0};
bool tree[M<<1]={0};
bool ops[M<<1]={0};
int ll,rr;

void Color(int num,int l,int r,int pos)
{
	if(l>=r)
            return;
	if(ll>=r||rr<=l)
            return ;
	int mid=(l+r)>>1;
	int p1=(pos<<1)+1;
	int p2=(pos<<1)+2;
	if(num<2)
	{
		if(ll<=l&&rr>=r)
		{
			tree[pos]=num;
			flag[pos]=1;
			ops[pos]=0;
			return ;
		}
		if(flag[pos])
		{
			if(ops[pos])
			{
				tree[pos]=!tree[pos];
				ops[pos]=0;
			}
			flag[p1]=flag[p2]=1;
			flag[pos]=0;
			tree[p1]=tree[p2]=tree[pos];
			ops[p1]=ops[p2]=0;
		}
		else 
		{
			ops[p1]^=ops[pos];
			ops[p2]^=ops[pos];
			ops[pos]=0;
		}
		Color(num,l,mid,p1);
		Color(num,mid,r,p2);
		return ;
	}

	if(ll<=l&&rr>=r)
	{
		ops[pos]=!ops[pos];
		return ;
	}
	if(flag[pos])
	{
		flag[p1]=flag[p2]=1;
		flag[pos]=0;
		tree[p1]=tree[p2]=tree[pos];
		ops[p1]=ops[p2]=ops[pos];
		ops[pos]=0;
	}
	ops[p1]^=ops[pos];
	ops[p2]^=ops[pos];
	ops[pos]=0;
	Color(num,l,mid,p1);
	Color(num,mid,r,p2);
}

bool arr[M];
void getarr(int l,int r,int pos)
{
	int i;
	if(flag[pos])
	{
		if(ops[pos])
		{
			tree[pos]=!tree[pos];
			ops[pos]=0;
		}
		for(i=l;i<r;i++)
			arr[i]=tree[pos];
		return ;
	}
	int mid=(l+r)>>1;
	int p1=(pos<<1)+1;
	int p2=(pos<<1)+2;
	ops[p1]^=ops[pos];
	ops[p2]^=ops[pos];
	ops[pos]=0;
	getarr(l,mid,p1);
	getarr(mid,r,p2);
}

void print(int l,int r)
{
	if(l&1)printf("(%d",l>>1);
	else printf("[%d",l>>1);
	printf(",");
	if(r&1)printf("%d]",r>>1);
	else printf("%d)",r>>1);
}

void output()
{
	int first=1;
	int i,j;
	getarr(0,M,0);
	for(i=0;i<M;i++)
	{
		if(!arr[i])continue;
		for(j=i+1;j<M;j++)
			if(!arr[j])break;
		if(!first)
			printf(" ");
		else first=0;
		print(i,j);
		i=j;
	}
	if(first)
            printf("empty set");
	printf("\n");
}

void set(int a,int b,int num)
{
	ll=a;
	rr=b;
	Color(num,0,M,0);
}

int main()
{
	char pa,pb,op;
	int ta,tb,a,b;
	flag[0]=1;
	while(1)
	{
		if(scanf("%c",&op)==EOF)
                    break;
		if(op=='\n')
                    continue;
		scanf(" %c%d,%d%c",&pa,&ta,&tb,&pb);
		if(pa=='[')
                    a=ta<<1;
		else 
                    a=(ta<<1)+1;
		if(pb==']')
                    b=(tb<<1)+1;
		else 
                    b=tb<<1;
		switch(op)
		{
		case 'U':set(a,b,1);break;
		case 'I':set(0,a,0);set(b,M,0);break;
		case 'D':set(a,b,0);break;
		case 'C':set(0,a,0);set(b,M,0);set(a,b,2);break;
		case 'S':set(a,b,2);break;
		default:return 0;
		}
	}
	output();
	return 0;
}