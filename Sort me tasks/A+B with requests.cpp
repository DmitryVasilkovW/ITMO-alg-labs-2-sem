#include <iostream>
int main()
{
    int a, b, t;
    std::cin >> t;
    for (int i = 0; i < t; i ++)
    {
        std::cin >> a >> b;
        std::cout << a + b << "\n";
    }
    return 0;
}
