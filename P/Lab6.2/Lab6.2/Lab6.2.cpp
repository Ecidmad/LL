#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct ridge
{
    int to;
};
int Fuel(int N, const vector<int>& cost, const vector<vector<ridge>>& graph)
{
    vector<int> minCost(N, INT_MAX);
    vector<bool> visited(N, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    minCost[0] = 0;
    pq.push({ 0, 0 });
    while (!pq.empty())
    {
        int u = pq.top().second;
        int current_cost = pq.top().first;
        pq.pop();
        if (u == N - 1)
            return current_cost;
        if (visited[u])
            continue;
        visited[u] = true;
        for (const ridge& edge : graph[u])
        {
            int v = edge.to;
            int new_cost = current_cost + cost[u];
            if (new_cost < minCost[v])
            {
                minCost[v] = new_cost;
                pq.push({ new_cost, v });
            }
        }
    }
    return -1;
}

int main()
{
    int N;
    cin >> N;
    vector<int> fuelCosts(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> fuelCosts[i];
    }
    int M;
    cin >> M;
    vector<vector<ridge>> graph(N);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        graph[u].push_back({ v });
        graph[v].push_back({ u });
    }
    int result = Fuel(N, fuelCosts, graph);
    cout << result << endl;
}