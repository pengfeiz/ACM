#include <iostream>
#include <limits>
using namespace std;

#define MAXN 100000

int data[MAXN];

struct Node
{
	int s, t, max, min;
	Node *l, *r;
}*head;

void build(int s, int t, Node *&p)
{
	p = new Node;
	p->s = s, p->t = t, p->max = -INT_MAX, p->min = INT_MAX;
	if(s == t)
	{
		p->max = p->min = data[s];
		p->l = p->r = NULL;
		return ;
	}
	int m = (s + t) / 2;
	build(s, m, p->l);
	build(m + 1, t, p->r);

	p->max = max(p->l->max, p->r->max);
	p->min = min(p->l->min, p->r->min);
}

int minv, maxv;

void query(int s, int t, Node *p)
{
	if(t < p->s || s > p->t) return ;
	if(s <= p->s && t >= p->t)
	{
		minv = min(minv, p->min);
		maxv = max(maxv, p->max);
		return ;
	}
	query(s, t, p->l);
	query(s, t, p->r);
}

int main()
{
	int i, s, t, n, Q;
	while(scanf("%d %d", &n, &Q) != EOF)
	{
		for(i = 1; i <= n; i++) scanf("%d", data + i);

		build(1, n, head);

		for(i = 1; i <= Q; i++)
		{
			scanf("%d %d", &s, &t);
			maxv = -INT_MAX, minv = INT_MAX;
			query(s, t, head);
			printf("%d\n", maxv - minv);
		}
	}
	return 0;
}
