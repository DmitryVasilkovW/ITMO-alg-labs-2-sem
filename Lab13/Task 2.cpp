#include <iostream>
#include <vector>
#define scanner cin
#define Systemout cout
using namespace std;

long s1, s2;

namespace vec
{
	vector<int> hash1(1000000);
	vector<int> hash2(1000000);
}


namespace sol
{
	void ch();
	template<typename T>
	void soll(T n);
}

int main()
{
	long n;
	cin >> n;

	sol::soll(n);

	bool isEqual = true;

	for (long i = 0; i <= 10000; i++)
	{
		if (vec::hash1[i] != vec::hash2[i])
		{
			isEqual = false;
			break;
		}
	}

	sol::ch();
	return 0;
}

template<typename T>
void sol::soll(T n)
{
	for (long i = 0; i < n; i++)
	{
		long x;
		scanner >> x;
		s1 = (s1 + x) % 11111;
	}

	for (long i = 0; i < n; i++)
	{
		long x;
		scanner >> x;
		s2 = (s2 + x) % 11111;
	}
}

void sol::ch()
{
	if (s1 == s2)
	{
		Systemout << "YES" << endl;
	}
	else
	{
		Systemout << "NO" << endl;
	}
}
