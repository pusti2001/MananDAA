#include <bits/stdc++.h>
using namespace std;

int minDistance(int *dist, bool *isIncluded, int vertices)
{
    int min = INT_MAX, minIndex = -1;
    for (int i = 0; i < vertices; i++)
    {
        if (isIncluded[i] == false && dist[i] <= min)
        {
            min = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void dijkstras(int graph[9][9], int *dist, int n, int src)
{
    bool isIncluded[n] = {0};
    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    for (int i = 0; i < n; i++)
    {
        int u = minDistance(dist, isIncluded, n);
        isIncluded[u] = true;
        for (int j = 0; j < n; j++)
            if ((!isIncluded[j]) && (graph[u][j] != 0))
                dist[j] = min(dist[j], dist[u] + graph[u][j]);
    }
}

int main()
{
    int n = 9, src = 0;
    int graph[9][9] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                       {4, 0, 8, 0, 0, 0, 0, 11, 0},
                       {0, 8, 0, 7, 0, 4, 0, 0, 2},
                       {0, 0, 7, 0, 9, 14, 0, 0, 0},
                       {0, 0, 0, 9, 0, 10, 0, 0, 0},
                       {0, 0, 4, 14, 10, 0, 2, 0, 0},
                       {0, 0, 0, 0, 0, 2, 0, 1, 6},
                       {8, 11, 0, 0, 0, 0, 1, 0, 7},
                       {0, 0, 2, 0, 0, 0, 6, 7, 0}};

    int dist[n];
    dijkstras(graph, dist, n, src);
    for (int i = 0; i < n; i++)
        cout << dist[i] << " ";

    return 0;
}