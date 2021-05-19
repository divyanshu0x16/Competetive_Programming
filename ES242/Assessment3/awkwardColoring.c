#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

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

int main(){
    int n, m; scanf("%d %d", &n, &m);
    Graph* G = createGraph(n);
    
    int ui, vi;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &ui, &vi);
        addEdge(G, ui-1, vi-1);    
    }
    
    int *type = (int*)malloc(sizeof(int)*n); //array of size n
    for (int i = 0; i < G->n; i++){
        type[i] = -1;
    }
    
    struct Queue *q = createQueue();
    enQueue(q, 0);
    
    int *visited = (int*)malloc(sizeof(int)*n); //array of size n
    for (int i = 0; i < G->n; i++){
        visited[i] = 0;
    }
    visited[0] = 1;
    
    type[0] = 0;
    bool flag = 1;
    while (q->front != NULL) {
        int v = q->front->key;
        deQueue(q);
        Node* temp = G->Adj[v];
        while (temp != NULL){
            if (visited[temp->value] != 1 ){
                visited[temp->value] = 1;
                
                //If the previous vertex was of type 0, the current vertex would be of type 1 and vice-versa
                if(type[v] == 0) type[temp->value] = 1;
                else type[temp->value] = 0; 
                enQueue(q, temp->value);
            }  //If at any point both become equal then we cannot fill odd and different values in other parts.
            
            if (type[temp->value] == type[v]) {
                flag = 0;
            }
            temp = temp->next;
        }
    }
    
    
    /*for (int i = 0; i < n; i++) {
        printf("%d ", type[i]);
    }*/
    
    int typeZero = 0, typeOne = 0;
    for (int i = 0; i < n; i++) {
        if(type[i] == 0) typeZero++;
    }
    typeOne = n-typeZero;
    /* Two types. Fill one with (1,3) and other with 2. So 2^size options. Then we swtich the sides,
    so similarly we have 2^size1 for other side two. Total is 2^size+2^size1
    */
    int ans = pow(2, typeOne)+pow(2, typeZero);
    if(flag == 0) printf("0\n");
    else printf("%d\n", ans);
    
    
}

