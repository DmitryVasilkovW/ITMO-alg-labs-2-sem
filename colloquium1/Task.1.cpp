#include <iostream>
#include <vector>

using namespace std;

struct Edge {
	int start;
	int end;
	int result;
};

int main() {
	int n, m;
	cin >> n >> m;

	vector<Edge> edges(m);
	for (int i = 0; i < m; i++) {
		cin >> edges[i].start >> edges[i].end >> edges[i].result;
	}

	vector<int> dist(n + 1, 0);

	
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m; j++) {
			if (dist[edges[j].start] + edges[j].result < dist[edges[j].end]) {
				dist[edges[j].end] = dist[edges[j].start] + edges[j].result;
			}
		}
	}
	
	for (int j = 0; j < m; j++) {
		if (dist[edges[j].start] + edges[j].result < dist[edges[j].end]) {
			cout << 1 << endl;
			return 0;
		}
	}

	cout << -1 << endl; 

	return 0;
}
