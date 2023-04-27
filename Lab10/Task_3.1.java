import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));

        String[] input1 = input.readLine().split(" ");

        int n = Integer.parseInt(input1[0]);
        int m = Integer.parseInt(input1[1]);
        int q = Integer.parseInt(input1[2]);

        List<List<Integer>> adjList = new ArrayList<>();
        for (int i = 0; i <= n; i++)
        {
            adjList.add(new ArrayList<Integer>());
        }

        for (int i = 0; i < m; i++)
        {
            String[] input2 = input.readLine().split(" ");
            int start = Integer.parseInt(input2[0]);
            int end = Integer.parseInt(input2[1]);
            adjList.get(start).add(end);
        }

        for (int i = 0; i < q; i++)
        {
            String[] input3 = input.readLine().split(" ");
            int start = Integer.parseInt(input3[0]);
            int end = Integer.parseInt(input3[1]);

            if (canReach(start, end, adjList) && canReach(end, start, adjList))
            {
                System.out.println("YES");
            }

            else
            {
                System.out.println("NO");
            }
        }
    }

    public static boolean canReach(int start, int target, List<List<Integer>> adjList)
    {
        boolean[] visited = new boolean[adjList.size()];
        return dfs(start, target, visited, adjList);
    }

    public static boolean dfs(int current, int target, boolean[] visited, List<List<Integer>> adjList)
    {
        if (current == target)
        {
            return true;
        }

        visited[current] = true;
        for (int neighbor : adjList.get(current))
        {
            if (!visited[neighbor])
            {
                if (dfs(neighbor, target, visited, adjList))
                {
                    return true;
                }
            }
        }
        return false;
    }
}
