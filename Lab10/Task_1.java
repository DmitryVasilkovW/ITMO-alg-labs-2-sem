import java.util.Scanner;
import java.util.ArrayList;

public class Main
{
    static boolean[] ListOfTraps;
    static ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
    static int[] component;

    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);

        int n = input.nextInt();
        int m = input.nextInt();

        ListOfTraps = new boolean[n + 1];
        component = new int[n + 1];

        for (int i = 0; i <= n; i++)
        {
            graph.add(new ArrayList<>());
        }

        for (int i = 1; i <= m; i++)
        {
            int start = input.nextInt();
            int end = input.nextInt();

            graph.get(start).add(end);
            graph.get(end).add(start);
        }

        for (int i = 1; i <= n; i++)
        {
            int trap = input.nextInt();

            if (trap == 1)
            {
                ListOfTraps[i] = true;
            }
        }

        int numComponents = 0;

        for (int i = 1; i <= n; i++)
        {
            if (component[i] == 0)
            {
                numComponents++;
                dfs(i, numComponents);
            }
        }

        System.out.println(numComponents);

        for (int i = 1; i <= n; i++)
        {
            System.out.print(component[i] + " ");
        }

        System.out.println();

        boolean[] trapComponents = new boolean[numComponents + 1];

        for (int i = 1; i <= n; i++)
        {
            if (ListOfTraps[i]) {
                trapComponents[component[i]] = true;
            }
        }

        for (int i = 1; i <= numComponents; i++)
        {
            System.out.print(trapComponents[i] ? "1 " : "0 ");
        }

        System.out.println();
    }

    public static void dfs(int node, int componentNum)
    {
        component[node] = componentNum;

        for (int neighbour : graph.get(node))
        {
            if (component[neighbour] == 0)
            {
                dfs(neighbour, componentNum);
            }
        }
    }
}
