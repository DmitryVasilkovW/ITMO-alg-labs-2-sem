
import java.util.*;

public class Main
{
    static ArrayList<ArrayList<Integer>> List;
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);

        int n = input.nextInt();
        int m = input.nextInt();

        List = new ArrayList<ArrayList<Integer>>();

        for (int i = 0; i < n; i++)
        {
            List.add(new ArrayList<Integer>());

        }

        for (int i = 0; i < m; i++)
        {
            int u = input.nextInt();
            int v = input.nextInt();

            u--;
            v--;

            List.get(u).add(v);
            List.get(v).add(u);
        }

        int s = input.nextInt();
        int f = input.nextInt();

        s--;
        f--;

        int[] dist = new int[n];

        Arrays.fill(dist, -1);
        dist[s] = 0;

        Queue<Integer> queue = new LinkedList<>();
        queue.offer(s);

        while (!queue.isEmpty())
        {
            int u = queue.poll();

            for (int v : List.get(u))
            {
                if (dist[v] == -1)
                {
                    dist[v] = dist[u] + 1;
                    queue.offer(v);
                }
            }
        }

        System.out.print(dist[f]);
    }
}
