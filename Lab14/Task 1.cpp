#include <iostream>
#include <vector>
using namespace std;
 
string T, X;

//struct BitField{
//	string T : 20;
//};

vector<unsigned long long> indices;

namespace sol
{
	auto sol(unsigned long long count)
	{
		for (unsigned long long i = 0; i < T.length(); i++)
		{
			bool match = true;
			for (unsigned long long j = 0; j < X.length(); j++)
			{
				if (T[i + j] != X[j])
				{
					match = false;
					break;
				}
			}
			if (match)
			{
				count++;
				indices.push_back(i);
			}
		}
		return count;
	}
}


int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	getline(cin, T);
	getline(cin, X);

	cout << sol::sol(0) << endl;

	for (unsigned long long i = 0; i < indices.size(); i++)
	{
		cout << indices[i] << " ";
	}

	return 0;
}
