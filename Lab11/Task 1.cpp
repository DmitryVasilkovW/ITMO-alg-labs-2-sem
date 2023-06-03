#include <iostream>

int INF = 1000007;

int N, M, K;

void floyd_warshall(int* adj)
{
	for (int a = 0; a < N; a++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if ((abs(a - i) <= K) && (abs(a - j) <= K))
				{
					if ((adj[i*N + a] + adj[a*N + j] < adj[i*N + j]) && (adj[i*N + a] != INF) && (adj[a*N + j] != INF))
					{
						adj[i*N + j] = adj[i*N + a] + adj[a*N + j];
					}
				}
			}
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	std::cin >> N >> M >> K;

	int* adj = new int[N*N];

	for (int i = 0; i < N*N; i++)
	{
		adj[i] = INF;
	}

	for (int i = 0; i < N; i++)
	{
		adj[i*N + i] = 0;
	}

	for (int i = 0; i < M; i++)
	{
		int u, v, w;
		std::cin >> u >> v >> w;
		u--;
		v--;
		adj[u*N + v] = w;
	}

	int Q;
	std::cin >> Q;

	floyd_warshall(adj);

	for (int i = 0; i < Q; i++)
	{
		int s, t;
		std::cin >> s >> t;

		s--;
		t--;

		std::cout << (adj[s*N + t] != INF ? adj[s*N + t] : -1) << "\n";
	}

	return 0;
}
