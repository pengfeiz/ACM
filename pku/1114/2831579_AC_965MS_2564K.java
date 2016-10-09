import java.io.*;
import java.util.*;

public class Main{
	static HashSet<String> all=new HashSet<String>();
	static ArrayList<String> tt=new ArrayList<String>();
	static HashMap<String,Long> ana(String s)
	{
		StringTokenizer str=new StringTokenizer(s,"+");
		HashMap<String,Long> tot=new HashMap<String,Long>(),temp;
		while(str.hasMoreTokens())
		{
			String ss=str.nextToken();
			temp=get(ss);
			tot=add(tot,temp);
		}
		return tot;
	}
	
	static HashMap<String,Long> add(HashMap<String,Long> a,HashMap<String,Long> b)
	{
		HashMap<String,Long> tot=new HashMap<String,Long>();
		for(int i=0;i<tt.size();i++)
		{
			boolean has=false;
			long temp=0;
			if(a.containsKey(tt.get(i)))
			{
				has=true;
				temp+=a.get(tt.get(i));
			}
			if(b.containsKey(tt.get(i)))
			{
				has=true;
				temp+=b.get(tt.get(i));
			}
			if(has)
				tot.put(tt.get(i), temp);
		}
		return tot;
	}
	static HashMap<String,Long> mul(Long k,HashMap<String,Long> a)
	{
		HashMap<String,Long> tot=new HashMap<String,Long>();
		for(int i=0;i<tt.size();i++)
			if(a.containsKey(tt.get(i)))
				tot.put(tt.get(i), a.get(tt.get(i))*k);
		return tot;
	}
	static HashMap<String,Long> get(String s)
	{
		HashMap<String,Long> tot=new HashMap<String,Long>();
		if(s==null||s.length()<1)
			return tot;
		if(s.charAt(0)>='0'&&s.charAt(0)<='9')
		{
			int kk=0;
			while(kk<s.length()&&s.charAt(kk)>='0'&&s.charAt(kk)<='9')
				kk++;
			String temp1=s.substring(0, kk),temp2=s.substring(kk, s.length());
			return tot=mul(Long.parseLong(temp1),get(temp2));
		}
		else
		{
			if(s.charAt(0)=='(')
			{
				int num=1,kk=1;
				while(kk<s.length())
				{
					if(s.charAt(kk)=='(')
						num++;
					if(s.charAt(kk)==')')
						num--;
					if(num==0)
						break;
					kk++;
				}
				if(kk==s.length()-1)
					if(1<kk)
						return tot=get(s.substring(1, kk));
					else
						return tot;
				else
				{
					if(s.charAt(kk+1)>='0'&&s.charAt(kk+1)<='9')
					{
						int k=kk+1;
						while(k<s.length()&&s.charAt(k)>='0'&&s.charAt(k)<='9')
							k++;
						String temp1=s.substring(kk+1, k),temp2=s.substring(k);
						tot=mul(Long.parseLong(temp1),get(s.substring(1, kk)));
						return tot=add(tot,get(temp2));
					}
					else
					{
//						if(1<=kk)
							return tot=add(get(s.substring(1, kk)),get(s.substring(kk+1)));
//						else
//							return tot=get(s.substring(kk+1));
					}
				}
			}
			else
			{
				if(s.length()==1)
				{
					tot.put(s, 1l);
					if(!all.contains(s))
					{
						tt.add(s);
						all.add(s);
					}
					return tot;
				}
				else
				{
					if(s.charAt(1)>='a'&&s.charAt(1)<='z')
					{
						if(s.length()==2)
						{
							tot.put(s, 1l);
							if(!all.contains(s))
							{
								tt.add(s);
								all.add(s);
							}
							return tot;
						}
						String t=s.substring(0, 2);
						if(!all.contains(t))
						{
							tt.add(t);
							all.add(t);
						}
						if(s.charAt(2)>='0'&&s.charAt(2)<='9')
						{
							int k=2;
							while(k<s.length()&&s.charAt(k)>='0'&&s.charAt(k)<='9')
								k++;
							tot.put(t,Long.parseLong(s.substring(2, k)));
							tot=add(tot,get(s.substring(k)));
							return tot;
						}
						tot.put(t, 1l);
						tot=add(tot,get(s.substring(2)));
						return tot;
					}
					else
					{
						String t=s.substring(0, 1);
						if(!all.contains(t))
						{
							tt.add(t);
							all.add(t);
						}
						if(s.charAt(1)>='0'&&s.charAt(1)<='9')
						{
							int k=1;
							while(k<s.length()&&s.charAt(k)>='0'&&s.charAt(k)<='9')
								k++;
							tot.put(t,Long.parseLong(s.substring(1, k)));
							tot=add(tot,get(s.substring(k)));
							return tot;
						}
						tot.put(t, 1l);
						tot=add(tot,get(s.substring(1)));
						return tot;
					}
					
				}
			}
		}
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String start=br.readLine().trim();
		HashMap<String,Long> s,e;
		s=ana(start);
		int t=Integer.parseInt(br.readLine().trim());
		while(t-->0)
		{
			String end=br.readLine().trim();
			e=ana(end);
			boolean same=true;
			for(int i=0;i<tt.size();i++)
				if(s.get(tt.get(i))==null&&e.get(tt.get(i))==null)
					continue;
				else
					if(s.get(tt.get(i))==null||e.get(tt.get(i))==null||s.get(tt.get(i))-e.get(tt.get(i))!=0)
//				if(s.get(tt.get(i))-e.get(tt.get(i))!=0)
				{
//					System.out.println(tt.get(i)+" "+s.get(tt.get(i))+" "+e.get(tt.get(i)));
					same=false;
					break;
				}
			if(same)
				System.out.println(start+"=="+end);
			else
				System.out.println(start+"!="+end);
		}
		
	}

}