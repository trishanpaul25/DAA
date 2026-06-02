#include <stdio.h>

#define MAX 20

struct Edge
{
    int u, v, w;
};

struct Edge edge[MAX], temp;

int parent[MAX];

/* Find parent */
int find(int x)
{
    while(parent[x] != x)
        x = parent[x];

    return x;
}

/* Union of two sets */
void unite(int a, int b)
{
    parent[a] = b;
}

int main()
{
    int n, e;
    int i, j;

    int totalCost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("\nEnter edges (u v weight):\n");

    for(i = 0; i < e; i++)
    {
        scanf("%d %d %d",
              &edge[i].u,
              &edge[i].v,
              &edge[i].w);
    }

    /* Initialize parent */
    for(i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    /* Sort edges by weight (Bubble Sort) */
    for(i = 0; i < e - 1; i++)
    {
        for(j = 0; j < e - i - 1; j++)
        {
            if(edge[j].w > edge[j + 1].w)
            {
                temp = edge[j];
                edge[j] = edge[j + 1];
                edge[j + 1] = temp;
            }
        }
    }

    printf("\nEdges in Minimum Spanning Tree:\n");

    /* Kruskal Algorithm */
    for(i = 0; i < e; i++)
    {
        int p1 = find(edge[i].u);
        int p2 = find(edge[i].v);

        /* If no cycle */
        if(p1 != p2)
        {
            printf("%d -- %d  = %d\n",
                   edge[i].u,
                   edge[i].v,
                   edge[i].w);

            totalCost += edge[i].w;

            unite(p1, p2);
        }
    }

    printf("\nTotal Minimum Cost = %d\n", totalCost);

    return 0;
}
