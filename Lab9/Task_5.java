import java.util.*;

public class Main
{
    static ArrayList<Integer> visited;
    static ArrayList<ArrayList<Integer>> List;

    public static boolean dfs(int u, int p, int n, int count)
    {
        visited.set(u, 1);
        count++;

        if (count == n)
        {
            return true;
        }

        for (int i = 0; i < List.get(u).size(); i ++)
        {
            int next = List.get(u).get(i);

            if (next != p)
            {
                if (visited.get(next) == 0)
                {
                    if (dfs(next, u, n, count))
                    {
                        return true;
                    }
                }
            }
        }

        visited.set(u, 3);
        return false;
    }

    public static int Max(int[] array)
    {
        int max = -56;
        int in = 0;

        for (int i = 0; i < array.length; i ++)
        {
            if (array[i] > max)
            {
                max = array[i];
                in = i;
            }
        }
        return in;
    }

    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);

        int n = input.nextInt();
        int m = input.nextInt();
        int U;

        List = new ArrayList<ArrayList<Integer>>();
        visited = new ArrayList<Integer>();

        for (int i = 0; i < n; i++)
        {
            List.add(new ArrayList<Integer>());
            visited.add(0);
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

        int[] dist = new int[n];

        Arrays.fill(dist, -1);

        Queue<Integer> queue = new LinkedList<>();
        queue.offer(0);
        dist[0] = 0;


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

        U = Max(dist);

        if (dfs(U, -1, n, 0))
        {
            System.out.print("YES");
        }

        else
        {
            System.out.print("NO");
        }
    }
}
