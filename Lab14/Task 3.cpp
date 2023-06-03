#include <iostream>
using namespace std;

struct BitField{
	unsigned int count : 20;
};
long long n, m;
BitField f;
string str;

void sol()
{
	for (long long i = 0; i < m; i++)
	{
		long long a, b, c;
		cin >> a >> b >> c;
		string word1 = str.substr(a - 1, c);
		string word2 = str.substr(b - 1, c);
		if (word1 == word2)
		{
			f.count++;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	cin >> str;

	f.count = 0;

	sol();

	cout << f.count << endl;
	return 0;
}
