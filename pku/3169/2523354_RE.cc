#include<iostream>

using namespace std;
#define Max 1002
int ta,tb,a[Max],b[Max],c[Max],sa[Max],sb[Max],sc[Max],d[Max];
int n,maxa,maxb;
void bellman()
{
	int k=0,i;
   bool used=false;
   memset(d,0,sizeof(d));
   while(!used)
   {
	   k++;
	   if(k>n)
		   break;
	   used=true;
	   for(i=0;i<ta;i++)
	   {
		   if(d[b[i]]<d[a[i]]+c[i])
		   {
			   d[b[i]]=d[a[i]]+c[i];
			   used=false;
		   }
		 
	   }

		   for(i=0;i<tb;i++)
		   {
			   if(d[sb[i]]>d[sa[i]]+sc[i])
			   {
				   d[sa[i]]=d[sb[i]]-sc[i];
				   used=false;
			   }
			   
		   }

			 for(i=1;i<=n;i++)
				   if(d[i]<d[i-1])
				   {
					   used=false;
					   d[i]=d[i-1];
				   }


   }
   if(k>n)
	   cout<<-1<<endl;
   else if(d[n]==0)
	   cout<<-2<<endl;
   else
	   cout<<d[n]-d[1]<<endl;
   

}
int main()
{
	int i;
	scanf("%d%d%d",&n,&ta,&tb);
	for(i=0;i<ta;i++)
	{
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
		if(a[i]>b[i])
			swap(a[i],b[i]);
		//maxa=b[i]>maxa?b[i]:maxa;
	}
	for(i=0;i<tb;i++)
	{
		scanf("%d%d%d",&sa[i],&sb[i],&sc[i]);
		if(sa[i]>sb[i])
			swap(sa[i],sb[i]);
		//	maxb=b[i]>maxb?b[i]:maxb;
	}
   bellman();
	return 0;
}