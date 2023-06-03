#include <iostream>
#include <vector>
using namespace std;

 

unsigned long long n;

string str = str.substr(0, str.size());
unsigned long long i = 1;
unsigned long long j = 0;

namespace sol
{
	void sol(auto &array);
}


int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
    getline(cin, str);


	n = str.length();
	vector<unsigned long long> array(n, 0);


	sol::sol(array);


    for (auto it : array)
	{
        cout << it << " ";
    }
    return 0;
}

void sol::sol(auto &array)
{
	while (i < n)
	{
		while (j > 0 && str[i] != str[j])
		{
			j = array[j - 1];
		}

		if (str[i] == str[j])
		{
			j++;
		}

		array[i] = j;
		i++;
	}
}
