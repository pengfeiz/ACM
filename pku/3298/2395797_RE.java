import java.io.*;
import java.util.*;

public class Main {
    static int[][] dp;
    static int[] a;
    static int n;
    static int dp(int s,int mark)
    {
        if(dp[s][mark]>-1)
            return dp[s][mark];
        if(mark==1)
        {
            if(s+1<n&&a[s+1]>a[s])
                return dp[s][mark]=dp(s+1,1);
            else
            {
                return dp[s][mark]=1+dp(s+1,0);
            }
        }
        else
        {
            if(s+1<n&&a[s+1]<a[s])
                return dp[s][mark]=dp(s+1,0);
            else
            {
                return dp[s][mark]=1+dp(s+1,1);
            }
        }
    }
    public static void main(String[] args) throws Exception {
        // TODO Auto-generated method stub
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer str;
        int m=Integer.parseInt(br.readLine().trim());
        while(m-->0)
        {
            str=new StringTokenizer(br.readLine());
            n=Integer.parseInt(str.nextToken());
            a=new int[n];
            for(int i=0;i<n;i++)
                a[i]=Integer.parseInt(str.nextToken());
            dp=new int[n][2];
            for(int i=0;i<2;i++)
                for(int j=0;j<n;j++)
                    dp[j][i]=-1;
            dp[n-1][0]=dp[n-1][1]=1;
            System.out.println(dp(0,1));
        }
    }

} 
