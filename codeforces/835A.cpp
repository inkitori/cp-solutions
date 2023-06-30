#include <iostream>

int main()
{
    int s, v1, v2, t1, t2;
    int first, second;
    std::cin >> s >> v1 >> v2 >> t1 >> t2;

    first = (v1 * s) + (2 * t1);
    second = (v2 * s) + (2 * t2);

    if (first < second)
    {
        std::cout << "First";
    }
    else if (second < first)
    {
        std::cout << "Second";
    }
    else
    {
        std::cout << "Friendship";
    }
}