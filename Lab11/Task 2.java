import java.util.Scanner;

public class Main
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int m = input.nextInt();

        int[][] dist = new int[n + 1][n + 1];

        final int INF = Integer.MAX_VALUE;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == j)
                {
                    dist[i][j] = 0;
                }
                else
                {
                    dist[i][j] = INF;
                }
            }
        }

        for (int i = 1; i <= m; i++)
        {
            int u = input.nextInt();
            int v = input.nextInt();
            int w = input.nextInt();

            dist[u][v] = w;
            dist[v][u] = w;
        }

        for (int k = 1; k <= n; k++)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (dist[i][k] != INF && dist[k][j] != INF)
                    {
                        dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        int maxDist = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dist[i][j] != INF)
                {
                    maxDist = Math.max(maxDist, dist[i][j]);
                }
            }
        }

        if (maxDist == INF)
        {
            System.out.println("0");
        }
        else
        {
            System.out.println(maxDist);
        }
    }
}
