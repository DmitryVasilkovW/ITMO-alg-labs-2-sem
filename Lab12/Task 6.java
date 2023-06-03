import java.util.*;

public class Main
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();

        List<Edge> edges = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            int a = scanner.nextInt() - 1;
            int b = scanner.nextInt() - 1;
            int c = scanner.nextInt();
            edges.add(new Edge(a, b, c));
        }


        List<Edge> mst = kruskal(n, edges);

        int s1 = 0;
        for (Edge edge : mst)
        {
            s1 += edge.weight;
        }

        int s2 = Integer.MAX_VALUE;
        for (Edge edge : mst)
        {
            List<Edge> mstWithoutEdge = kruskalWithoutEdge(n, edges, edge);
            int s = 0;
            for (Edge e : mstWithoutEdge)
            {
                s += e.weight;
            }
            if (s < s2)
            {
                s2 = s;
            }
        }

        System.out.println(s1 + " " + s2);
    }

    private static List<Edge> kruskal(int n, List<Edge> edges)
    {
        List<Edge> result = new ArrayList<>();
        UnionFind unionFind = new UnionFind(n);
        Collections.sort(edges);

        for (Edge edge : edges)
        {
            if (unionFind.find(edge.from) != unionFind.find(edge.to))
            {
                result.add(edge);

                unionFind.union(edge.from, edge.to);
            }
        }

        return result;
    }


    private static List<Edge> kruskalWithoutEdge(int n, List<Edge> edges, Edge excludedEdge)
    {
        List<Edge> result = new ArrayList<>();
        UnionFind unionFind = new UnionFind(n);
        Collections.sort(edges);

        for (Edge edge : edges)
        {
            if (!edge.equals(excludedEdge) && unionFind.find(edge.from) != unionFind.find(edge.to))
            {
                result.add(edge);

                unionFind.union(edge.from, edge.to);
            }
        }

        return result;
    }

    private static class Edge implements Comparable<Edge>
    {
        private int from;
        private int to;
        private int weight;

        public Edge(int from, int to, int weight)
        {
            this.from = from;
            this.to = to;
            this.weight = weight;
        }

        public int compareTo(Edge o)
        {
            return Integer.compare(this.weight, o.weight);
        }

        public boolean equals(Object obj)
        {
            if (obj == null || getClass() != obj.getClass())
            {
                return false;
            }
            Edge edge = (Edge) obj;
            return this.from == edge.from && this.to == edge.to && this.weight == edge.weight;
        }
        
    }


    private static class UnionFind
    {
        private int[] parent;
        private int[] rank;

        public UnionFind(int n)
        {
            parent = new int[n];
            rank = new int[n];
            for (int i = 0; i < n; i++)
            {
                parent[i] = i;
            }
        }

        public int find(int x)
        {
            if (parent[x] == x)
            {
                return x;
            }
            parent[x] = find(parent[x]);
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
            } else if (rank[rootX] > rank[rootY])
            {
                parent[rootY] = rootX;
            } else {
                parent[rootX] = rootY;
                rank[rootY]++;
            }
        }
    }
}
