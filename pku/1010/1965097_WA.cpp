#include <iostream>
using namespace std;
#define MAX 1000
long a[26],n,m,b[MAX];
int main()
{
	int i,j[4],t,x,mm[3],h[4],k,p,q,oo[4];
	n=0;
	while(cin>>b[n])
	{
		if(b[n]==0)
		{
			m=0;
			while(cin>>a[m])
			{
				if(a[m]==0)
					break;
				m++;
			}
			n++;
			for(i=0;i<m;i++)
			{
				memset(h,0,4);
				mm[0]=mm[1]=mm[2]=q=0;
				for(j[0]=0;j[0]<n&&q==0;j[0]++)
					for(j[1]=j[0];j[1]<n&&q==0;j[1]++)
						for(j[2]=j[1];j[2]<n&&q==0;j[2]++)
							for(j[3]=j[2];j[3]<n&&q==0;j[3]++)
								if(b[j[0]]+b[j[1]]+b[j[2]]+b[j[3]]==a[i])
								{
									for(k=t=0;k<4;k++)
										if(b[j[k]]!=0)
											t++;
									for(k=0;k<4;k++)
										oo[k]=j[k];
									for(k=0;k<3;k++)
									{
										for(p=k+1;p<4;p++)
											if(oo[p]==oo[k]&&b[oo[p]]!=0)
												oo[p]=n-1;
									}
									for(k=x=0;k<4;k++)
										if(b[oo[k]]!=0)
											x++;
									if(x>mm[0])
									{
										mm[0]=x;
										mm[1]=t;
										mm[2]=0;
										for(p=0;p<4;p++)
										{
											h[p]=b[j[p]];
											if(h[p]>mm[2])
												mm[2]=h[p];
										}
									}
									else if(x==mm[0])
									{
										if(t<mm[1])
										{
											mm[1]=t;
											mm[2]=0;
											for(p=0;p<4;p++)
											{
												h[p]=b[j[p]];
												if(h[p]>mm[2])
													mm[2]=h[p];
											}
										}
										else if(t==mm[1])
										{
											for(p=0;p<4;p++)
												if(mm[2]<b[j[p]])
													break;
											if(p<4)
											{
												mm[2]=0;												
												for(p=0;p<4;p++)
												{
													h[p]=b[j[p]];
													if(h[p]>mm[2])
														mm[2]=h[p];
												}
											}
											else
												q=1;
										}
									}
								}
				if(q==1)
					cout<<a[i]<<" ("<<mm[0]<<"): tie\n";
				else if(mm[0]==0)
					cout<<a[i]<<" ---- none\n";
				else
				{
					cout<<a[i]<<" ("<<mm[0]<<"):";
					for(k=0;k<mm[1];k++)
							cout<<" "<<h[k];
					cout<<endl;
				}
			}
			n=-1;
		}
		n++;
	}
	return 0;
}

