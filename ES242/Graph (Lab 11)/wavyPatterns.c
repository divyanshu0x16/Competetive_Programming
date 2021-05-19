#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

struct QNode { 
    int keyX;
    int keyY; 
    //This variable distance will store the value the cell will contain in matrix
    int distance;
    struct QNode* next; 
}; 

struct Queue { 
    struct QNode *front, *rear;
}; 
   
struct QNode* newNode(int x, int y, int dist) 
{ 
    struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode)); 
    temp->keyX = x;
    temp->keyY = y; 
    temp->distance = dist;
    temp->next = NULL; 
    return temp; 
} 
  
struct Queue* createQueue() 
{ 
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue)); 
    q->front = q->rear = NULL; 
    return q; 
} 
  
void enQueue(struct Queue* q, int x, int y, int dist) 
{ 
    struct QNode* temp = newNode(x, y, dist); 
  
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

int validCoord(int x, int y, int n, int m, int** visited){
    if(x < 0 || y < 0 || x >= n || y >= m || visited[x][y] == 1){
        return 0;
    }
    return 1;
}

void print2d(int** grid, int r, int c){
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++)
            printf("%d ", grid[i][j]);
        printf("\n");
    }
}

int main() {
    int r, c, Ci, Cj; scanf("%d %d %d %d", &r, &c, &Ci, &Cj);

    int **grid;
    {
    grid = malloc(r * sizeof * grid);
    for (int i = 0; i < r; i++)
        grid[i] = malloc(c * sizeof * grid[i]);
    }

    int **visited;
    {
    visited = malloc(r * sizeof * visited);
    for (int i = 0; i < r; i++)
        visited[i] = malloc(c * sizeof * visited[i]);

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            visited[i][j] = 0;
    }

    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    struct Queue *q = createQueue();
    enQueue(q, Ci, Cj, 0);
    visited[Ci][Cj] = 1;
    grid[Ci][Cj] = 0;

    while (q->front != NULL){
        int x = q->front->keyX;
        int y = q->front->keyY;
        int dist = q->front->distance;
        deQueue(q);

        for (int i = 0; i < 8; i++){
            int newX = x+dx[i];
            int newY = y+dy[i];
            if(validCoord(newX, newY, r, c, visited)){
                visited[newX][newY] = 1;
                grid[newX][newY] = dist+1;
                enQueue(q,newX, newY, dist+1);
            }
        }
    }
    print2d(grid, r, c);
    return 0;
}