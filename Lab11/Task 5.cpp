#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge
{
int it, weight;
Edge(int it, int weight)
{
this->it = it;
this->weight = weight;
}
};

vector<vector<Edge>> graph;
vector<int> dist;
vector<bool> visited;

void dijkstra(int s);

int main()
{
int n, m, s, t;
cin >> n >> m >> s >> t;
s--;
t--;


dist.resize(n, INT_MAX);
visited.resize(n, false);

graph.resize(n);
for (int i = 0; i < m; i++) 
{
    int a, b, w;
    cin >> a >> b >> w;
    a--;
    b--;
    graph[a].push_back(Edge(b, w));
}

dijkstra(s);

if (dist[t] == INT_MAX) 
{
    cout << -1 << endl;
} 
else 
{
    cout << dist[t] << endl;
}
}

void dijkstra(int s)
{
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
pq.push(make_pair(0, s));
dist[s] = 0;

while (!pq.empty()) 
{
    int u = pq.top().second;
    pq.pop();

    if (visited[u])
    {
        continue;
    }
    visited[u] = true;

    for (Edge e : graph[u]) 
    {
        int v = e.it;
        int weight = e.weight;

        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) 
        {
            dist[v] = dist[u] + weight;
            pq.push(make_pair(dist[v], v));
        }
    }
}
}
