#include <iostream>

int main()
{
    int n, tmp, sum = 0, problems = 0;

    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cin >> tmp;
            sum += tmp;
        }

        if (sum >= 2)
        {
            problems++;
        }

        sum = 0;
    }

    std::cout << problems;
}