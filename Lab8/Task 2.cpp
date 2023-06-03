#include <iostream>
#include <string>


int ch(std::string code)
{
	int mistake = 0;
	for (int i = 0; i < code.length(); i ++)
	{
		if (code[i] == '1')
		{
			mistake ^= i + 1;
		}
	}
	return mistake;
}

int main()
{
	int number_of_code;
	std::cin >> number_of_code;
	while (std::cin)
	{
		int mistake = 0;
		std::string Code;
		std::cin >> Code;
		mistake = ch(Code);

		if (mistake != 0)
		{
			Code[mistake - 1] ^= ('0' ^ '1');
		}

		for (int j = 0; j < Code.length(); j ++)
		{
			j ++;
			if((j & (j - 1)) && j - 1 == Code.length() - 1)
			{
				std::cout << Code[j - 1] << std::endl;
			}
			else if((j & (j - 1)))
			{
				std::cout << Code[j - 1];
			}
			j --;
		}
	}
	return 0;
}
