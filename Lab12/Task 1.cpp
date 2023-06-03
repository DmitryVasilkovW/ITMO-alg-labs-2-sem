#include <iostream>
using namespace std;

namespace lab
{
	const long MAXN = 1e5;
	const long MAXM = 1e6;

	long n, m;
	long parent[MAXN];

	pair<long, pair<long, long>> edges[MAXM];
}

namespace dsu
{
	template <typename T>
	auto find(T x)
	{
		if (lab::parent[x] == x) {
			return x;
		}
		return lab::parent[x] = find(lab::parent[x]);
	}

	template <typename T>
	void join(T x, T y)
	{
		x = find(x);
		y = find(y);
		if (x != y) {
			lab::parent[y] = x;
		}
	}
}

namespace kruskal
{
	long kruskal();
	void init();
	auto kruskal_fun(auto ans);
}


int main()
{
	cin >> lab::n >> lab::m;
	for (long i = 0; i < lab::m; i++)
	{
		long a, b, c;
		cin >> a >> b >> c;
		lab::edges[i] = {c, {a, b}};
	}
	cout << kruskal::kruskal() << endl;
	return 0;
}

void kruskal::init()
{
	for (auto i = 1; i <= lab::n; i++)
	{
		lab::parent[i] = i;
	}
}

auto kruskal::kruskal_fun(auto ans) 
{
	for (auto i = 0; i < lab::m; i++)
	{
		long a = lab::edges[i].second.first;
		long b = lab::edges[i].second.second;
		long w = lab::edges[i].first;
		if (dsu::find(a) != dsu::find(b))
		{
			dsu::join(a, b);
			ans += w;
		}
	}
	return ans;
}

long kruskal::kruskal()
{
	kruskal::init();

	sort(lab::edges, lab::edges + lab::m);
	long ans = 0;
	ans = kruskal::kruskal_fun(ans);
	
	return ans;
}
