
#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int n = 4;
    int graph[4][4] = {0};

    graph[0][1] = 10;
    graph[1][0] = 10;

    graph[0][2] = 6;
    graph[2][0] = 6;

    graph[0][3] = 5;
    graph[3][0] = 5;

    graph[1][3] = 15;
    graph[3][1] = 15;

    graph[2][3] = 4;
    graph[3][2] = 4;

    int key[4];
    bool selected[4];
    int parent[4];

    for (int i = 0; i < n; i++)
    {
        key[i] = INT_MAX;
        selected[i] = false;
        parent[i] = -1;
    }

    key[0] = 0;
    int totalCost = 0;

    for (int count = 0; count < n; count++)
    {
        int u = -1;
        int minValue = INT_MAX;

        for (int v = 0; v < n; v++)
        {
            if (!selected[v] && key[v] < minValue)
            {
                minValue = key[v];
                u = v;
            }
        }

        if (u == -1)
        {
            cout << "All cities cannot be connected.\n";
            return 0;
        }

        selected[u] = true;

        if (parent[u] != -1)
        {
            cout << parent[u] + 1 << " - " << u + 1
                 << " : " << key[u] << endl;

            totalCost += key[u];
        }

        for (int v = 0; v < n; v++)
        {
            if (graph[u][v] != 0 &&
                !selected[v] &&
                graph[u][v] < key[v])
            {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "Minimum construction cost: " << totalCost << endl;

    return 0;
}
