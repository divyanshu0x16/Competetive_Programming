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

int non_of_Paths;
void dfs(Graph* G,int u, int *visited, int *isleaf, int *parent){

    int size = 0;
    Node * temp = G->Adj[u];
    while (temp != NULL){
        size++;
        temp = temp->next;
    }
    if(size == 1) isleaf[u] = 1;

    temp = G->Adj[u];
    if (size == 1 && visited[temp->value] == 1)
        non_of_Paths++;
    
    while (temp != NULL){
        if (visited[temp->value]==0){
            visited[temp->value]=1;
            parent[temp->value] = u;
            dfs(G, temp->value, visited, isleaf, parent);
        }
        temp = temp->next;
    }
}
//WE construct an array of parents
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, m; scanf("%d %d", &n, &m);
    int containsCat[n];

    Graph* G = createGraph(n);

    for (int i = 0; i < n; i++) 
        scanf("%d", &containsCat[i]);

    for (int i = 0; i < n-1; i++){
        int x, y; scanf("%d %d", &x, &y);
        addEdge(G, x-1, y-1);
    }
    
    int visited[n];
    for (int i=0; i<G->n; i++)
        visited[i] = 0;
    visited[0] = 1;

    int isleaf[n];
    for (int i = 0; i<G->n; i++)
        isleaf[i] = 0;
    
    int parent[n];
    for (int i = 0; i<G->n; i++)
        parent[i] = -1;
    
    dfs(G, 0, visited, isleaf, parent);

    int temp;
    for (int i = 0; i < n; i++){
        int consecutive = 0;

        temp = i;
        if(isleaf[i] == 1){
            while (parent[i] != -1){
                if( containsCat[i] == 1 ){
                    consecutive++;
                    if(consecutive > m){
                        non_of_Paths--;
                        continue;
                    }
                }else consecutive = 0;
                i = parent[i];
            } 
            if (containsCat[0] == 1){
                consecutive++;
                if (consecutive > m)
                    non_of_Paths--;
            }
        }
        i = temp;
    }
    

    printf("%d\n", non_of_Paths);
    return 0;
}
