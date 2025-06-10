#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

using std::cout;
using std::endl;
bool is_final(const std::string& name)
{
    return name.back() == 'I';
}
template <typename T>
bool search(const T& start, const std::unordered_map<T, std::vector<T>>& graph, int& step_count, std::vector<T>& path)
{
    std::queue<T> search_queue;
    std::unordered_set<T> visited;
    std::unordered_map<T, int> steps;
    std::unordered_map<T, T> came_from;
    auto it = graph.find(start);
    if (it != graph.end())
    {
        for (auto&& neighbor : it->second)
        {
            search_queue.push(neighbor);
            steps[neighbor] = 1;
            came_from[neighbor] = start;
        }
    }

    while (!search_queue.empty())
    {
        T current = search_queue.front();
        search_queue.pop();
        if (visited.find(current) == visited.end())
        {
            if (is_final(current)) {
                step_count = steps[current];
                path.push_back(current);
                T at = current;
                while (at != start) {
                    at = came_from[at];
                    path.push_back(at);
                }
                std::reverse(path.begin(), path.end());
                return true;
            }
            auto neighbors = graph.find(current);
            if (neighbors != graph.end()) {
                for (auto&& neighbor : neighbors->second)
                {
                    if (visited.find(neighbor) == visited.end())
                    {
                        search_queue.push(neighbor);
                        steps[neighbor] = steps[current] + 1;
                        came_from[neighbor] = current;
                    }
                }
            }
            visited.insert(current);
        }
    }
    return false;
}
int main()
{
    std::unordered_map<std::string, std::vector<std::string>> g;
    g.insert({ "S", {"A", "B", "E", "D"} });
    g.insert({ "B", {"C"} });
    g.insert({ "C", {"J"} });
    g.insert({ "D", {"G","B"} });
    g.insert({ "E", {"G"} });
    g.insert({ "F", {"G"} });
    g.insert({ "G", {"H", "F", "J"} });
    g.insert({ "H", {"I"} });
    g.insert({ "J", {"I"} });
    std::string start_point = "S";
    int steps = 0;
    std::vector<std::string> shortest_way;
    bool result = search(start_point, g, steps, shortest_way);
    if (result)
    {
        cout << "Steps to final: " << steps << endl;
        cout << "Shortest path: ";
        for (size_t i = 0; i < shortest_way.size(); ++i)
        {
            cout << shortest_way[i];
            if (i != shortest_way.size() - 1)
            {
                cout << " -> ";
            }
        }
        cout << endl;
    }
    else
    {
        cout << "No way!\n";
    }
}