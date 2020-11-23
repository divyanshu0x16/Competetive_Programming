#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node* next;
} Node;

typedef struct Graph{
    int n; 
    int m;
    Node** Adj; //List of links
} Graph;

Graph* createGraph(int n){
    Graph* G = (Graph *)malloc(sizeof(Graph));
    G->n = n;
    //Initially number of edges is 0
    G->m = 0;
    G->Adj = (Node **)malloc(n*sizeof(Node *));
    for (int i=0; i<n; i++){
        G->Adj[i] = NULL; // initially there are no edges
    }
    return G;
}

void addEdge(Graph* G, int u, int v){
    Node* temp1 = (Node *)malloc(sizeof(Node));
    temp1 -> value = v; // G - > Adh[u] -> [1,] -> [3,]
    temp1 -> next = G -> Adj[u]; //make it point to the start node of u; 
    //Suppose our new value is 2. So, [2,] -> [1,] ->[3,]. But our G->Adj[u] is still pointing
    // to [1,]. So we need to reassign it G -> Adj[u] -> [2,] -> [1,] ->[3,]
    G -> Adj[u] = temp1;
    G->m ++;

    //Similarly we do that for other vertex
    Node* temp2 = (Node *)malloc(sizeof(Node));
    temp2 -> value = u;
    temp2 -> next = G -> Adj[v]; //make it point to the start node of u;
    G -> Adj[v] = temp2;
    G->m ++;
}

void printGraph(Graph*G){
    for (int i=0; i<G->n; i++){
        printf("%d", i);
        Node * temp = G ->Adj[i];
        while (temp != NULL){
            printf(" -> %d", temp->value);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main(){
    Graph* G = createGraph(3);
    addEdge(G,0,1);
    //addEdge(G,0,2);
    addEdge(G,1,2);
    printGraph(G);
}