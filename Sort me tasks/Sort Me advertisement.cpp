#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n;
	cin >> n;

	vector<long long> a(n);
	for (auto& x : a) {
		cin >> x;
	}

	unordered_map<long long, long long> cnt;
	for (auto& x : a) {
		cnt[x]++;
	}

	vector<long long> unique_a;
	for (auto& x : cnt) {
		unique_a.push_back(x.first);
	}
	sort(unique_a.begin(), unique_a.end());

	long long ans = 0;
	for (auto it = unique_a.begin(); it != unique_a.end(); it++) {
		for (auto jt = it+1; jt != unique_a.end(); jt++) {
			long long x = *it ^ *jt;
			if (x < *jt) {
				continue;
			}
			if (cnt.count(x)) {
				if (x == *it || x == *jt) {
					ans += cnt.at(x) * (cnt.at(x)-1) / 2 * cnt.at(*it);
				} else {
					ans += cnt.at(x) * cnt.at(*it) * cnt.at(*jt);
				}
			}
		}
	}

	cout << ans << '\n';

	return 0;
}
