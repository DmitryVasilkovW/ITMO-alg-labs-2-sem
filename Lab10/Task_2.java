import java.util.*;

class Vertex
{
    private int it;
    private List<Vertex> friends;

    public Vertex(int it)
    {
        this.it = it;
        this.friends = new ArrayList<>();
    }

    public void addFriend(Vertex friend)
    {
        friends.add(friend);
    }

    public void removeFriend(Vertex friend)
    {
        friends.remove(friend);
    }

    public boolean isFriend(Vertex other, boolean[] visited)
    {
        visited[it] = true;
        if (friends.contains(other))
        {
            return true;
        }
        for (Vertex friend : friends)
        {
            if (!visited[friend.it] && friend.isFriend(other, visited))
            {
                return true;
            }
        }
        return false;
    }
}

class Graph
{
    private Vertex[] vertices;

    public Graph(int n)
    {
        vertices = new Vertex[n + 1];
        for (int i = 1; i <= n; i++)
        {
            vertices[i] = new Vertex(i);
        }
    }

    public void addEdge(int a, int b)
    {
        Vertex vertexA = vertices[a];
        Vertex vertexB = vertices[b];
        vertexA.addFriend(vertexB);
        vertexB.addFriend(vertexA);
    }

    public void removeEdge(int a, int b)
    {
        Vertex vertexA = vertices[a];
        Vertex vertexB = vertices[b];
        vertexA.removeFriend(vertexB);
        vertexB.removeFriend(vertexA);
    }

    public boolean areFriends(int a, int b)
    {
        boolean[] visited = new boolean[vertices.length];
        return vertices[a].isFriend(vertices[b], visited);
    }
}

public class Main
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);

        int n = input.nextInt();
        int m = input.nextInt();
        int q = input.nextInt();

        Graph graph = new Graph(n);

        for (int i = 0; i < m; i++)
        {
            int a = input.nextInt();
            int b = input.nextInt();
            graph.addEdge(a, b);
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < q; i++)
        {
            String type = input.next();
            int a = input.nextInt();
            int b = input.nextInt();

            if (type.equals("?") && a == b)
            {
                sb.append("YES\n");
            }

            else if (type.equals("?"))
            {
                sb.append(graph.areFriends(a, b) ? "YES\n" : "NO\n");
            }

            else
            {
                graph.removeEdge(a, b);
            }
        }
        System.out.print(sb);
    }
}
