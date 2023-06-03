import java.util.*;

public class Main
{
    static class Edge
    {
        int it, weight;
        Edge(int it, int weight)
        {
            this.it = it;
            this.weight = weight;
        }
    }

    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int m = input.nextInt();
        int q = input.nextInt();
        int start = input.nextInt();

        List<Edge>[] graph = new List[n + 1];

        for (int i = 1; i <= n; i++)
        {
            graph[i] = new ArrayList<>();
        }

        for (int i = 0; i < m; i++)
        {
            int from = input.nextInt();
            int to = input.nextInt();
            int weight = input.nextInt();
            graph[from].add(new Edge(to, weight));
            graph[to].add(new Edge(from, weight));
        }

        int[] dist = new int[n + 1];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[start] = 0;

        PriorityQueue<Integer> queue = new PriorityQueue<>(Comparator.comparingInt(i -> dist[i]));
        queue.add(start);

        while (!queue.isEmpty())
        {
            int from = queue.poll();

            for (Edge edge : graph[from])
            {
                int it = edge.it;
                int weight = edge.weight;
                if (dist[it] > dist[from] + weight)
                {
                    dist[it] = dist[from] + weight;
                    queue.add(it);
                }
            }
        }

        for (int i = 0; i < q; i++)
        {
            int query = input.nextInt();
            System.out.println(dist[query] == Integer.MAX_VALUE ? -1 : dist[query]);
        }
    }
}
