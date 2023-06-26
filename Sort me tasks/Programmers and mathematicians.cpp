#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 10000000;

vector<bool> is_prime(MAXN + 1, true); 
vector<int> prime_sum(MAXN + 1, 0); 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;

  
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= k; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= k; j += i) {
                is_prime[j] = false;
            }
        }
    }

    
    for (int i = 2; i <= k; i++) {
        prime_sum[i] = prime_sum[i - 1] + is_prime[i];
    }

    
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (a > b) {
            swap(a, b);
        }
        b = min(b, k);
        a = max(a, 2);
        int count = prime_sum[b] - prime_sum[a - 1];
        cout << count << "\n";
    }
    return 0;
}
