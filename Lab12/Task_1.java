import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        List<Edge> edges = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            int c = scanner.nextInt();
            edges.add(new Edge(a, b, c));
        }
        int minCost = findMinimumCost(edges, n);
        System.out.println(minCost);
    }

    private static int findMinimumCost(List<Edge> edges, int n) 
    {
        int minCost = 0;
        PriorityQueue<Edge> queue = new PriorityQueue<>(edges);
        DisjointSet set = new DisjointSet(n);
        while (!queue.isEmpty())
        {
            Edge edge = queue.poll();
            if (set.find(edge.from) != set.find(edge.to)) 
            { 
                set.union(edge.from, edge.to);
                minCost += edge.cost;
            }
        }
        int root = set.find(1);
        for (int i = 2; i <= n; i++) 
        {
            if (set.find(i) != root) 
            {
                return -1;
            }
        }
        return minCost;
    }
    
    private static class Edge implements Comparable<Edge>
    {
        int from;
        int to;
        int cost;

        public Edge(int from, int to, int cost) 
        {
            this.from = from;
            this.to = to;
            this.cost = cost;
        }

        public int compareTo(Edge other)
        {
            return Integer.compare(cost, other.cost);
        }
    }

    private static class DisjointSet
    {
        int[] parent; 
        int[] rank;

        public DisjointSet(int size) 
        {
            parent = new int[size + 1];
            rank = new int[size + 1];
            for (int i = 1; i <= size; i++) 
            {
                parent[i] = i;
                rank[i] = 0;
            }
        }

      
        public int find(int x) 
        {
            if (parent[x] != x)
            {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }
        
        public void union(int x, int y)
        {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX == rootY)
            {
                return;
            }
            if (rank[rootX] < rank[rootY])
            {
                parent[rootX] = rootY;
            }
            else if (rank[rootX] > rank[rootY]) 
            {
                parent[rootY] = rootX;
            } 
            else 
            {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
}
