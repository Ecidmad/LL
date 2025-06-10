#include <iostream>

void print(int A, int B)
{
    if (A == B)
    {
        std::cout << A << std::endl;
        return;
    }
    else if (A < B)
    {
        std::cout << A << std::endl;
        print(A + 1, B);
    }
    else
    {
        std::cout << A << std::endl;
        print(A - 1, B);
    }
}

int main()
{
    int A, B;
    std::cin >> A;
    std::cin >> B;
    print(A, B);
}