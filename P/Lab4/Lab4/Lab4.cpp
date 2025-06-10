#include <iostream>
#include <fstream>
#include <unordered_set> //Для хэш-таблицы
#include <vector>
#include <algorithm> //Для sort

int main()
{
    std::ifstream inFile("input.txt");
    std::ofstream outFile("output.txt");
    std::unordered_set<int> numbers;
    int n;
    while (inFile >> n)
    {
        if (n > 0)
        {
            numbers.insert(n);
        }
        else if (n < 0)
        {
            numbers.erase(-n);
        }
        else if (n == 0)
        {
            std::vector<int> sortNum(numbers.begin(), numbers.end());
            std::sort(sortNum.begin(), sortNum.end());
            for (const int& num : sortNum)
            {
                outFile << num << " ";
            }
            outFile << "\n";
            break;
        }
    }
    inFile.close();
    outFile.close();
}