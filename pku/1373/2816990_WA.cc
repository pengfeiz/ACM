#include <cstdio>

unsigned a,b,om,z;
int la,lb,lom,lz;

int n,f[100000];
char s[100000];

unsigned min(unsigned a,unsigned b)
{return a<b?a:b;}

#define ID(w,lw) ((w)+(1<<lw))
#define M(l) ((1<<(l))-1)

int can(unsigned z,int lz);
int cont(unsigned s,int ls,unsigned r,int lr)
{
	if(lr>la)
	{
		if((r&M(la))==a)
			if(cont(s,ls+1,r>>la,lr-la))
				return 1;
	}
	else
	{
		if((a&M(lr))==r)
			if(can(s,ls+1))
				return 1; 	
	}
	if(lr>lb)
	{
		if((r&M(lb))==b)
			if(cont(s|(1<<ls),ls+1,r>>lb,lr-lb))
				return 1;
	}
	else
	{
		if((b&M(lr))==r)
			if(can(s|(1<<ls),ls+1))
				return 1; 	
	}
	return 0;
}

int can(unsigned z,int lz)
{
	int i,id=ID(z,lz);
	if(f[id]==n)
		return s[id];
	f[id]=n;
	for(i=lom-lz;i>=0;i--)
	{
		if(z==((om>>i)&M(lz))) 
			return s[id]=1;
	}
	s[id]=0;
	for(i=min(la,lz);i>0;i--)
	{
		if((a>>(la-i))==(z&M(i)))
			if(cont(0,1,z>>i,lz-i))
				return s[id]=1;
	}  
	for(i=min(lb,lz);i>0;i--)
	{
		if((b>>(lb-i))==(z&M(i)))
			if(cont(1,1,z>>i,lz-i))
				return s[id]=1;
	}  
	return s[id]=0;
}

int myget(unsigned *xp,int *xlp)
{
	char s[32];
	unsigned x;
	int xl;
	if(!gets(s)) 
		return 0;
	x=0;
	for(xl=0;s[xl];xl++)
		x|=(s[xl]=='b')<<xl;
	*xp=x;
	*xlp=xl;
	return 1;
}	

int main()
{
	while(1)
	{
		n++;	
		if(!myget(&a, &la)) 
			break;
		if(!myget(&b, &lb)) 
			break;
		if(!myget(&om, &lom)) 
			break;
		if(!myget(&z, &lz)) 
			break;
		if(can(z,lz))
			printf("YES\n");
		else
			printf("NO\n");					
	}
	return 0;
}
