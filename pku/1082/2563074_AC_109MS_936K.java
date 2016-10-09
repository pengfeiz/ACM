//by wpt


import java.io.*;
import java.util.StringTokenizer;

public class Main{
	static int[] month={0,31,28,31,30,31,30,31,31,30,31,30,31};
	static boolean[][][] a;
	static int ni,nj,nk;
	static void ini()
	{
		a=new boolean[103][14][33];
		a[101][11][3]=true;
		for(int i=101;i>-1;i--)
			for(int j=12;j>0;j--)
				for(int k=31;k>0;k--)
				{
					if(!exist(i,j,k))
						continue;
					boolean mark1=true,mark2=true;
					if(j==12)
						mark1=a[i+1][1][k];
					else
						if(exist(i,j+1,k))
							mark1=a[i][j+1][k];
					next(i,j,k);
					if(exist(ni,nj,nk))
						mark2=a[ni][nj][nk];
					if(!mark1||!mark2)
						a[i][j][k]=true;
					
				}
	}
	static boolean exist(int x,int y,int z)
	{
		if(x>101||y>12)
			return false;
		if(x==101&&(y>11||y==11&&z>2))
			return false;
		if(y==2&&leap(x))
			if(z>29)
				return false;
			else
				return true;
		if(z>month[y])
			return false;
		return true;
		
	}
	static boolean leap(int x)
	{
		if((x%4==0&&x%100!=0||x%400==0))
			return true;
		return false;
	}
	static void next(int x,int y,int z)
	{
		ni=x;
		nj=y;
		nk=z+1;
		if(leap(x)&&y==2&&nk>29)
		{
			nj++;
			nk=1;
		}
		if(nk>month[nj])
		{
			nj++;
			nk=1;
		}
		if(nj>12)
		{
			ni++;
			nj=1;
		}
		
	}
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		ini();
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer str;
		int n=Integer.parseInt(br.readLine().trim());
		
		while(n-->0)
		{
			str=new StringTokenizer(br.readLine());
			if(a[Integer.parseInt(str.nextToken())-1900][Integer.parseInt(str.nextToken())][Integer.parseInt(str.nextToken())])
				System.out.println("YES");
			else
				System.out.println("NO");
		}
	}

}
