#include <iostream>
#include <cstdlib>
#include <cstring>
struct Student {
    char name[50];
    int id;
};
int comp(const void* n, const void* m)
{
    const Student* studentA = (const Student*)n;
    const Student* studentB = (const Student*)m;
    return strcmp(studentA->name, studentB->name);
}
int main()
{
    Student students[] =
    {
        {"Fail", 1},
        {"Fool", 2},
        {"Fuel", 3},
        {"Food", 4},
        {"Ramen", 5}
    };
    int num = sizeof(students) / sizeof(students[0]);
    qsort(students, num, sizeof(Student), comp);
    std::cout << "Sorted: \n";
    for (int i = 0; i < num; ++i)
    {
        std::cout << students[i].name << " " << students[i].id << "\n";
    }
}