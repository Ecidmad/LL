#include <iostream>
#include <vector>
#include <algorithm>

struct Les
{
    int start;
    int end;
};
bool compLes(const Les& a, const Les& b)
{
    return a.end < b.end;
}
int main()
{
    int n;
    std::cin >> n;
    std::vector<Les> lectures(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> lectures[i].start >> lectures[i].end;
    }
    std::sort(lectures.begin(), lectures.end(), compLes);
    int count = 0;
    int lastEndTime = 0;
    for (const auto& lecture : lectures)
    {
        if (lecture.start >= lastEndTime)
        {
            ++count;
            lastEndTime = lecture.end;
        }
    }
    std::cout << count << std::endl;
}