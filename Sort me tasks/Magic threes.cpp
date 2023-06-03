#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
	int n;
	cin >> n;
	unordered_map<int, unordered_set<int>> pairs;
	for (int i = 1; i <= n; i++) {
		for (int j = i+1; j <= n; j++) {
			int prod = i*j;
			int root = sqrt(prod);
			if (root*root == prod) {
				pairs[i].insert(j);
			}
		}
	}
	long long cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (auto& p1 : pairs[i]) {
			for (auto& p2 : pairs[p1]) {
				if (pairs[i].count(p2)) {
					cnt++;
				}
			}
		}
	}
	cout << cnt << "\n";
	return 0;
}
