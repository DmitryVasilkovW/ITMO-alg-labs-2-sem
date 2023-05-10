import java.util.*;
import java.io.*;

public class Main 
{
    static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static void main(String[] args) throws IOException
    {
        int n = nextInt(), m = nextInt(), q = nextInt();
        boolean[][] blocked = new boolean[n][m];
        while (q-- > 0) {
            int x = nextInt()-1, y = nextInt()-1;
            blocked[x][y] = true;
        }
        List<Integer>[] g = new List[n*m];
        for (int i = 0; i < n*m; i++) {
            g[i] = new ArrayList<Integer>();
        }
        int[][] dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        for (int x = 0; x < n; x++) 
        {
            for (int y = 0; y < m; y++) 
            {
                if (blocked[x][y]) continue;
                int from = x*m + y;
                for (int[] d : dir) {
                    int nx = x + d[0], ny = y + d[1];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m || blocked[nx][ny]) continue;
                    int to = nx*m + ny;
                    g[from].add(to);
                }
            }
        }
        int[] match = new int[n*m];
        Arrays.fill(match, -1);
        boolean[] used = new boolean[n*m];
        for (int i = 0; i < n*m; i++) 
        {
            Arrays.fill(used, false);
            tryKuhn(i, g, match, used);
        }
        int ans = 0;
        for (int i = 0; i < n*m; i++) 
        {
            if (match[i] != -1) ans++;
        }
        System.out.println(ans);
    }

    static boolean tryKuhn(int v, List<Integer>[] g, int[] match, boolean[] used) 
    {
        if (used[v]) return false;
        used[v] = true;
        for (int to : g[v]) 
        {
            if (match[to] == -1 || tryKuhn(match[to], g, match, used)) 
            {
                match[to] = v;
                return true;
            }
        }
        return false;
    }

    static int nextInt() throws IOException 
    {
        while (st == null || !st.hasMoreTokens()) 
        {
            st = new StringTokenizer(in.readLine());
        }
        return Integer.parseInt(st.nextToken());
    }
}
