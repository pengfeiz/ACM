#include<cstdio>
#include<string>
int main()
{
	char s1[11],s2[11],f[10],index[10],l,n,j,i,flag,h;
	int ans,tmp;
	while(1)
	{
		scanf("%s",s1);
		if(s1[0]=='#') break;
		scanf("%s",s2);
		l=strlen(s1);
		for(i=0;i<10;i++) f[i]=-1;
		ans=n=i=h=0;
		while(i<l)
		{
			flag=0;
			for(;i<l;i++)
			{
				if(s1[i]=='?') {index[n]=i++; break;}
				else if(!flag&&s1[i]<s2[i]) {flag=1; f[n]=0; continue;}
				else if(!flag&&s1[i]>s2[i]) {flag=1; f[n]=1; continue;}
			}
			if(s1[i-1]=='?') n++;
		}
		for(j=index[n-1]+1;j<l;j++)
		{
			if(s1[j]>s2[j]) {h=1; break;}
			else if(s1[j]<s2[j]) break;
		}
		if(!n)
		{
			if(f[0]==1) puts("1");
			else puts("0");
			continue;
		}
		for(i=0;i<n;i++)
		{
			if(f[i]==0) break;
			else if(f[i]==1)
			{
				tmp=1;
				for(j=i;j<n;j++) tmp*=10;
				ans+=tmp; break;
			}
			else
			{
				tmp=9-(s2[index[i]]-'0');
				if(i==n-1) tmp+=h;
				else if(tmp>0)
				{
					for(j=i+1;j<n;j++) tmp*=10;
				}
				ans+=tmp;
			}
		}
		printf("%d\n",ans);
	}
}
