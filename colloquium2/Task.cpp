#include <iostream>
#include <vector>
using namespace std;

//struct BitField{
//	unsigned int i : 19;
//	unsigned int j : 19;
//	unsigned long long count3 : 19;
//};

//BitField f;


namespace Prefix
{
	vector<int> PrefixFunction(const string_view& s);

	bool isPrimitiveSong(const string_view& song);
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);



	long N;
	char c;

	string song;
	cin >> N >> c;


	getline(cin, song);

	song = c + song;

	Prefix::isPrimitiveSong(song) ? cout << "YES" << "\n" : cout << "NO" << "\n";
	return 0;
}

vector<int> Prefix::PrefixFunction(const string_view& song)
{
	vector<int> prefix(song.length(), 0);

	for (int i = 1; i < song.length(); i++)
	{
		int j = prefix[i - 1];

		while (j > 0 && song[i] != song[j]) j = prefix[j - 1];

		if (song[i] == song[j]) j++;

		prefix[i] = j;
	}
	return prefix;
}

bool Prefix::isPrimitiveSong(const string_view& song)
{
	vector<int> prefix = PrefixFunction(song);
	int lastPrefix = prefix[song.length() - 1];
	return (song.length() % (song.length() - lastPrefix) == 0 && lastPrefix > 0);
}
