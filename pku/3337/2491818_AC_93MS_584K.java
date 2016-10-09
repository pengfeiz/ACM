import java.io.*;


public class Main{
	static int[] a;
	static boolean[] use;
	static int solve(String s,int mark)
	{
//		System.out.println(s+" "+mark);
		if(s.equals(""))
			return 0;
		int add=0,sub=0;
		char c=s.charAt(0);
		int k;
		if(c>='a'&&c<='z')
		{
			k=c-'a';
			use[k]=true;
			if(s.length()<=1)
				return a[k];
			int d=0;
			int t=1;
			char last=s.charAt(1);
			int len=s.length();
			for(;t<len;t++)
				if(s.charAt(t)!=last&&(add%2==1||sub%2==1))
					break;
				else
					if(s.charAt(t)=='+')
					{
						add++;
						last='+';
					}
					else
					{
						sub++;
						last='-';
					}
			d=add/2-sub/2;
			int temp=a[k];
			a[k]+=d;
			if(t==s.length())
				return temp;
			else
			{
				if(add%2==1)
					if(mark==0)
						return temp+solve(s.substring(t),mark);
					else
						return temp-solve(s.substring(t),mark);
				else
					if(mark==0)
						return temp-solve(s.substring(t),1);
					else
						return temp+solve(s.substring(t),1);
			}

		}
		else
		{
			int d=0,t=0;
			boolean has=true;
			for(;t<s.length();t++)
				if(s.charAt(t)!='+'&&s.charAt(t)!='-')
				{
					has=false;
					break;
				}
				else
					if(s.charAt(t)=='+')
						add++;
					else
						sub++;
			if(has)
				return 0;
			k=s.charAt(t)-'a';
			use[k]=true;
			d=add/2-sub/2;
			a[k]+=d;
			if(t==s.length()-2)
				return a[k];
			if(t==s.length()-1)
				return a[k];
			else
				if(s.charAt(t+1)=='+')
					if(mark==0)
						return a[k]+solve(s.substring(t+2),mark);
					else
						return a[k]-solve(s.substring(t+2),mark);
				else
					if(mark==0)
						return a[k]-solve(s.substring(t+2),1);
					else
						return a[k]+solve(s.substring(t+2),1);
			
		
		}
	}

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int n=Integer.parseInt(br.readLine().trim());
		while(n-->0)
		{
			a=new int[26];
			use=new boolean[26];
			for(int i=0;i<26;i++)
				a[i]=i+1;
			String s=br.readLine();
			String ss="";
			char[] ch=s.toCharArray();
			int len=s.length();
			for(int i=0;i<len;i++)
				if(ch[i]!=' ')
					ss+=ch[i];
			System.out.println("Expression: "+s);
			System.out.println("value = "+solve(ss,0));
			for(int i=0;i<26;i++)
				if(use[i])
					System.out.println((char)(i+'a')+" = "+a[i]);
			
		}
	}

}
