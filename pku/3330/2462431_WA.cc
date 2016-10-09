#include<cstdio>
#include<string>
#include<iostream>
#include<set>

std::string		s;

struct	dnode
{
	std::set<std::string>		se;
	std::string					s,out;
	double						k;
	
};

void	init()
{
	char	ts[350];
	gets(ts);
	s=ts;
	if (ts[0]=='0')
		exit(0);

}

int		find(std::string	s)
{
	int		i,total;
	
	total=0;
	
	for (i=0;i<(int)s.length();i++)
	{
		if (s[i]=='(')
			total++;
		if (s[i]==')')
			total--;
		if (!total)
			return(i+1);
	}
	return(-1);
}

std::string	left(std::string	s)
{	
	int		p;
	
	if (s[0]=='(')
				s=s.substr(1,s.length()-2);
		
	
	p=find(s);
	s=s.substr(0,p);
	if (s[0]==' ')
		s=s.substr(1,s.length()-1);
	
	return(s);	
}

std::string	right(std::string	s)
{
	int		p;
	
	if (s[0]=='(')
				s=s.substr(1,s.length()-2);
	
	p=find(s);
	s=s.substr(p+1,s.length()-p);	
	if (s[0]==' ')
		s=s.substr(1,s.length()-1);


	
	return(s);	
}

dnode	dfs(std::string	s,bool	key)
{
	dnode			l,r,ret;
	std::string		lc,rc;
	
	
	ret.se.clear();
	
	if (s.length()==1)
	{
		ret.s=s;
		ret.se.insert(s);
		ret.k=0;
		return(ret);
	}
	
	lc=left(s);
	rc=right(s);

	
	l=dfs(lc,true);
	r=dfs(rc,false);
	std::set_union(l.se.begin(),l.se.end(),
			r.se.begin(),r.se.end(),std::inserter(ret.se,ret.se.begin()));
	
	ret.k=(double)ret.se.size()/(double)(l.se.size()+r.se.size());
	
	if (l.s.length()<r.s.length())		
		ret.s='('+l.s+' '+r.s+')';
	else
		ret.s='('+r.s+' '+l.s+')';

		
	
	
		
	if (key)	
		if (l.k<r.k)
			ret.out='('+lc+' '+rc+')';
		else
			ret.out='('+rc+' '+lc+')';			
	else
		if (l.k>r.k)
			ret.out='('+lc+' '+rc+')';		
		else
			ret.out='('+rc+' '+lc+')';
		
	
	return(ret);
}



int			main()
{
	dnode		t;


//	freopen("c:\\in.txt","r",stdin);
	
	while (true)
	{
		init();
		t=dfs(s,true);
		std::cout<<t.s<<std::endl;
	}
	
	return(0);
}
