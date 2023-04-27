import java.util.*;

class Edge
{
    int start;
    int end;
    int result;

    public Edge(int start, int end, int result)
    {
        this.start = start;
        this.end = end;
        this.result = result;
    }
}

public class Main
{
    public static int findNegativeCycle(List<Edge> edges, int n)
    {
        int[] dist = new int[n + 1];
        Arrays.fill(dist, 0);

        for (int i = 0; i < n - 1; i++)
        {
            for (Edge edge : edges)
            {
                if (dist[edge.start] + edge.result < dist[edge.end])
                {

                    dist[edge.end] = dist[edge.start] + edge.result;
                }
            }
        }

        for (Edge edge : edges)
        {
            if (dist[edge.start] + edge.result < dist[edge.end])
            {
                return 1;
            }
        }

        return -1;
    }

    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);

        int n = input.nextInt();
        int m = input.nextInt();

        List<Edge> edges = new ArrayList<>();

        for (int i = 0; i < m; i++)
        {
            int start = input.nextInt();
            int end = input.nextInt();
            int result = input .nextInt();
            edges.add(new Edge(start, end, result));
        }

        int result = findNegativeCycle(edges, n);
        System.out.println(result);
    }
}
