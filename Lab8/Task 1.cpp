#include <iostream>
#include <string>
#include <vector>

std::vector<int>first_int;
std::vector<char>first_char;
std::vector<int>second_int;
std::vector<char>second_char;

short swich = 1;

void Swich()
{
	if (swich ==  1)
	{
		swich++;
	}
	else
	{
		swich--;
	}
}

int delta()
{
	int sum1 = 0;
	int sum2 = 0;
	for (int i = 0; i < first_int.size(); i ++)
	{
		sum1 += first_int[i];
	}
	for (int i = 0; i < second_int.size(); i ++)
	{
		sum2 += second_int[i];
	}
	return abs(sum1 - sum2);
}

int sum()
{
	int sum = 0;
	if (swich == 1)
	{
		for (int i = 0; i < first_int.size(); i ++)
		{
			sum += first_int[i];
		}
	}
	else
	{
		for (int i = 0; i < second_int.size(); i ++)
		{
			sum += second_int[i];
		}
	}
	return sum;
}

void parser(std::string line)
{
	std::string str;
	for (int i = 0; i < line.length(); i++)
	{
		if (i == 0 && swich == 1)
		{
			first_char.push_back(line[0]);
		}
		else if (isalpha(line[i]) && swich == 1)
		{
			first_char.push_back(line[i]);
			first_int.push_back(std::stoi(str));
			str = "";
		}
		else if (i == line.length() - 1 && swich == 1)
		{
			str += line[i];
			first_int.push_back(std::stoi(str));
			str = "";
		}
		else if (isdigit(line[i]) && swich == 1)
		{
			str += line[i];
		}
		if (i == 0 && swich == 2)
		{
			second_char.push_back(line[0]);
		}
		else if (isalpha(line[i]) && swich == 2)
		{
			second_char.push_back(line[i]);
			second_int.push_back(std::stoi(str));
			str = "";
		}
		else if (i == line.length() - 1 && swich == 2)
		{
			str += line[i];
			second_int.push_back(std::stoi(str));
			str = "";
		}
		else if (isdigit(line[i]) && swich == 2)
		{
			str += line[i];
		}
	}
}

int main()
{
	int first_line_length, second_line_length, k;
	std::string first_line;
	std::string second_line;
	std::cin >> first_line_length >> second_line_length >> k;
	std::cin >> first_line;
	std::cin >> second_line;

	parser(first_line);
	Swich();
	parser(second_line);
	Swich();
	k -= delta();

	if (k < 0)
	{
		std::cout << "No";
		return 0;
	}

	int sum1, sum2;
	sum1 = sum();
	Swich();
	sum2 = sum();
	Swich();

	if (std::max(sum1, sum2) < k)
	{
		std::cout << "Yes";
		return 0;
	}

	int fit = 0;
	int sit = 0;

	while(fit < first_char.size() && sit < second_char.size())
	{
		if(first_char[fit] == second_char[sit])
		{
			if(first_int[fit] > second_int[sit])
			{
				first_int[fit] -= second_int[sit];
				sit ++;
			}

			else if(first_int[fit] == second_int[sit])
			{
				sit ++;
				fit ++;
			}

			else if(first_int[fit] < second_int[sit])
			{
				 second_int[sit] -= first_int[fit];
				 fit ++;
			}
		}

		else if(first_char[fit] != second_char[sit])
		{
			if(first_int[fit] > second_int[sit])
			{
				first_int[fit] -= second_int[sit];
				k -= second_int[sit];
				sit ++;
			}

			else if(first_int[fit] == second_int[sit])
			{
				k -= second_int[sit];
				sit ++;
				fit ++;
			}

			else if(first_int[fit] < second_int[sit])
			{
				second_int[sit] -= first_int[fit];
				k -= first_int[fit];
				fit ++;
			}
		}
	}
	if (k >= 0)
	{
		std::cout << "Yes";
	}
	else
	{
		std::cout << "No";
	}
	return 0;
}
