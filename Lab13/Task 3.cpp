#include <iostream>
#include <vector>

struct gr
{
	int sum;
	int count;
	int max;
	std::vector<int> b;
};

std::vector<gr> array;

struct st
{
	int isu;
	int points;
};

std::vector<std::vector<st>> map;

unsigned int divider;

unsigned int create_hash(int key, unsigned int k)
{
	return key * k % divider;
}

namespace ad
{
	void add(int gr, int isu, int b)
	{
		gr--;
		unsigned int m = 101;
		unsigned int h = create_hash(isu, m);

		st tmp;
		tmp.isu = isu;
		tmp.points = b;

		map[h].push_back(tmp);

		array[gr].count++;
		array[gr].max = std::max(array[gr].max, b);
		array[gr].sum += b;
		array[gr].b[b]++;
	}
}

namespace Search_
{
	void Search(int gr, char op)
	{
		gr--;
		if (op == 'a')
		{
			std::cout << array[gr].sum / array[gr].count << "\n";
		}
		else
		{
			std::cout << array[gr].max << "\n";
		}
	}
}

namespace dell
{
	void del(int gr, int isu)
	{
		gr--;
		unsigned int m = 101;
		unsigned int h = create_hash(isu, m);
		int i = 0;

		int poin = 0;

		for (auto it : map[h])
		{
			if (it.isu == isu)
			{
				poin = it.points;
			}
			i++;
		}

		i = 0;

		array[gr].count--;
		array[gr].sum -= poin;
		array[gr].b[poin]--;

		array[gr].max = 0;

		for (int j = 0; j < 101; j++)
		{
			if (array[gr].b[j] != 0)
			{
				array[gr].max = j;
			}
		}

		i = 0;

		for (auto &it : map[h])
		{
			if (it.isu == isu)
			{
				map[h].erase(map[h].begin() + i);
				break;
			}
			i++;
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	int m, q;
	std::cin >> m >> q;

	array.resize(m);
	for (auto &i : array)
	{
		i.b.resize(101);
	}

	map.resize(q);

	divider = m;

	for (int i = 0; i < q; i++)
	{
		char op;
		std::cin >> op;
		if (op == '+')
		{
			int grup, isu, po;
			std::cin >> grup >> isu >> po;
			ad::add(grup, isu, po);
		}
		else if (op == 'a' || op == 'm')
		{
			int grup;
			std::cin >> grup;
			Search_::Search(grup, op);
		}
		else if (op == '-')
		{
			int grup, isu;
			std::cin >> grup >> isu;
			dell::del(grup, isu);
		}
	}

	return 0;
}
