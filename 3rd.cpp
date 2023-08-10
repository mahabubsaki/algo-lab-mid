#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 3;
const long long INF = 1e18;
long long d[N][N];
int main()
{
    int nodes, edges, queries;
    cin >> nodes >> edges >> queries;
    for (int i = 1; i <= nodes; i++)
    {
        for (int j = 1; j <= nodes; j++)
        {
            d[i][j] = INF;
        }
    }

    for (int i = 0; i < edges; i++)
    {
        int from, to;
        long long weight;
        cin >> from >> to >> weight;
        d[from][to] = min(d[from][to], weight);
        d[to][from] = min(d[to][from], weight);
    }

    for (int i = 1; i <= nodes; i++)
    {
        d[i][i] = 0;
    }

    for (int k = 1; k <= nodes; k++)
    {
        for (int u = 1; u <= nodes; u++)
        {
            for (int v = 1; v <= nodes; v++)
            {
                d[u][v] = min(d[u][v], d[u][k] + d[k][v]);
            }
        }
    }
    for (int i = 0; i < queries; i++)
    {
        int u, v;
        cin >> u >> v;
        if (d[u][v] == INF)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << d[u][v] << endl;
        }
    }

    return 0;
}