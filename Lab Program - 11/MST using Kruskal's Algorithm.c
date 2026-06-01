#include <stdio.h>

#define INF 9999

int p[10] = {0};

int applyfind(int i)
{
    while (p[i] != 0)
        i = p[i];
    return i;
}

int applyunion(int i, int j)
{
    if (i != j)
    {
        p[j] = i;
        return 1;
    }
    return 0;
}

int main()
{
    int cost[10][10] = {
        {INF, 2, INF, 6, INF},
        {2, INF, 3, 8, 5},
        {INF, 3, INF, INF, 7},
        {6, 8, INF, INF, 9},
        {INF, 5, 7, 9, INF}
    };

    int n = 5;
    int i, j;
    int ne = 1;
    int mincost = 0;
    int min, a, b, u, v;

    printf("Edges in Minimum Spanning Tree:\n\n");

    while (ne < n)
    {
        min = INF;

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = applyfind(u);
        v = applyfind(v);

        if (applyunion(u, v))
        {
            printf("%d to %d = %d\n", a, b, min);
            mincost += min;
            ne++;
        }

        cost[a][b] = cost[b][a] = INF;
    }

    printf("\nMinimum Cost = %d\n", mincost);

    return 0;
}
