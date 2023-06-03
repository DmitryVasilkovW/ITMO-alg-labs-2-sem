import java.util.*;

class Main
{
    static int max(int[][] graph, int n)
    {
        int maxFlow = ford.fordFulkerson(graph, 0, n - 1);
        return maxFlow;
    }
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        int m = sc.nextInt();
        
        int[][] graph = new int[n][n];
        
        for (int i = 0; i < m; i++)
        {
            int u = sc.nextInt() - 1;
            int v = sc.nextInt() - 1;
            int c = sc.nextInt();
            graph[u][v] += c;
        }
        
        System.out.println(max(graph, n));
    }
}

class ford
{
    public static int fordFulkerson(int[][] graph, int source, int sink)
    {
        int n = graph.length;
        int[][] residual = new int[n][n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                residual[i][j] = graph[i][j];
            }
        }
        int[] parent = new int[n];
        int maxFlow = 0;
        while (bfs(residual, source, sink, parent))
        {
            int pathFlow = Integer.MAX_VALUE;
            for (int v = sink; v != source; v = parent[v])
            {
                int u = parent[v];
                pathFlow = Math.min(pathFlow, residual[u][v]);
            }
            for (int v = sink; v != source; v = parent[v])
            {
                int u = parent[v];
                residual[u][v] -= pathFlow;
                residual[v][u] += pathFlow;
            }
            maxFlow += pathFlow;
        }
        return maxFlow;
    }

    public static boolean bfs(int[][] residual, int source, int sink, int[] parent)
    {
        int n = residual.length;
        boolean[] visited = new boolean[n];
        Queue<Integer> queue = new LinkedList<>();
        queue.add(source);
        visited[source] = true;
        parent[source] = -1;
        while (!queue.isEmpty())
        {
            int u = queue.poll();
            for (int v = 0; v < n; v++)
            {
                if (!visited[v] && residual[u][v] > 0)
                {
                    queue.add(v);
                    parent[v] = u;
                    visited[v] = true;
                    if (v == sink)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
}
