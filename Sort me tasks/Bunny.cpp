#include <iostream>
long long sum = 1;
int main() 
{
	int n, k;
	int *arr;
	std::cin >> k >> n;
	arr = new int[n + 1];
	arr[0] = 1;
	for (int i = 1; i <= n; ++i) 
	{
		arr[i] = sum;
		if (k <= i) 
		{
			sum = 1000000007 + sum - arr[i - k];
		}
		sum = (sum + arr[i]) % 1000000007;
	}
	std::cout << arr[n];
	delete[] arr;
	return 0;
}
