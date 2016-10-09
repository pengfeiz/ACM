import java.io.*;
import java.text.DecimalFormat;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main{
	static String s;
	static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	static int a,b,c;
	static StringTokenizer str;
	static char[] ch;
	static Scanner in=new Scanner(System.in);
	static void ini()
		while(in.hasNext())
			s+=in.nextLine().toLowerCase()+' ';
	static void solve()
	{
		s=s.trim();
		str=new StringTokenizer(s,"!?.:;");
		a=str.countTokens();
		c=0;
		str=new StringTokenizer(s," !.:;,?...\"()~!@#$%^&*()_+[]");
		while(str.hasMoreTokens())
		{
			b++;
			String temp=str.nextToken();
//			System.out.println(temp);
			
			ch=temp.toCharArray();
			int len=ch.length;
			if(len<=3)
			{
				c++;
				continue;
			}
			boolean mark=false;
			for(int i=0;i<len;i++)
			{
				if((ch[i]=='a'||ch[i]=='e'||ch[i]=='i'||ch[i]=='o'||ch[i]=='u'||ch[i]=='y'))
				{	
					if(!mark)
					{
						c++;
						mark=true;
					}
				}
				else
					mark=false;
			}
			if(len>1)
			{
				if(ch[len-2]=='e'&&ch[len-1]=='s')
				{
//					System.out.println(temp);
					c--;
					if((ch[len-3]=='a'||ch[len-3]=='e'||ch[len-3]=='i'||ch[len-3]=='o'||ch[len-3]=='u'||ch[len-3]=='y'))
						c++;
				}
				if(ch[len-2]=='e'&&ch[len-1]=='d')
				{
//					System.out.println(temp);
					c--;
					if((ch[len-3]=='a'||ch[len-3]=='e'||ch[len-3]=='i'||ch[len-3]=='o'||ch[len-3]=='u'||ch[len-3]=='y'))
						c++;
				}
				if(ch[len-1]=='e'&&ch[len-2]!='l')
				{
//					System.out.println(temp);
					c--;
					if((ch[len-2]=='a'||ch[len-2]=='e'||ch[len-2]=='i'||ch[len-2]=='o'||ch[len-2]=='u'||ch[len-2]=='y'))
						c++;
				}
			}
		}
		DecimalFormat f=new DecimalFormat("0.00");
//		System.out.println(a+" "+b+" "+c);
		double tot=206.835-(1.015*b)/a-(84.6*c)/b;
		tot*=100;
		if(tot-(int)tot>=0.5)
			tot=(int)tot+1;
		else
			tot=(int)tot;
		tot/=100;
		System.out.println(f.format(tot));
		
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ini();
		solve();
	}

}

