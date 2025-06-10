#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int Peak(const vector<vector<int>>& graph, int start, int finish)
{
    vector<int> dist(graph.size(), INT_MAX);
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, start));
    while (!pq.empty())
    {
        int curr = pq.top().second;
        pq.pop();
        if (curr == finish)
        {
            return dist[curr];
        }
        for (int i = 0; i < graph.size(); i++)
        {
            if (graph[curr][i] != -1)
            {
                int new_distance = dist[curr] + graph[curr][i];
                if (new_distance < dist[i])
                {
                    dist[i] = new_distance;
                    pq.push(make_pair(new_distance, i));
                }
            }
        }
    }
    return -1;
}
int main()
{
    int N, S, F;
    cin >> N >> S >> F;
    vector<vector<int>> graph(N, vector<int>(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> graph[i][j];
        }
    }
    int distance = Peak(graph, S - 1, F - 1);
    cout << distance << endl;
}