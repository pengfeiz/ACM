#include <iostream>
using namespace std;

const int maxn=3001;
const int min_NaN=0x80000000;
const int max_NaN=0x7fffffff;

int heap_num[maxn],heap_n;

int maxx(int a,int b,int c)
{
	int x;
	x=a>b?a:b;
	return x>c?x:c;
}

//������
void change(int x)
{	
	int max_num,xx=x;

	while(1)
	{
		max_num=maxx(heap_num[xx],heap_num[xx<<1],heap_num[(xx<<1)+1]);

		if(max_num==heap_num[xx<<1])
		{
			swap(heap_num[xx<<1],heap_num[xx]);
			xx=xx<<1;
		}	
		else if(max_num==heap_num[(xx<<1)+1])
		{
			swap(heap_num[(xx<<1)+1],heap_num[xx]);
			xx=(xx<<1)+1;
		}
		else break;

	}
}

//������
void build_heap(int x)
{
	if(x>heap_n)
		return;
	build_heap(x<<1);
	build_heap((x<<1)+1);
	change(x);
}


//����ֻ��Ҫÿ�ε����ٵ���
void heap_output(int x,int heap_nn)
{

//����ע�����Ԫ����ʱ����Ҫ����
	heap_n--;
	printf("%d ",heap_num[x]);
	if(heap_nn>1)
	{
		heap_num[x]=heap_num[heap_nn];
		heap_num[heap_nn]=-1;
		change(x);
	}
}


//����
void heap_insert(int x)
{
	heap_n++;
	int i=heap_n;
	while(i>1)
	{
		heap_num[i]=heap_num[i>>1];
		i=i>>1;
	}
	heap_num[1]=x;
	change(1);
}


//ɾ��
void heap_delete(int x)
{
	heap_num[x]=heap_num[heap_n];
	heap_num[heap_n]=-1;
	heap_n--;
	change(x);
}


int main()
{
	int i,x;

	heap_n=20;
printf("%d",maxx(3,14,11));
	memset(heap_num,0xff,sizeof(heap_num));

//��������	
	for(i=1;i<=heap_n;i++)
	{
		heap_num[i]=rand()%heap_n;
	}


	printf("�������\n");
	for(i=1;i<=heap_n;i++)
		printf("%d ",heap_num[i]);
	printf("\n\n");

//������
	build_heap(1);

	
	printf("�ѣ�\n");
	for(i=1;i<=heap_n;i++)
		printf("%d ",heap_num[i]);
	printf("\n\n");

//�������Ԫ��
	while(scanf("%d",&x),x>=0)
	{
		heap_insert(x);
		printf("�¶ѣ�\n");
		for(i=1;i<=heap_n;i++)
			printf("%d ",heap_num[i]);
		printf("\n\n");
	}

//����ɾ��Ԫ��
	while(scanf("%d",&x),x)
	{
		heap_delete(x);
		printf("�¶ѣ�\n");
		for(i=1;i<=heap_n;i++)
			printf("%d ",heap_num[i]);
		printf("\n\n");
	}


//������
	printf("������\n");
	for(i=heap_n;i>=1;i--)
		heap_output(1,i);
	printf("\n\n");

	return 0;
}
