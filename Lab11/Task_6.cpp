#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<string> ans;
map<pair<int, int>, int> del;
vector<pair<int, int>> arr;
pair<int, int> input;
vector<pair<char, pair<int, int>>> req;
char command;

template <typename T>
class Dsu
{
private:
	vector<T> parent;
	vector<T> rank;
public:
	Dsu(T n)
	{
		parent.resize(n);
		rank.resize(n);

		for (auto i = 0; i < n; i++)
		{
			parent[i] = i;
			rank[i] = 0;
		}
	}


	int find(T x)
	{
		if (parent[x] == x)
		{
			return x;
		}
		return parent[x] = find(parent[x]);
	}

	void union_sets(T x, T y)
	{
		int root_x = find(x);
		int root_y = find(y);
		if (root_x != root_y)
		{
			if (rank[root_x] < rank[root_y])
			{
				swap(root_x, root_y);
			}
			parent[root_y] = root_x;
			if (rank[root_x] == rank[root_y])
			{
				rank[root_x]++;
			}
		}
	}
};

void Ans()
{
	for (int i = ans.size() - 1; i >= 0; i--)
	{
		std::cout << ans[i];
	}
}

template <typename T>
void Input(T m)
{
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--, b--;
		if (a < b)
		{
			input.first = a;
			input.second = b;
		}
		else
		{
			input.first = b;
			input.second = a;
		}
		arr.push_back(input);
	}
}

template <typename T>
void Input_req(T q)
{
	for (int i = 0; i < q; i++)
	{
		int a, b;
		cin >> command >> a >> b;
		a--, b--;

		if (command == '-')
		{
			if (a < b)
			{
				del.emplace(make_pair(a, b), 7);
				req.emplace_back(command, make_pair(a, b));
			}
			if (a >= b)
			{
				del.emplace(make_pair(b, a), 7);
				req.emplace_back(command, make_pair(b, a));
			}
		}

		else
		{
			if (a < b)
			{
				req.emplace_back(command, make_pair(a, b));
			}
			if (a >= b)
			{
				req.emplace_back(command, make_pair(b, a));
			}
		}
	}
}

int main()
{
	int n, m, q;
	cin >> n >> m >> q;

	Dsu dsu(n);

	Input(m);

	Input_req(q);

	for (auto i : arr)
	{
		if (del[i] != 7)
		{
			dsu.union_sets(i.first, i.second);
		}
	}


	for (int i = q - 1; i >= 0; i--)
	{
		if (req[i].first == '?')
		{
			if (dsu.find(req[i].second.first) == dsu.find(req[i].second.second))
			{
				ans.push_back("YES\n");
			}
			else
			{
				ans.push_back("NO\n");
			}
		}

		else
		{
			dsu.union_sets(req[i].second.first, req[i].second.second);
		}
	}

	Ans();

	return 0;
}
