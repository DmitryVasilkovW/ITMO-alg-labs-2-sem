#include <iostream>
#include <regex>
#include <vector>

using namespace std;

void check(string &str, int i, bool &flag)
{
	if (i < 3)
	{
		regex regular("[A-Z][a-z]*");
		if (!regex_match(str, regular))
		{
			flag = false;
			return;
		}
	}

	if (i == 3)
	{
		regex regular("[0-9][0-9]");
		if (!regex_match(str, regular))
		{
			flag = false;
			return;
		}
	}

	if (i == 4)
	{
		regex regular1("^\\+7\\(([0-9]{3})\\)-([0-9]{3})-([0-9]{2})-([0-9]{2})$");
		regex regular2("^\\+7([0-9]{10})$");
		regex regular3("^\\+7\\(([0-9]{3})\\)([0-9]{3})-([0-9]{4})$");
		if (!regex_match(str, regular1) && !regex_match(str, regular2) && !regex_match(str, regular3))
		{
			flag = false;
			return;
		}
	}

	if (i == 5)
	{
		regex regular("g\\.[A-Z]{3},");
		if (!regex_match(str, regular))
		{
			flag = false;
			return;
		}
	}

	if (i == 6)
	{
		regex regular("ul\\.[A-Z][a-z]*,");
		if (!regex_match(str, regular))
		{
			flag = false;
			return;
		}
	}

	if (i == 7)
	{
		regex regular("d\\.[0-9]+");
		if (!regex_match(str, regular))
		{
			flag = false;
			return;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	for (int g = 0; g < n; g++)
	{
		char c;
		cin >> c;
		string inp;
		getline(cin, inp);
		inp = c + inp;

		vector<string> vec(8, "228");
		string tmp;
		int t = 0;

		for (char ch : inp)
		{
			if (!isspace(ch))
			{
				tmp += ch;
			}
			if (isspace(ch))
			{
				vec[t] = tmp;
				t++;
				tmp.clear();
			}
		}
		vec[t] = tmp;

		bool flag = true;
		for (const string &S : vec)
		{
			if (S == "228")
			{
				flag = false;
				break;
			}
		}

		if (!flag)
		{
			cout << "NO" << '\n';
			continue;
		}

		for (int i = 0; i < 8; i++)
		{
			string s = vec[i];
			if (i < 3 || i == 3 || i == 5 || i == 6 || i == 7)
			{
				check(s, i, flag);
			}
			else if (i == 4)
			{
				if (s[0] == '+' && s[1] != '7')
				{
					flag = false;
				}
				else if (s[0] == '+')
				{
					s.erase(remove(s.begin(), s.end(), '('), s.end());
					s.erase(remove(s.begin(), s.end(), ')'), s.end());
					s.erase(remove(s.begin(), s.end(), '-'), s.end());
					check(s, i, flag);
				}
			}

			if (!flag)
			{
				break;
			}
		}

		cout << (flag ? "YES" : "NO") << '\n';
	}

	return 0;
}
