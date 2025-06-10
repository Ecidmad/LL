#include <iostream>
using std::cout;
using std::endl;
int n;
void counting(const int& i)
{
    if (i <= 0) return;
    counting(i - 1);
    cout << i << endl;
}

int main()
{
    std::cin >> n;
    counting(n);
}