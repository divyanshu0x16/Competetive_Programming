#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INT_MAX +2147483647

typedef struct Graph
{
    int n;     //nodes
    int m;     //edges
    int **Adj; //an array of pointers
} Graph;

Graph *createGraph(int n)
{
    Graph *G = (Graph *)malloc(sizeof(Graph));
    G->n = n;
    //Initially number of edges is 0
    G->m = 0;
    G->Adj = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        G->Adj[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
        {
            G->Adj[i][j] = 0;
        }
    }
    return G;
}

void addEdge(Graph *G, int u, int v, int weight)
{
    G->Adj[u][v] = weight;
    G->Adj[v][u] = weight;
    G->m++;
}

void printGraph(Graph *G)
{
    //Printing a matrix
    for (int i = 0; i < G->n; i++)
    {
        for (int j = 0; j < G->n; j++)
        {
            printf("%4d", G->Adj[i][j]);
        }
        printf("\n");
    }
}

//Similar to dijkstra
int minDistance(Graph *G, int *dist, bool *sptSet)
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < G->n; v++)
        if (sptSet[v] == 0 && dist[v] < min)
            min = dist[v], min_index = v;

    return min_index;
}

void prims(Graph *G)
{
    //array to store constructed MST
    int parent[G->n];
    int key[G->n];     //valuse used to pick minimum weight edge in cut
    bool mstSet[G->n]; //Check weather an edge is included in mst or not

    for (int i = 0; i < G->n; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;     //first node is the root
    parent[0] = -1; //similar to cats and restaurant

    //We do not check for the last node
    for (int i = 0; i < (G->n) - 1; i++)
    {
        int u = minDistance(G, key, mstSet); //Pick the minimum set of vertices not yet includes

        mstSet[u] = 1;

        for (int j = 0; j < G->n; j++)
        {
            if (G->Adj[u][j] != 0 && mstSet[j] == false && G->Adj[u][j] < key[j])
            {
                parent[j] = u;
                key[j] = G->Adj[u][j];
            }
        }
    }

    printf("Edge \tWeight\n");
    for (int i = 1; i < G->n; i++)
        printf("%d - %d \t%d \n", parent[i], i, G->Adj[i][parent[i]]);
}

int main()
{
    int vertices;
    scanf("%d", &vertices);
    Graph *G = createGraph(vertices);

    int u, v, w, edges;
    scanf("%d ", &edges);
    for (int i = 0; i < edges; i++)
    {
        scanf("%d %d %d", &u, &v, &w);
        addEdge(G, u, v, w);
    }

    prims(G);
}
