import java.util.Scanner;

public class Main{
	static int[][] g,mark;
	static int n,m,sum;
	static void search(int a,int b)
	{
		if(g[a][b]==0)
			return;
		mark[a][b]=1;
		if(a-1>=0&&g[a-1][b]==0||a-1<0)
			sum++;
		else
			if(mark[a-1][b]==0)
				search(a-1,b);
		if(a+1<n&&g[a+1][b]==0||a+1>=n)
			sum++;
		else
			if(mark[a+1][b]==0)
				search(a+1,b);
		if(b-1>=0&&g[a][b-1]==0||b-1<0)
			sum++;
		else
			if(mark[a][b-1]==0)
				search(a,b-1);
		if((b+1<m&&g[a][b+1]==0)||b+1>=m)
			sum++;
		else
			if(mark[a][b+1]==0)
				search(a,b+1);
		if(a-1>=0&&b-1>=0)
			if(g[a-1][b-1]==1&&mark[a-1][b-1]==0)
				search(a-1,b-1);
		if(a-1>=0&&b-1>=0)
			if(g[a-1][b-1]==1&&mark[a-1][b-1]==0)
				search(a-1,b-1);
		if(a+1<n&&b+1<m)
			if(g[a+1][b+1]==1&&mark[a+1][b+1]==0)
				search(a+1,b+1);
		if(a-1>=0&&b+1<m)
			if(g[a-1][b+1]==1&&mark[a-1][b+1]==0)
				search(a-1,b+1);
		if(a+1<n&&b-1>=0)
			if(g[a+1][b-1]==1&&mark[a+1][b-1]==0)
				search(a+1,b-1);
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in=new Scanner(System.in);
		for(;;)
		{
			n=in.nextInt();
			m=in.nextInt();
			int a=in.nextInt(),b=in.nextInt();
			if(n==0&&m==0)
				return;
			sum=0;
			g=new int[n][m];
			mark=new int[n][m];
			for(int i=0;i<n;i++)
			{
				String s=in.next();
				for(int j=0;j<m;j++)
					if(s.charAt(j)=='X')
						g[i][j]=1;
			}
			search(a-1,b-1);
			System.out.println(sum);
		}
	}

}