main(){int m,n,t;scanf("%d%d",&m,&n);{if(n>m){t=n;n=m;m=t;}if(n==1||n==2)printf("%d\n",(m+1)/2);else if(n%3==0 || m%3==0) printf("2\n");else printf("1\n");}}
