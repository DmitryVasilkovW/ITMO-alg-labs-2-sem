
import java.util.Scanner;

public class Main
{

    public static void dfs(char[][] martix, int it1, int it2)
    {
        if (it1 < 0 || it2 < 0)
        {
            return;
        }

        if (it1 >= martix.length || it2 >= martix[0].length)
        {
            return;
        }

        if (martix[it1][it2] == '#')
        {
            return;
        }

        martix[it1][it2] = '#';

        dfs(martix, it1 - 1, it2);
        dfs(martix, it1 + 1, it2);
        dfs(martix, it1, it2 - 1);
        dfs(martix, it1, it2 + 1);
    }

    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);

        int count = 0;
        int n = input.nextInt();
        int m = input.nextInt();

        char[][] matrix = new char[n][m];

        for (int i = 0; i < n; i++)
        {
            String line = input.next();

            for (int j = 0; j < m; j++)
            {
                matrix[i][j] = line.charAt(j);
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == '.')
                {
                    count++;
                    dfs(matrix, i, j);
                }
            }
        }

        System.out.println(count);
    }
}
