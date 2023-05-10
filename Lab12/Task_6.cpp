#include <iostream>
#include <vector>

using namespace std;

long n, m;
long s1 = 0;

vector<pair<pair<long, long>, long>> edges;

namespace dsu
{
	class UnionFind
	{
	public:
		vector<long> parent;
		vector<long> rank;

		UnionFind(long n)
		{
			parent.resize(n);
			rank.resize(n, 0);

			for (long i = 0; i < n; i++)
			{
				parent[i] = i;
			}
		}

		long find(long x)
		{
			if (parent[x] == x)
			{
				return x;
			}
			parent[x] = find(parent[x]);
			return parent[x];
		}

		void unite(long x, long y)
		{
			long rootX = find(x);
			long rootY = find(y);

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
				parent[rootX] = rootY;
				rank[rootY]++;
			}
		}
	};
}

namespace kruskal
{
	vector<pair<pair<long, long>, long>> kruskal(vector<pair<pair<long, long>, long>>& edges);

	vector<pair<pair<long, long>, long>> kruskalWithoutEdge(vector<pair<pair<long, long>, long>>& edges, pair<pair<long, long>, long> excludedEdge);
}

namespace lab
{
	void input()
	{
		for (long i = 0; i < m; i++)
		{
			long a, b, c;
			cin >> a >> b >> c;
			edges.push_back(make_pair(make_pair(a - 1, b - 1), c));
		}
	}

	long ans(long s2, vector<pair<pair<long, long>, long>>& mst)
	{
		for (auto edge : mst)
		{
			vector<pair<pair<long, long>, long>> mstWithoutEdge = kruskal::kruskalWithoutEdge(edges, edge);
			long s = 0;
			for (auto e : mstWithoutEdge)
			{
				s += e.second;
			}
			if (s < s2)
			{
				s2 = s;
			}
		}
		return s2;
	}

	void Mst(vector<pair<pair<long, long>, long>>& mst)
	{
		for (auto edge : mst)
		{
			s1 += edge.second;
		}
	}
}

int main()
{
	cin >> n >> m;

	lab::input();

	vector<pair<pair<long, long>, long>> mst = kruskal::kruskal(edges);

	long s2 = INT_MAX;

	s2 = lab::ans(s2, mst);

	lab::Mst(mst);

	cout << s1 << " " << s2 << endl;

	return 0;
}

vector<pair<pair<long, long>, long>> kruskal::kruskalWithoutEdge(vector<pair<pair<long, long>, long>>& edges, pair<pair<long, long>, long> excludedEdge)
{
	vector<pair<pair<long, long>, long>> result;
	dsu::UnionFind uf(n);

	sort(edges.begin(), edges.end(), [](auto& a, auto& b) {return a.second < b.second;});

	for (auto edge : edges)
	{
		if (!(edge == excludedEdge) && uf.find(edge.first.first) != uf.find(edge.first.second))
		{
			result.push_back(edge);
			uf.unite(edge.first.first, edge.first.second);
		}
	}

	return result;
}

vector<pair<pair<long, long>, long>> kruskal::kruskal(vector<pair<pair<long, long>, long>>& edges) 
{
	vector<pair<pair<long, long>, long>> result;
	dsu::UnionFind uf(n);
	sort(edges.begin(), edges.end(), [](auto &a, auto &b) { return a.second < b.second; });

	for (auto edge: edges) {
		if (uf.find(edge.first.first) != uf.find(edge.first.second)) {
			result.push_back(edge);
			uf.unite(edge.first.first, edge.first.second);
		}
	}

	return result;
}
