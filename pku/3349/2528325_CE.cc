import java.util.*;

@SuppressWarnings("unchecked")
public class Main{
	static int m=2;
	static long[][] a=new long[m][6];
	static HashSet<Long>[] h=new HashSet[m];
	static long[] b=new long[6];
	static int n;
	static void ini()
	{
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<6;j++)
				a[i][j]=(long)(Math.random()*10000%99773)+1;
			h[i]=new HashSet<Long>();
		}
		n=ni();
		long min;
		while(n-->0)
		{
			min=Long.MAX_VALUE;
			for(int i=0;i<6;i++)
			{
				b[i]=ni();
				if(b[i]<min)
					min=b[i];
			}
			put(min);
		}
		System.out.println("No two snowflakes are alike.");
	}
	static void put(long min)
	{
		long temp;
		long[] t=get(min);
		boolean mark=false;
		for(int j=0;j<m;j++)
		{
			temp=0;
			for(int i=0;i<6;i++)
				temp+=(long)t[i]*(long)a[j][i];
			if(!h[j].contains(temp))
				mark=true;
			h[j].add(temp);
		}
		if(!mark)
		{
			System.out.println("Twin snowflakes found.");
			System.exit(0);
		}

	}
	static long[] get(long min)
	{
		long[][] t=new long[12][6];
		int p=0;
		for(int k=0;k<6;k++)
		{
			if(b[k]!=min)
				continue;
			int p1=0,p2=0;
			for(int i=k;i<6;i++)
				t[p][p1++]=b[i];
			for(int i=0;i<k;i++)
				t[p][p1++]=b[i];
			
			p++;
			for(int i=k;i>-1;i--)
				t[p][p2++]=b[i];
			for(int i=5;i>k;i--)
				t[p][p2++]=b[i];
			p++;
		}
		long[] temp=new long[6];
		for(int i=0;i<6;i++)
			temp[i]=t[0][i];
		for(int i=1;i<p;i++)
		{
			if(com(temp,t[i]))
				for(int j=0;j<6;j++)
					temp[j]=t[i][j];
		}
		return temp;
	}
	static boolean com(long[] a,long[] b)
	{
		for(int i=0;i<6;i++)
			if(a[i]>b[i])
				return true;
			else
				if(a[i]<b[i])
					return false;
		return false;
	}
	static int ni() {
		int v = 0;
		char t = 0;
		boolean neg = false;
		try {
			while (!Character.isDigit(t = (char) System.in.read()) && t != '-')
				;
			if (t == '-') {
				neg = true;
				t = '0';
			}
			do {
				v *= 10;
				v += t - '0';
			} while (Character.isDigit(t = (char) System.in.read()));
		} catch (Exception e) {
		}
		return neg ? -v : v;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ini();
	}

}
