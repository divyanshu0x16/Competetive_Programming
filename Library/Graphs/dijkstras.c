#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INT_MAX +2147483647
typedef struct Graph{
    int n; //nodes
    int m; //edges
    int** Adj; //an array of pointers
} Graph;

Graph* createGraph(int n){
    Graph* G = (Graph *)malloc(sizeof(Graph));
    G->n = n;
    //Initially number of edges is 0
    G->m = 0;
    G->Adj = (int **)malloc(n*sizeof(int *));
    for (int i=0; i<n; i++){
        G->Adj[i] = (int*)malloc(n*sizeof(int));
        for (int j=0; j<n; j++){
            G->Adj[i][j] = 0;
        }
    }
    return G;
}

void addEdge(Graph* G, int u, int v, int weight){
    G->Adj[u][v] = weight;
    G->Adj[v][u] = weight;
    G->m ++;
}

void printGraph(Graph*G){
    //Printing a matrix
    for (int i=0; i<G->n; i++){
        for (int j=0; j< G->n; j++){
            printf("%4d",G->Adj[i][j]);
        }
        printf("\n");
    }
}

int minDistance(Graph* G, int *dist, bool *sptSet) 
{ 
    int min = INT_MAX, min_index; 
  
    for (int v = 0; v < G-> n; v++) 
        if (sptSet[v] == 0 && dist[v] <= min) 
            min = dist[v], min_index = v; 
  
    return min_index; 
}

void dikstra(Graph* G, int src){
    int minDist[G->n];
    bool set[G->n]; 

    for (int i = 0; i < G->n; i++)
    {
        minDist[i] = INT_MAX;
        set[i]=0;
    }
    
    minDist[src] = 0;

    for (int i = 0; i < (G->n)-1; i++)
    {
        //We pick the minimum distance vertex from the set of vertices not yet counted
        int u = minDistance(G, minDist, set);

        set[u] = 1;

        for (int v = 0; v < G->n; v++)
            if (!set[v] && G->Adj[u][v] && minDist[u] != INT_MAX  && minDist[u]+G->Adj[u][v] < minDist[v])
            minDist[v] = minDist[u]+G->Adj[u][v];
        
    }
    for (int i = 0; i < G->n; i++)
        printf("%d \t\t  %d\n", i, minDist[i]);
      
}

int main(){
    int vertices; scanf("%d", &vertices);
    Graph* G = createGraph(vertices);
    
    int u, v, w, edges; scanf("%d ", &edges);
    for (int i = 0; i < edges; i++)
    {
        scanf("%d %d %d", &u, &v, &w);
        addEdge(G, u, v, w);
    }
    
    dikstra(G, 0);

    //printGraph(G);
}