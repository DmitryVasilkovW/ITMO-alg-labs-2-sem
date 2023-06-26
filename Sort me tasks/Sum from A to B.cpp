#include <iostream>
int main()
{
    long a, b, sum = 0;
    std::cin >> a >> b;
    if(a < b)
    {
        for (long i = a; i < b + 1; i ++)
        {
            sum += i;
        }
    }
    else if(a > b)
    {
        for (long i = b; i < a + 1; i ++)
        {
            sum += i;
        }
    }
    else if(a == b)
    {
        sum = a;
    }
    std::cout << sum << "\n";
    return 0;
}
