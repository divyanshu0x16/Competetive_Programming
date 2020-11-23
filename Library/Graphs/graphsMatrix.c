#include <stdio.h>
#include<stdlib.h>

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

void addEdge(Graph* G, int u, int v){
    G->Adj[u][v] = 1;
    G->Adj[v][u] = 1;
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

int main(){
    Graph* G = createGraph(3);
    addEdge(G,0,1);
    addEdge(G,0,2);
    // addEdge(G,1,2);
    printGraph(G);
}