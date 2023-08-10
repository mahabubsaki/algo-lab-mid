
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const long long int INF = 1e18;
long long int distanceArr[N];
int visited[N], parent[N];
int nodes, edges;
priority_queue<pair<long long int, int>> pq;

vector<pair<int, int>> adj_list[N];

void dijkstra(int node)
{
    pq.push({0, node});
    for (int i = 1; i <= nodes; i++)
    {
        distanceArr[i] = INF;
    }
    distanceArr[node] = 0;

    while (!pq.empty())

    {

        int head_node = pq.top().second;
        pq.pop();
        if (visited[head_node] == 0)
        {
            visited[head_node] = 1;
            for (auto adj_entry : adj_list[head_node])
            {

                int adj_node = adj_entry.first;

                int edge_cost = adj_entry.second;
                if (distanceArr[head_node] + edge_cost < distanceArr[adj_node])
                {
                    parent[adj_node] = head_node;
                    distanceArr[adj_node] = distanceArr[head_node] + edge_cost;
                    pq.push({-distanceArr[adj_node], adj_node});
                }
            }
        }
    }
}

int main()
{

    cin >> nodes >> edges;

    for (int i = 0; i < edges; i++)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        adj_list[from].push_back({to, weight});
        adj_list[to].push_back({from, weight});
    }

    int src = 1;

    dijkstra(src);
    if (visited[nodes] == 0)
    {
        cout << -1;
        return 0;
    }
    int current_node = nodes;
    vector<int> path;

    while (true)
    {
        path.push_back(current_node);
        if (current_node == src)
        {
            break;
        }
        current_node = parent[current_node];
    }
    reverse(path.begin(), path.end());

    for (auto node : path)
    {
        cout << node << " ";
    }

    return 0;
}
// 10 10
// 1 4 201
// 2 3 238
// 3 4 40
// 3 6 231
// 3 8 45
// 4 5 227
// 4 6 58
// 4 9 55
// 5 7 14
// 6 10 242
