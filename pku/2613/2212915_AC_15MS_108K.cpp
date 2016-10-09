#include <iostream>
using namespace std;

double p,q,r,s,a1,a2;

void dosth()
{
	double t,qq,ss,pp,rr;
	if(q>p/2)
		q=p-q;
	if(s>r/2)
		s=r-s;
	pp=p;
	rr=r;
	qq=q;
	ss=s;
	t=1.0;
	for(;pp>(p-q)&&rr>(r-s);pp--,rr--)
		t*=pp/rr;
	for(;pp>(p-q)&&qq>0;pp--,qq--)
		t*=pp/qq;
	for(;qq>0&&ss>0;qq--,ss--)
		t*=ss/qq;
	for(;ss>0&&rr>(r-s);ss--,rr--)
		t*=ss/rr;
	for(;qq>0&&ss>0;ss--,qq--)
		t*=ss/qq;
	printf("%.5lf\n",t);
}

int main()
{
	while(scanf("%lf%lf%lf%lf",&p,&q,&r,&s)!=EOF)
		dosth();
	return 0;
}