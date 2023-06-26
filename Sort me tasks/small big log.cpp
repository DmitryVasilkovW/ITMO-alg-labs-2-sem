#include<iostream>
#include <vector>
using namespace std;

bool check(vector<int>& logs, int k, int len) {
	int cuts = 0;
	for(int log : logs) {
		cuts += (log-1)/len;
		if(cuts > k) {
			return false;
		}
	}
	return true;
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> logs(n);
	int maxLen = 0;
	for(int i=0; i<n; i++) {
		cin >> logs[i];
		maxLen = max(maxLen, logs[i]);
	}
	int lo = 1, hi = maxLen, ans = 0;
	while(lo <= hi) {
		int mid = lo + (hi-lo)/2;
		if(check(logs, k, mid)) {
			ans = mid;
			hi = mid-1;
		} else {
			lo = mid+1;
		}
	}
	cout << ans << endl;
	return 0;
}

