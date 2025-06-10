#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Box
{
    int weight;
    int stability;
};
bool compBox(const Box& a, const Box& b)
{
    return (a.stability + a.weight) < (b.stability + b.weight);
}
int main()
{
    int n;
    cin >> n;
    vector<Box> b(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> b[i].weight >> b[i].stability;
    }
    sort(b.begin(), b.end(), compBox);
    priority_queue<int> max_heap;
    int tW = 0;
    int mB = 0;
    for (const auto& box : b)
    {
        if (tW <= box.stability)
        {
            tW += box.weight;
            max_heap.push(box.weight);
            mB++;
        }
        else if (!max_heap.empty() && max_heap.top() > box.weight)
        {
            tW -= max_heap.top();
            max_heap.pop();
            tW += box.weight;
            max_heap.push(box.weight);
        }
    }
    cout << mB << endl;
}