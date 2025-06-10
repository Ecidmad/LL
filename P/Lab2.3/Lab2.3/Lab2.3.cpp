#include <iostream>

int numbers(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return n % 10 + numbers(n / 10);
}
int main()
{
    int q;
    std::cin >> q;
    int sum = numbers(q);
    std::cout << q << " = " << sum;
}