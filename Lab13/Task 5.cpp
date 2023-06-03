#include <iostream>
#include <vector>

std::vector<std::vector<std::string>> array(3, std::vector<std::string> ());

unsigned int divider;
//unsigned int count = 0;
//unsigned int lim = 2;

struct BitField{
	unsigned int count1 : 19;
	unsigned int count2 : 19;
	unsigned int count3 : 19;
};

struct BitField2{
	unsigned long N : 4;
};

struct BitField3{
	unsigned long N : 2;
};

BitField field;

BitField2 field2;

BitField3 field3;


unsigned int create_hash(std::string key, unsigned int k)
{
	unsigned int h ;
	h = 0;
	unsigned int pow;
	pow = ++h;

	for (unsigned int i = 0; i < key.size(); i++)
	{
		h += (key[i] - 'a') * pow;
		pow *= k;
	}
	return h % divider;
}

namespace ad
{
	void add(std::vector<std::pair<unsigned int, std::string>> &arr, std::string key);
}

namespace Search_{
	template<typename T>
	bool Search(std::vector<std::pair<unsigned int, T>> &arr, const T key)
	{
		unsigned int m = 101;

		unsigned int h1 = create_hash(key, m);
		m += 2;
		unsigned int h2 = create_hash(key, m);

		if (arr[h1].first == h1 && arr[h1].second == key)
		{
			return true;
		}

		if (arr[h2].first == h2 && arr[h2].second == key)
		{
			return true;
		}

		return false;
	}

}

namespace dell
{
	bool pred(auto &arr, std::string key, unsigned int h)
	{
		if (arr[h].second == key) return true;
		return false;
	}

	void del(std::vector<std::pair<unsigned int, std::string>> &arr, std::string key);
}



//void rehash(std::vector<std::pair<unsigned int, std::string>> &arr)
//{
//	if(first){count = 0; lim *= 2;}
//	if(!first){{count1 = 0; lim1 *= 2;}}
//
//	unsigned int m = 14;
//
//	if(first) m = divider;
//	if(!first) m = divider1;
//
//	std::vector<std::pair<unsigned int, std::string>> new_table(m);
//
//
//
//	for (auto &item : arr)
//	{
//		if (item.second != "")
//		{
//			ad::add(new_table, item.second);
//		}
//	}
//
//	arr = new_table;
//
//	if (first) divider = arr.size();
//	if (!first) divider1 = arr.size();
//}



int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	unsigned int number_of_elements;
	std::cin >> number_of_elements;
	field3.N = 3;

	for (int i = 0; i < 3; i ++) array[i].resize(number_of_elements);

	field2.N = 13;


	std::vector<std::pair<unsigned int, std::string>> root (number_of_elements * field2.N);
	std::vector<std::pair<unsigned int, std::string>> tree (number_of_elements * field2.N);

	field.count1 = 0;
	field.count2 = 0;
	field.count3 = 0;

	divider = number_of_elements * field2.N;
	//divider1 = number_of_elements * N;

	std::string element;
	for (unsigned int i = 0; i < 3; i ++)
	{
		for (unsigned int j = 0; j < number_of_elements; j ++)
		{
			std::cin >> element;
			array[i][j] = element;
		}
	}

	for (unsigned int i = 0; i < number_of_elements; i ++)
	{
		ad::add(root, array[0][i]);
//		if (count > lim)
//		{
//			rehash(root);
//		}
//		first = false;
		ad::add(tree, array[1][i]);
//		if (count1 > lim1)
//		{
//			rehash(tree);
//		}
		//first = true;
	}

	for (unsigned int i = 0; i < number_of_elements; i ++)
	{
		if(!Search_::Search(tree, array[2][i]) && !Search_::Search(root, array[2][i]))
		{
			field.count3 += 3;
		}
		else if(!Search_::Search(tree, array[2][i]) || !Search_::Search(root, array[2][i]))
		{
			if(!Search_::Search(tree, array[2][i]) && Search_::Search(root, array[2][i]))
			{
				field.count3 ++;
			}
			else if(Search_::Search(tree, array[2][i]) && !Search_::Search(root, array[2][i]))
			{
				field.count3 ++;
			}
		}

	}

	for (unsigned int i = 0; i < number_of_elements; i ++) dell::del(tree, array[1][i]);


	for (unsigned int i = 0; i < number_of_elements; i ++) ad::add(tree, array[2][i]);


	for (unsigned int i = 0; i < number_of_elements; i ++)
	{
		if(!Search_::Search(tree, array[1][i]) && !Search_::Search(root, array[1][i]))
		{
			field.count2 += 3;
		}
		else if(!Search_::Search(tree, array[1][i]) || !Search_::Search(root, array[1][i]))
		{
			if(!Search_::Search(tree, array[1][i]) && Search_::Search(root, array[1][i]))
			{
				field.count2 ++;
			}
			else if(Search_::Search(tree, array[1][i]) && !Search_::Search(root, array[1][i]))
			{
				field.count2 ++;
			}
		}

	}

	for (unsigned int i = 0; i < number_of_elements; i ++)
	{
		dell::del(tree, array[2][i]);
		dell::del(root, array[0][i]);
	}


	for (unsigned int i = 0; i < number_of_elements; i ++)
	{
		ad::add(root, array[1][i]);
//		if (count > lim)
//		{
//			rehash(root);
//		}
//		first = false;
		ad::add(tree, array[2][i]);


	}

	for (unsigned int i = 0; i < number_of_elements; i ++)
	{
		if(!Search_::Search(tree, array[0][i]) && !Search_::Search(root, array[0][i]))
		{
			field.count1 += field3.N;
		}
		else if(!Search_::Search(tree, array[0][i]) || !Search_::Search(root, array[0][i]))
		{
			if(!Search_::Search(tree, array[0][i]) && Search_::Search(root, array[0][i]))
			{
				field.count1 ++;
			}
			else if(Search_::Search(tree, array[0][i]) && !Search_::Search(root, array[0][i]))
			{
				field.count1 ++;
			}
		}
		else if(Search_::Search(tree, array[0][i]) && Search_::Search(root, array[0][i]))
		{
			field.count1 += 0;
		}
	}

	std::cout << field.count1 << " " << field.count2 << " " << field.count3;
	return 0;
}

void dell::del(std::vector<std::pair<unsigned int, std::string>> &arr, std::string key)
{
	unsigned int m = 101;

	unsigned int h1 = create_hash(key, m);
	m += 2;
	unsigned int h2 = create_hash(key, m);

	if (pred(arr, key, h1))
	{
		arr[h1].first = 0;
		arr[h1].second = "";
		//counter--;
	}
	else if (pred(arr, key, h2))
	{
		arr[h2].first = 0;
		arr[h2].second = "";
		//counter--;
	}
}

void ad::add(std::vector<std::pair<unsigned int, std::string>> &arr, std::string key)
{
	//counter++;
	bool flag = true;
	unsigned int m = 101;

	for (unsigned int i = 0; i < 2; i++)
	{
		unsigned int h1 = create_hash(key, m);
		m += 2;
		unsigned int h2 = create_hash(key, m);

		if (arr[h1].first == 0 && arr[h1].second.empty())
		{
			arr[h1].first = h1;
			arr[h1].second = key;
			break;
		}

		if (arr[h2].first == 0 && arr[h2].second.empty())
		{
			arr[h2].first = h2;
			arr[h2].second = key;
			break;
		}

		unsigned int h = flag ? h1 : h2;



		std::swap(h1, arr[h].first);
		std::swap(key, arr[h].second);

		int fl = flag ? 1 : 0;
		fl ^= 1;
		flag = fl == 1;
	}
}
