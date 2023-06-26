#include <iostream>
using namespace std;

int main() {
    long n, m;
    cin >> n;
    long a[n + 1];
    long s[n + 1]; 
    s[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i-1] + a[i]; 
    }
    cin >> m;
    for (long i = 0; i < m; i++) {
        long l, r;
        cin >> l >> r;
        if (l > r) {
            cout << 0 << " ";
        } else {
            long sum = s[r] - s[l-1]; 
            cout << sum << " ";
        }
    }
    return 0;
}
