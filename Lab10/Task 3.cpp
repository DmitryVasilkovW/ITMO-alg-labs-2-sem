#include <iostream>
#include <vector>


bool dfs(int current, int target, std::vector<std::vector<int>>& adjList, std::vector<bool>& visited)
{
	if (current == target)
	{
		return true;
	}

	visited[current] = true;
	for (int neighbor : adjList[current])
	{
		if (!visited[neighbor])
		{
			if (dfs(neighbor, target, adjList, visited))
			{
				return true;
			}
		}
	}

	return false;
}

bool canReach(int start, int target, std::vector<std::vector<int>>& adjList)
{
	std::vector<bool> visited(adjList.size(), false);
	return dfs(start, target, adjList, visited);
}

int main()
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	int n, m, q;
	std::cin >> n >> m >> q;

	std::vector<std::vector<int>> adjList(n + 1);

	for (int i = 0; i < m; i++)
	{
		int start, end;
		std::cin >> start >> end;
		adjList[start].push_back(end);
	}

	for (int i = 0; i < q; i++)
	{
		int start, end;
		std::cin >> start >> end;

		(canReach(start, end, adjList) && canReach(end, start, adjList)) ? std::cout << "YES\n" : std::cout << "NO\n";
	}

	return 0;
}
