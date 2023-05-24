#include <iostream>
#include <vector>

using namespace std;

long long N = 9;

vector<long long> arr1;
vector<long long> arr2;

long long Hash(long long key)
{
	return key * 101 % N;
}

void add(auto &arr, auto val)
{
	long long h = Hash(val);
	while (arr[h] != -1 && arr[h] != val) h = (h + 1) % N;
	arr[h] = val;
}

void Search(auto key, auto key1, auto &counter)
{
	long long h = Hash(key);
	long long h1 = Hash(key1);
	if (arr1[h] == -1 && arr2[h1] == -1) counter++;
}

int main()
{
	long long n, h, h1, counter = 0, x, y;
	cin >> n;
	N = n;
	arr1.resize(n, -1);
	arr2.resize(n, -1);
	for (long long i = 0; i < n; i++)
	{
		cin >> x >> y;

		Search(x, y, counter);

		add(arr1, x);
		add(arr2, y);
	}

	if (counter <= 3)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
}
