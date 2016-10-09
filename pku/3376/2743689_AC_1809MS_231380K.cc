#include<stdio.h>
#include<string.h>
const int M=2000005;
char pos[M<<1],neg[M<<1];
int s[M];
int len[M];
bool flag1[M];
bool flag2[M];
int next[M];
int n;
const int CTNUM = 26;		//储存字母的数目
const int STRNUM = M<<1;	//节点数目，绝对不能少于给定的字符串数目，一般给大点
const int MINCHAR='a';		//大小写分辨，如果混用或者不连续的话需要有对应的hash函数
struct TRIE
{
	int son[CTNUM];
	int s;
	int t;
}trie[STRNUM];
int TNUM=1;
void init()
{
	memset(&trie[0],0,sizeof(TRIE));
	TNUM=1;
}
int Ins(char *str,int len,int start)
{
	int i;
	int cur=0; 
	for(i=0;i<len;i++)
	{
		if( flag1[start+i] )trie[cur].s++;
		if( !trie[cur].son[str[i]-MINCHAR] )
		{
			memset( &trie[TNUM],0,sizeof(TRIE) );
			cur=trie[cur].son[str[i]-MINCHAR]=TNUM++;
		}
		else cur=trie[cur].son[str[i]-MINCHAR];		
	}
	trie[cur].s++;
	trie[cur].t++;
	return cur;
}
int Read( char *str,int len,int start)
{
	int i;
	int re=0;
	int cur=0; 
	for(i=0;i<len;i++)
	{
		if( flag2[start+i] )re+=trie[cur].t;
		cur=trie[cur].son[str[i]-MINCHAR];
		if(!cur)
			return re;
	}
	re+=trie[cur].s;
	return re;
}
void getnext(char *b ,int nb,int *next)//求出有nb个元素的b数组的next
{
	int i=0,j=-1;
	next[0] = -1;
	while ( i < nb )
	{
		if ( b[i]==b[j] || j==-1 )
		{
			i++;
			j++;
			next[i] = j;//真正的next数组
		}
		else 
			j = next[j];
	}
}

void getflag(int cur,char *a,char *b,int na,int nb,bool *flag)
{
	getnext(b,nb,next);
	int i=0 , j=0 ;
	while ( i<na )
	{
		if ( a[i] == b[j] || j == -1 )
		{
			i++;
			j++;
		}
		else j=next[j];
	}	
	while(j)
	{
		flag[s[cur]+len[cur]-j]=1;
		j=next[j];
	}
}
void GetFlag(int cur)
{
	char *a=pos+s[cur],*b=neg+s[cur];
	int na=len[cur],nb=na;
	getflag(cur,a,b,na,nb,flag1);
	getflag(cur,b,a,nb,na,flag2);	
}


int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		int i,cur,j;
		for(i=0,cur=0;i<n;i++)
		{
			scanf("%d",&len[i]);
			scanf("%s",pos+cur);
			s[i]=cur;			
			for(j=0;j<len[i];j++)
				neg[cur+j]=pos[cur+len[i]-1-j];
			cur+=len[i]+1;
		}
		for(i=0;i<n;i++)
		{
			GetFlag(i);
			Ins(pos+s[i],len[i],s[i]);
		}
		__int64 re=0;
		for(i=0;i<n;i++)
			re+=Read(neg+s[i],len[i],s[i]);
		printf("%I64d\n",re);
	}
	return 0;
}
/*
3
2 ba
1 a
2 ab
4
1 a
2 ab
2 ba
1 a
4
9 abaabaaba
1 a
2 ab
2 ba

*/