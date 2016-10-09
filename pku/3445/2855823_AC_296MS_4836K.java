import java.io.*;

public class Main{
	static String[] num=new String[17];
	static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	static int n;
	static int[] len=new int[17];
	static void set()
	{
		num[0]="{}";
		len[0]=2;
		for(int i=1;i<16;i++)
		{
			num[i]="{";
			num[i]+=num[0];
			for(int j=1;j<i;j++)
				num[i]+=","+num[j];
			num[i]+="}";
			len[i]=num[i].length();
		}
	}
	static void ini() throws Exception
	{
		n=Integer.parseInt(br.readLine().trim());
	}
	static void solve() throws Exception
	{ 
		while(n-->0)
		{
			String s1=br.readLine().trim(),s2=br.readLine().trim();
			int k1=0,k2=0;
			for(int i=0;i<16;i++)
			{
				if(s1.length()==len[i])
					k1=i;
				if(s2.length()==len[i])
					k2=i;
			}
			System.out.println(num[k1+k2]);
		}
	}
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		set();
		ini();
		solve();
	}

}

