#include <iostream>
#include <vector>

using namespace std;

bool isMirrorEqual(const vector<size_t>& arr, size_t k, size_t n)
{
	for (size_t i = 0; i < k; i++)
	{
		int K = k - 1;
		if (arr[K - i] != arr[k + i])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	size_t  N, M;
	cin >> N >> M;

	vector<size_t > cards(N);
	for (size_t  i = 0; i < N; i++)
	{
		cin >> cards[i];
	}

	vector<size_t> possiblePositions;
	for (size_t  i = 0; i < N; i++)
	{
		if (isMirrorEqual(cards, i, N))
		{
			possiblePositions.push_back(N - i);
		}
	}


	for (int i =  possiblePositions.size() - 1; i >=  0; i--)
	{
		cout << possiblePositions[i] << " ";
	}

	return 0;
}
