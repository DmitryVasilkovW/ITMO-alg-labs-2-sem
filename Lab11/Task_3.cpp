#include <iostream>
#include <vector>


struct Edge
		{
	int start;
	int end;
	int weight;
};

bool hasNegativeCycle(std::vector<Edge>& edges, int n, int k)
{
	const int INF = 1e9;

	std::vector<int> dist(n + 1, INF);
	dist[1] = 0;

	for (int i = 0; i < n - 1; i++)
	{
		for (const Edge& edge : edges)
		{
			if (dist[edge.start] < INF)
			{
				dist[edge.end] = std::min(dist[edge.end], dist[edge.start] + edge.weight);
			}
		}
	}


	for (const Edge& edge : edges) 
	{
		if (dist[edge.start] < INF && dist[edge.start] + edge.weight < dist[edge.end]) 
		{

			return true;
		}
	}

	return false;
}

int main() 
{
	int N, k;
	std::cin >> N >> k;

	std::vector<bool> results;

	for (int i = 0; i < N; i++)
	{
		int n, m;
		std::cin >> n >> m;

		std::vector<Edge> edges(m);
		for (int j = 0; j < m; j++)
		{
			std::cin >> edges[j].start >> edges[j].end >> edges[j].weight;
		}

		bool result = hasNegativeCycle(edges, n, k);
		results.push_back(result);
	}


	for (bool result : results) 
	{
		if (result)
		{
			std::cout << "NO" << std::endl;
		} 
		else 
		{
			std::cout << "YES" << std::endl;
		}
	}

	return 0;
}
