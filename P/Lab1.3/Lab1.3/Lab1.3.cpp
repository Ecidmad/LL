#include <iostream>
#include <vector>
#include <string>
#include <algorithm>  //Для Swap
void selSort(std::vector<std::string>& phones) 
{
    int n = phones.size();
    for (int i = 0; i < n - 1; ++i)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) 
        {
            if (phones[j] < phones[minIndex]) 
            {
                minIndex = j;
            }
        }
        std::swap(phones[i], phones[minIndex]);
    }
}
void print(const std::vector<std::string>& phones) 
{
    for (const std::string& phone : phones) 
    {
        std::cout << phone << std::endl;
    }
}
int main() 
{
    std::vector<std::string> numbers = 
    {
        "77-89-77",
        "17-80-60",
        "12-34-56",
        "77-76-99",
        "00-00-01" 
    };
    std::cout << "The original:\n";
    print(numbers);
    selSort(numbers);
    std::cout << "\nSorted:\n";
    print(numbers);
}