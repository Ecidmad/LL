#include <iostream>

void v(int n, int w = 2) {
    if (n < w)
    {
        return;
    }
    if (n % w == 0)
    {
        std::cout << w << " ";
        v(n / w, w);
    }
    else
    {
        v(n, w + 1);
    }
}

int main()
{
    int n;
    std::cin >> n;
    v(n);
}