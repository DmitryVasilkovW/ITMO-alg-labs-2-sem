#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 200005;

int n;
long long a[MAX_N];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	long long ans = 1;
	for (int i = 0; i < n; i++) {
		if (a[i] <= ans) {
			ans += a[i];
		} else {
			break;
		}
	}
	cout << ans << endl;
	return 0;
}
