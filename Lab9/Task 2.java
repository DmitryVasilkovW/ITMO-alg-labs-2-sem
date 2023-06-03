import java.util.ArrayList;
import java.util.Scanner;

public class Main
{
    static ArrayList<ArrayList<Integer>> List;
    static ArrayList<Integer> visited;


    public static boolean dfs(int u, int p)
    {
        visited.set(u, 1);

        for (int i = 0; i < List.get(u).size(); i ++)
        {
            int next = List.get(u).get(i);

            if (next != p)
            {
                if (visited.get(next) == 0)
                {
                   if (dfs(next, u))
                   {
                       return true;
                   }
                }

                if (visited.get(next) == 1)
                {
                    return true;
                }
            }
        }
        visited.set(u, 3);
        return false;
    }

    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);

        int n = input.nextInt();
        int m = input.nextInt();

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
        for (int i = 0; i < n; i++)
        {
            if (visited.get(i) == 0)
            {
                if (dfs(i, -1))
                {
                    System.out.print("YES");
                    return;
                }
            }
        }
        System.out.print("NO");
    }
}
