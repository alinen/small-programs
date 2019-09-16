#include <iostream>

int main()
{
    int N;
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        float a, b, c;
        std::cin >> a;
        std::cin >> b;
        std::cin >> c;

        if (a - b == c) std::cout << "Possible\n";
        else if (b - a == c) std::cout << "Possible\n";
        else if (b + a == c) std::cout << "Possible\n";
        else if (a * b == c) std::cout << "Possible\n";
        else if (a != 0 && b / a == c) std::cout << "Possible\n";
        else if (b != 0 && a / b == c) std::cout << "Possible\n";
        else std::cout << "Impossible\n";
    }
}
