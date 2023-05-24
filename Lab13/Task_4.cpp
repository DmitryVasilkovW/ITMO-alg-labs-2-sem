#include <iostream>
#include <vector>
#define scanner cin
#define Systemout cout
using namespace std;

const int MAXN = 10000000;

namespace var
{
	vector<int> h;
	vector<int> cnt;
	int n;
	int ans = 0;
}


namespace sol
{
	void sl();
}

namespace inp
{
	void in();
}

int main()
{
	scanner >> var::n;
	var::h.resize(var::n);

	inp::in();
	var::cnt.resize(MAXN * 2 + 1, 0);

	sol::sl();

	Systemout << var::ans << endl;
	return 0;
}


void inp::in()
{
	for (int i = 0; i < var::n; i++)
	{
		scanner >> var::h[i];
	}
}

void sol::sl()
{
	for (int i = 0; i < var::n; i++)
		{
			int sum = i - var::h[i] + MAXN;
			var::ans += var::cnt[sum];
			var::cnt[sum]++;
		}
}
