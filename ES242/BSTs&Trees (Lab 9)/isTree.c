#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool isCyclic(Graph* G, int u, int *visited, int parent){
    Node * temp = G->Adj[u];
    visited[u] = 1;
    while (temp != NULL) {
        if (visited[temp->value] == 0) {
            if (isCyclic(G, temp->value, visited, u)) {
                return 1; //If a cycles is detected then it should return true
            }
        }else if (temp->value != parent) {
            return 1; //If visited array is not equal to parent then there is a cycle
        }
        temp = temp->next;
    }
    return 0;
}

bool isTree(Graph* G, int *visited){
    //Firstly we have to check for cycles
    if(isCyclic(G, 0, visited, -1)) return 0; // If there is cycle then there cannot be trees
    
    for (int i = 0; i < G->n; i++) {
        if (visited[i] == 0) {
            return 0; //If all nodes are not visited then the graph is not a tree
        }
    }
    return 1;
}

int main(){
    int n, m; scanf("%d %d", &n, &m);
    Graph* G = createGraph(n);
    
    int a, b;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        addEdge(G, a-1, b-1);
    }
    
    int visited[n];
    for (int i=0; i<G->n; i++){
        visited[i] = 0;
    }
    visited[0] = 1;
    if(isTree(G, visited))printf("yes\n");
    else printf("no\n");
    
}