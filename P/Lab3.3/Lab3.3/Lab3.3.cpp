#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void quicksort(vector<vector<int>>& arr, int n, int m)
{
    if (n < m)
    {
        int pivot = arr[m][0];
        int i = n - 1;

        for (int j = n; j < m; j++)
        {
            if (arr[j][0] < pivot)
            {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[m]);
        int j = i + 1;
        quicksort(arr, n, j - 1);
        quicksort(arr, j + 1, m);
    }
}
int main()
{
    const int rows = 10;
    const int cols = 5;
    vector<vector<int>> array(rows, vector<int>(cols));
    std::srand(std::time(nullptr));
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            array[i][j] = rand() % (61 - 5 + 1) + 5;
        }
    }
    cout << "The original: \n";
    for (const auto& row : array)
    {
        for (const auto& elem : row)
        {
            cout << elem << " ";
        }
        cout << endl;
    }
    quicksort(array, 0, rows - 1);
    cout << "Sorted: \n";
    for (const auto& row : array)
    {
        for (const auto& elem : row)
        {
            cout << elem << " ";
        }
        cout << endl;
    }
}