#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
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

int ans = 0;
void dfs(Graph* G, int u, int *visited, int parent, int *colors){
    Node * temp = G->Adj[u];
    if (parent != -1) {
        if(colors[u] != colors[parent]) ans++;
    }
    while (temp != NULL){
        if (visited[temp->value]==0){
            visited[temp->value]=1;
            dfs(G, temp->value, visited, u, colors);
        }
        temp = temp->next;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n; scanf("%d", &n);
    Graph* G = createGraph(n);
    
    int pi;
    //converting to zero based indexing
    for (int i = 1; i < n; i++) {
        
        scanf("%d", &pi);
        addEdge(G, i, pi-1);
    }
    //printGraph(G);
    int visited[n];
    for (int i = 0; i < G->n; i++) {
        visited[i] = 0;
    }
    
    int colors[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &colors[i]);
    }
    
    ans = 0;
    
    dfs(G, 0, visited, -1, colors);
    
    //If all colors are equal, 0 is given output since it based upon difference. but we have to give 1 because one step is always needed
    int color = colors[0];
    bool allequal = 1;
    for (int i = 1; i < n; i++) {
        if(colors[i] != color) allequal = 0;
    }
    
    if (allequal) {
        printf("1\n");
    }else printf("%d\n", ans);

    return 0;
}




