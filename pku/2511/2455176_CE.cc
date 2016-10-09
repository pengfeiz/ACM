import java.io.*;
import java.util.*;

public class Main{
	static int n;
	static book[] b;
	static int[][] list;
	static int[][][] a;
	static void ini() throws Exception
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		n=Integer.parseInt(br.readLine());
		b=new book[n];
		a=new int[11][n][3];
		for(int i=0;i<n;i++)
		{
			String s=br.readLine();
			b[i]=new book();
			int temp=0;
			int k=0;
			for(;s.charAt(k)!=' ';k++)
				temp=temp*10+s.charAt(k)-'0';
			b[i].a=temp;
			b[i].name=s.substring(k+1);
			b[i].c=new char[b[i].name.length()];
			b[i].len=0;
			b[i].com="";
			for(k=0;k<b[i].name.length();k++)
			{
				char c=b[i].name.charAt(k);
				if(c>='a'&&c<='z'||c>='A'&&c<='Z')
				{
					
					if(c>='a'&&c<='z')
						c+=('A'-'a');
					b[i].c[b[i].len++]=c;
					b[i].com+=c;
					
				}
				
			}
//			System.out.println(b[i].com);
		}
		Arrays.sort(b);
		list=new int[n][n+1];
		for(int i=0;i<n;i++)
			list[i][0]=1;
		for(int i=1;i<n;i++)
			for(int j=0;j<i;j++)
			{
				if(canreach(b[i].c,b[j].c))
					list[i][list[i][0]++]=j;
			}
	}
	static boolean canreach(char[] x,char[] y)
	{
		int e=Math.min(x.length, y.length);
		for(int i=0;i<e;i++)
			if(x[i]==y[i])
				return false;
		return true;
	}
	static void solve()
	{
		int max=-1;
		int mr=0,mc=0;
		for(int i=0;i<n;i++)
		{
			a[0][i][0]=b[i].a;
			a[0][i][1]=-1;
			a[0][i][2]=-1;
			if(a[0][i][0]>max)
			{
				max=a[0][i][0];
				mr=0;
				mc=i;
			}
		}
		for(int i=1;i<10;i++)
		{
			for(int j=i;j<n;j++)
			{
				int best=a[i-1][j][0];
				int br=i-1;
				int bc=j;
				for(int k=1;k<list[j][0];k++)
				{
					int temp=a[i-1][list[j][k]][0]+b[j].a;
					if(temp>best)
					{
						best=temp;
						br=i-1;
						bc=list[j][k];
					}
				}
				if(best>=max)
				{
					max=best;
					mr=i;
					mc=j;
				}
				a[i][j][0]=best;
				a[i][j][1]=br;
				a[i][j][2]=bc;
			}
		}
		int[] tot=new int[11];
		int num=0;
		int cr=mr,cc=mc;
		int nr,nc;
		while(cr>=0)
		{
			nr=a[cr][cc][1];
			nc=a[cr][cc][2];
			if(nr!=cr)
				if(nc!=cc||nr==-1)
					tot[num++]=cc;
			cr=nr;
			cc=nc;
		}
		System.out.println(num+"\n"+a[mr][mc][0]);
		for(int i=num-1;i>-1;i--)
			System.out.println(b[tot[i]].name);
	}
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		ini();
		solve();
	}

}
class book implements Comparable<book>{
	String name,com;
	char[] c;
	int a,len;
	public int compareTo(book o) {
		// TODO Auto-generated method stub
		if(com.compareTo(o.com)>0)
			return 1;
		return 0;
	}
	
}