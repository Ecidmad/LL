#include <iostream>
#include <vector>

using std::cout;
using std::endl;

template <typename T>
std::vector<T> quicksort(const std::vector<T>& arr)
{
    if (arr.size() < 2)
        return arr;
    const T* pivot = &arr.front() + arr.size() / 2 - 1;
    std::vector<T> less;
    std::vector<T> greater;
    for (const T* item = &arr.front(); item <= &arr.back(); item++)
    {
        if (item == pivot) continue;
        if (*item <= *pivot) less.push_back(*item);
        else greater.push_back(*item);
    }
    std::vector<T> sorted_less = quicksort(less);
    std::vector<T> sorted_greater = quicksort(greater);
    sorted_less.push_back(*pivot);
    sorted_less.insert(sorted_less.end(), sorted_greater.begin(), sorted_greater.end());
    return sorted_less;
}

int main()
{
    const int Size = 10;
    std::vector<int> arr;
    // Инициализация генератора
    std::srand(std::time(nullptr));
    for (int i = 0; i < Size; ++i) {
        arr.push_back(50 + std::rand() % 51);
    }
    cout << "Random: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    std::vector<int> sorted = quicksort(arr);
    cout << "\nSorted: ";
    for (int num : sorted)
    {
        cout << num << " ";
    }
}