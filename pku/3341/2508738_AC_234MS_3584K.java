import java.io.*;
import java.text.DecimalFormat;
import java.util.*;

public class Main{
	static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer str;
	static HashMap<String,Integer> h=new HashMap<String,Integer>();
	static ArrayList<street> as=new ArrayList<street>();
	static ArrayList<String> temp=new ArrayList<String>();
	static double d1=1.2,d2=1.1;
	static DecimalFormat f=new DecimalFormat("0");
	static void ini() throws Exception
	{
		h.clear();
		as.clear();
		String s=br.readLine().trim();
		if(s.equals("--"))
			System.exit(0);
		str=new StringTokenizer(s);
		s=str.nextToken();
		as.add(new street(Double.parseDouble(str.nextToken()),Double.parseDouble(str.nextToken())));
		h.put(s, 0);
		int p=1;
		while(true)
		{
			s=br.readLine().trim();
			if(s.equals("$"))
				return;
			str=new StringTokenizer(s);
			s=str.nextToken();
			as.add(new street(Double.parseDouble(str.nextToken()),Double.parseDouble(str.nextToken())));
			h.put(s, p++);
		}
		
	}
	static void solve() throws Exception
	{
		while(true)
		{
			String s=br.readLine().trim();
			if(s.equals("#"))
				return;
			str=new StringTokenizer(s," :");
			temp.clear();
			while(str.hasMoreTokens())
				temp.add(str.nextToken());
			int n=temp.size();
			long start=Integer.parseInt(temp.get(n-1))+Integer.parseInt(temp.get(n-2))*60;
			double tot=0;
			int time=0,mile=0,num=1;
			for(int i=h.get(temp.get(0));i<=h.get(temp.get(1));i++)
			{
				int p=i;
				street se=as.get(p);
				for(int j=1;j<=se.l;j++)
				{
					long ss,ee;
					ss=start;
					ee=ss+(int)se.m-1;
					start=ee+1;
					boolean mark=false;
					long sss=ss%1440;
					if(sss>=0&&sss<360||ss/1440<ee/1440)
						mark=true;
					double t=1;
					if(mark)
						t=d1;
					if(num<11)
						tot+=t*1000.0;
					else
						if(num<31)
							tot+=t*250.0;
						else
							tot+=t*100.0;
					num++;
				}
				mile+=se.l;
				time+=se.l*se.m;
			}
			if((double)mile/((double)time/60.0)<30)
				tot*=d2;
			double d=tot-(int)tot;
			if(d>=0.5)
				tot=(int)tot+1;
			else
				tot=(int)tot;
			System.out.println(f.format(tot));
		}
		
	}
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		while(true)
		{
			ini();
			solve();
		}
	}

}
class street{
	double l,m;
	public street(double ll,double mm)
	{
		l=ll;
		m=mm;
	}
} 