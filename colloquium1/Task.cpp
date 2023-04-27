#include <iostream>
#include <vector>

using namespace std;

const long INF = 1e9;

struct Edge {
	long from, to, weight;
	Edge(long from_, long to_, long weight_): from(from_), to(to_), weight(weight_) {}
};

bool bellman_ford(const vector<Edge>& edges, const long n, vector<long>& dist) {
	dist.assign(n+1, INF);
	dist[1] = 0;
	for (long i = 0; i < n; i++) {
		bool any = false;
		for (auto& e : edges) {
			if (dist[e.from] < INF && dist[e.to] > dist[e.from] + e.weight) {
				dist[e.to] = dist[e.from] + e.weight;
				any = true;
			}
		}
		if (!any) break;
	}

	for (auto& e : edges) {
		if (dist[e.from] < INF && dist[e.to] > dist[e.from] + e.weight) {
			return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	long n, m;
	cin >> n >> m;

	vector<Edge> edges;
	for (long i = 0; i < m; ++i) {
		long u, v, w;
		cin >> u >> v >> w;
		edges.emplace_back(u, v, w);
		edges.emplace_back(v, u, w);
	}

	vector<long> dist;
	if (bellman_ford(edges, n, dist)) {
		cout << "1\n";
	} else {
		cout << "-1\n";
	}

	return 0;
}
