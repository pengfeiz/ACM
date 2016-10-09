 import java.util.Arrays;

      public class Main{
      	static int m,n;
      	static int[][] graph=new int[110][110];
      	static int[] rank=new int[110],r=new int[110];
      	static int[] d=new int[110];
      	static boolean[] mark=new boolean[110];
      	static void ini()
      	{
      		m=ni();
      		n=ni();
      		int k;
      		for(int i=0;i<=n;i++)
      			Arrays.fill(graph[i],-1);
      		for(int i=1;i<=n;i++)
      		{
      			graph[0][i]=ni();
      			rank[i]=ni();
      			r[i]=rank[i];
      			k=ni();
      			while(k-->0)
      				graph[ni()][i]=ni();
      		}
      		Arrays.sort(r,1,n+1);
      	}
      	static void solve()
      	{
      		int min=Integer.MAX_VALUE;
      		for(int i=n;i>0;i--)
      			min=Math.min(min, get(rank[i]));
      		System.out.println(min);
      	}
      	static int get(int limit)
      	{
      		Arrays.fill(d, Integer.MAX_VALUE);
      		Arrays.fill(mark, false);
      		d[0]=0;
      		rank[0]=limit;
      		while(true)
      		{
      			int min=Integer.MAX_VALUE,k=-1;
      			for(int i=0;i<=n;i++)
      				if(!mark[i]&&d[i]<min&&rank[i]<=limit&&rank[i]>=limit-m)
      				{
      					min=d[i];
      					k=i;
      				}
      			if(k==-1)
      				return Integer.MAX_VALUE;
      			mark[k]=true;
      			if(k==1)
      				return d[k];
      			for(int i=1;i<=n;i++)
      				if(graph[k][i]!=-1&&(d[i]==Integer.MAX_VALUE||graph[k][i]+d[k]<d[i]))
      					d[i]=graph[k][i]+d[k];
      			
      		}
      		
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
      		solve();
      	}

      }