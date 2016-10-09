import java.io.*;
import java.util.*;

public class Main{
	static int[] a=new int[110],ans=new int[15];
	static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer str;
	static int n,m;
	static boolean[] mark=new boolean[110];
	static HashMap<Integer,Integer> h=new HashMap<Integer,Integer>();
	static void ini() 
	{
		try{
		str=new StringTokenizer(br.readLine());
		n=Integer.parseInt(str.nextToken());
		m=n*(n-1)/2;
		for(int i=0;i<m;i++)
			a[i]=Integer.parseInt(str.nextToken());
		}
		catch(Exception e)
		{
			System.exit(0);
		}
	}
	static void solve()
	{
		Arrays.sort(a,0,m);
		h.clear();
		for(int i=0;i<m;i++)
			h.put(a[i], i);
		outside:
		for(int i=2;i<m;i++)
		{
			Arrays.fill(mark, false);
			mark[0]=mark[1]=mark[i]=true;
			ans[0]=(a[0]-a[i]+a[1])/2;
			ans[1]=a[0]-ans[0];
			ans[2]=a[1]-ans[0];
			for(int j=3;j<n;j++)
			{
				for(int k=2;k<m;k++)
					if(!mark[k])
					{	
						ans[j]=a[k]-ans[0];
						mark[k]=true;
						break;
					}
				for(int k=1;k<j;k++)
				{
					int t=ans[j]+ans[k],kk;
					for(kk=2;kk<m;kk++)
						if(!mark[kk]&&a[kk]==t)
						{
							mark[kk]=true;
							break;
						}
					if(kk==m)
						continue outside;
				}
			}
			int p=0;
			int[] test=new int[110];
			for(int j=0;j<n;j++)
				for(int k=0;k<j;k++)
					test[p++]=ans[j]+ans[k];
			Arrays.sort(test,0,p);
			for(int j=0;j<m;j++)
				if(test[j]!=a[j])
					continue outside;
			for(int j=0;j<n;j++)
				System.out.print(ans[j]+" ");
			System.out.println();
			return;
		}
		System.out.println("Impossible");
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		while(true)
		{
			ini();
			solve();
		}
	}

}