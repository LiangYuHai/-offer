//pdd提前批笔试
// Created by johanliang on 2020/9/3.
//
//分割矩阵（1-8）
public class A {
public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.close();
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j || i + j == n + 1 || (n % 2 != 0 && (i == (n + 1) / 2 || j == (n + 1) / 2))) {
                    System.out.print(0);
                } else if (j < n + 1 - i && j > (float) (n+1) / 2) {
                    System.out.print(1);
                } else if (j > i && j < (float) (n+1) / 2) {
                    System.out.print(2);
                } else if (j < i && i < (float) (n+1) / 2) {
                    System.out.print(3);
                } else if (i < n + 1 - j && i > (float) (n+1) / 2) {
                    System.out.print(4);
                } else if (i > n + 1 - j && j < (float) (n+1) / 2) {
                    System.out.print(5);
                } else if (i > j && j > (float) (n+1) / 2) {
                    System.out.print(6);
                } else if (i < j && i > (float) (n+1) / 2) {
                    System.out.print(7);
                } else if (i > n + 1 - j && i < (float) (n+1) / 2) {
                    System.out.print(8);
                }

                if (j == n) {
                    System.out.println();
                } else {
                    System.out.print(" ");
                }
            }
        }

    }

}

//移动士兵
import java.util.*;

public class Second2
{
    static int [][]a=new int[405][405];
    static int [][]col=new int[405][405];
    static int []qx=new int[200005];
    static int []qy=new int[200005];
    static int []siz=new int[200005];
    static int []v=new int[200005];
    static int cnt,n,m;

    static int []kx={0,0,1,-1};
    static int []ky={1,-1,0,0};

public static void bfs(int x,int y)
    {
        int eh=1,ed=0,eh2=1,ed2=0;
        qx[++ed]=x; qy[++ed2]=y;
        while(eh<=ed)
        {
            int u=qx[eh],v=qy[eh2]; eh++; eh2++; col[u][v]=cnt; siz[col[u][v]]++;
            for(int i=0;i<=3;i++)
            {
                int tx=u+kx[i],ty=v+ky[i];
                if(tx<=0||tx>n||ty<=0||ty>m||col[tx][ty]!=0||a[tx][ty]==0) continue;
                qx[++ed]=tx; qy[++ed2]=ty;
            }
        }
    }

public static void main(String[] args)
    {
        Scanner S=new Scanner(System.in);
        n=S.nextInt(); m=S.nextInt();
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) a[i][j]=S.nextInt();
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
                if(a[i][j]==1&&col[i][j]==0) {cnt++; bfs(i,j);}

        int ans=0;
        for(int i=1;i<=cnt;i++) ans=Math.max(ans,siz[i]);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(a[i][j]==1) continue;
                int tmp=0;
                for(int k=0;k<=3;k++)
                {
                    int tx=i+kx[k],ty=j+ky[k];
                    if(tx<=0||tx>n||ty<=0||ty>m) continue;
                    if(v[col[tx][ty]]==0)
                    {
                        v[col[tx][ty]]=1;
                        tmp+=siz[col[tx][ty]];
                    }
                }
                ans=Math.max(ans,tmp+1);
                for(int k=0;k<=3;k++)
                {
                    int tx=i+kx[k],ty=j+ky[k];
                    if(tx<=0||tx>n||ty<=0||ty>m) continue;
                    v[col[tx][ty]]=0;
                }
            }
        }

        int p2=0;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) p2+=a[i][j];
        System.out.println(Math.min(ans,p2));
    }
}

//背包
import java.util.*;

public class zbr01
{
    static int []dp=new int[1000005];
    static int []c=new int[500005];
    static int []v=new int[500005];

public static void main(String[] args)
    {
        Scanner S=new Scanner(System.in);
        int n=S.nextInt(),m=S.nextInt(),k=20005;
        for(int i=0;i<k;i++) dp[i]=-10000000;
        for(int i=1;i<=n;i++)
        {
            int w=S.nextInt(),v=S.nextInt();
            if(w<0)
            {
                for(int j=0;j<k+m+w;j++)
                    dp[j]=Math.max(dp[j],dp[j-w]+v);
            }
            else
            {
                for(int j=k+m;j>=w;j--)
                    dp[j]=Math.max(dp[j],dp[j-w]+v);
            }
        }
        int ans=0;
        for(int i=k-5;i<=k+m;i++) ans=Math.max(ans,dp[i]);
        System.out.println(ans);
    }
}

//显著特征（X可以被Y整除）
import java.util.Scanner;

public class Four2 {

public static void main(String[] args) {
        Scanner S = new Scanner(System.in);
        long N = S.nextLong();
        int M = S.nextInt();
        long[] arr = new long[M + 1];
        for (int i = 1; i <= M; i++) {
            arr[i] = S.nextInt();
        }
        long ed = pw(2, M), ans = N;
        for (int i = 1; i < ed; i++) {
            long cnt = 0, tmp = 1;
            for (int j = 1; j <= M; j++) {
                if ((i & (1 << (j - 1))) != 0) {
                    cnt++;
                    tmp = tmp / gcd(tmp, arr[j]) * arr[j];
                }
            }
            if (cnt % 2 == 1) ans -= (N / tmp);
            else ans += (N / tmp);
        }
        System.out.println(N - ans);
    }

public static long pw(long a, long b) {
        long ans = 1, base = a;
        while (b != 0) {
            if (b % 2 == 1) ans = (ans * base);
            base = (base * base);
            b >>= 1;
        }
        return ans;
    }

public static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}

//显著特征（X可以被Y整除）
import java.util.Scanner;

public class Four2 {

public static void main(String[] args) {
        Scanner S = new Scanner(System.in);
        long N = S.nextLong();
        int M = S.nextInt();
        long[] arr = new long[M + 1];
        for (int i = 1; i <= M; i++) {
            arr[i] = S.nextInt();
        }
        long ed = pw(2, M), ans = N;
        for (int i = 1; i < ed; i++) {
            long cnt = 0, tmp = 1;
            for (int j = 1; j <= M; j++) {
                if ((i & (1 << (j - 1))) != 0) {
                    cnt++;
                    tmp = tmp / gcd(tmp, arr[j]) * arr[j];
                }
            }
            if (cnt % 2 == 1) ans -= (N / tmp);
            else ans += (N / tmp);
        }
        System.out.println(N - ans);
    }

public static long pw(long a, long b) {
        long ans = 1, base = a;
        while (b != 0) {
            if (b % 2 == 1) ans = (ans * base);
            base = (base * base);
            b >>= 1;
        }
        return ans;
    }

public static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}