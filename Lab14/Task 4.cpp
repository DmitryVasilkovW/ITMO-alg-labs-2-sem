
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Node{
public:
	string value;
	long long count;
	long long size;
	Node* left;
	Node* right;

	Node(const string& value) 
	{
		this->value = value;
		this->count = 1;
		this->size = 1;
		this->left = nullptr;
		this->right = nullptr;
	}
};

map<string, Node*> nod;
Node* Root;

namespace tree 
{
	template<typename T>
	void add(const T& val);

	template<typename T>
	string Search(T index);
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long n;
	cin >> n;

	vector<string> strings;
	string s;

	for (long long i = 0; i < n; i++)
	{
		cin >> s;
		if (!isdigit(s[0])) tree::add(s);
		else cout << tree::Search(stoi(s) - 1) << "\n";
	}

	return 0;
}

template<typename T>
void tree::add(const T& val) 
{
	if (nod.empty()) 
	{
		nod[val] = new Node(val);
		Root = nod[val];
	}
	else 
	{
		Node* node = Root;
		while (true)
		{
			++node->size;
			if (val == node->value) 
			{
				++node->count;
				break;
			}
			else if (val < node->value)
			{
				if (node->left == nullptr) 
				{
					nod[val] = new Node(val);
					node->left = nod[val];
					break;
				}
				else 
				{
					node = node->left;
				}
			}
			else 
			{
				if (node->right == nullptr)
				{
					nod[val] = new Node(val);
					node->right = nod[val];
					break;
				}
				else 
				{
					node = node->right;
				}
			}
		}
	}
}

template<typename T>
string tree::Search(T index) 
{
	Node* node = Root;
	while (node != nullptr)
	{
		long long leftSize = node->left != nullptr ? node->left->size : 0;
		if (index < leftSize) 
		{
			node = node->left;
		}
		else if (index - leftSize < node->count) 
		{
			return node->value;
		}
		else
		{
			index -= leftSize + node->count;
			node = node->right;
		}
	}

	return "";
}
