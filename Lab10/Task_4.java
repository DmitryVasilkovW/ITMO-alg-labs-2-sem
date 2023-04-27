import java.util.*;

public class Main
{
    public static void dfs(List<List<Integer>> graph, int[] newIndex, boolean[] visited, int u, int[] cur)
    {
        visited[u] = true;
        for (int v : graph.get(u))
        {
            if (!visited[v])
            {
                dfs(graph, newIndex, visited, v, cur);
            }
        }
        newIndex[u] = cur[0]--;
    }

    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);

        int n = input.nextInt();
        int m = input.nextInt();

        List<List<Integer>> graph = new ArrayList<>(n);

        for (int i = 0; i < n; i++)
        {
            graph.add(new ArrayList<>());
        }

        for (int i = 0; i < m; i++)
        {
            int u = input.nextInt() - 1;
            int v = input.nextInt() - 1;
            graph.get(u).add(v);
        }

        int[] newIndex = new int[n];
        int[] cur = {n};

        boolean[] visited = new boolean[n];

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(graph, newIndex, visited, i, cur);
            }
        }

        for (int i = 0; i < n; i++)
        {
            System.out.print(newIndex[i] + " ");
        }
    }
}
