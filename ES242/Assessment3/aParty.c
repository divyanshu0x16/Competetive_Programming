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

struct QNode { 
    int key; 
    struct QNode* next; 
}; 

struct Queue { 
    struct QNode *front, *rear;
}; 
   
struct QNode* newNode(int k) 
{ 
    struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode)); 
    temp->key = k; 
    temp->next = NULL; 
    return temp; 
} 
  
struct Queue* createQueue() 
{ 
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue)); 
    q->front = q->rear = NULL; 
    return q; 
} 
  
void enQueue(struct Queue* q, int k) 
{ 
    struct QNode* temp = newNode(k); 
  
    if (q->rear == NULL) { 
        q->front = q->rear = temp; 
        return; 
    } 
  
    q->rear->next = temp; 
    q->rear = temp; 
} 
  
void deQueue(struct Queue* q) 
{ 
    if (q->front == NULL) 
        return; 
  
    struct QNode* temp = q->front; 
  
    q->front = q->front->next; 
   
    if (q->front == NULL) 
        q->rear = NULL; 
  
    free(temp); 
} 

void bfs(Graph *G, int u, int *depth){
    struct Queue *q = createQueue();
    enQueue(q,u); //[u]
    int n = G->n;
    int *visited = (int*)malloc(sizeof(int)*n); //array of size n
    //We essentially create an array which will store the depth of each node

    for (int i = 0; i < G->n; i++)
        visited[i] = 0;

    for (int i = 0; i < G->n; i++)
        depth[i] = 0; 
    
    visited[u] = 1; //[1,0,0,0,....]
    while (q->front != NULL){
        int v = q->front->key;
        deQueue(q);
        Node* temp = G->Adj[v];
        while (temp != NULL){
            if (visited[temp->value] != 1 ){
                visited[temp->value] = 1;
                enQueue(q, temp->value);
                depth[temp->value] = depth[v]+1;
            }  
            temp = temp->next; //Move to the next Node in the adjaceny list
        }
    }
    return;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n; scanf("%d\n", &n);
    int pi;
    
    Graph* G = createGraph(n+1);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &pi);
        if(pi == -1) pi++;
        addEdge(G, i, pi);
    }
    
    int depth[n+1];
    for (int i = 0; i < n+1; i++) 
        depth[i] = 0;

    bfs(G, 0, depth);

    int maxDepth = 0;
    for (int i = 0; i < n+1; i++)
        if (maxDepth < depth[i])
            maxDepth = depth[i];

    printf("%d\n", maxDepth);
    
    return 0;
}