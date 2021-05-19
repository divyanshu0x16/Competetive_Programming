#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

void print2d(char **grid, int  r, int c){
    for (int i = 0; i < r; i++) {
        for (int j = 0 ; j < c; j++)
            printf("%c", grid[i][j]);
        printf("\n");
        
    }
}

bool validCoor(int x, int y, int n, int m, char **grid){
    if ((0 <= x) && (x <= n-1) && (0 <= y) && (y <= m-1) && (grid[x][y] == 'R')){
        return 1;
    }
    return 0;
}

void dfs(char colorValue,int i, int j, int n, int m,char **grid, char **answer){
  
    int initalX = i, initalY = j;
    //First go north
    while (j >= 0) {
        if (validCoor(i, j, n, m, grid)) 
            answer[i][j] = colorValue;
        j--;
    }
    i = initalX, j = initalY;
    //Go east
    while (i >= 0) {
        if (validCoor(i, j, n, m, grid)) 
            answer[i][j] = colorValue;
        i--;
    }
    i = initalX, j = initalY;
    //Go west
    while (i < n) {
        if (validCoor(i, j, n, m, grid)) 
            answer[i][j] = colorValue;
        i++;
    }
    i = initalX, j = initalY;
    //Go south
    while (j < m) {
        if (validCoor(i, j, n, m, grid)) 
            answer[i][j] = colorValue;
        j++;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, m; scanf("%d %d\n", &n, &m);
    
    char **grid;
    {
        grid = malloc(n* sizeof * grid);
        for (int i = 0; i < n ; i++) 
            grid[i] = malloc(m*sizeof*grid[i]);
        
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < m; j++) 
                scanf("%c", &grid[i][j]);
            if (i < n-1)
                scanf("\n");
        }
    }
    char **answer;
    {
        answer = malloc(n* sizeof * answer);
        for (int i = 0; i < n ; i++) 
            answer[i] = malloc(m*sizeof*answer[i]);
            
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) 
                answer[i][j] = '0';   
    }
    
    int colorValue = 0;
    char colorToPass;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (validCoor(i, j, n, m, grid)) {
                if (answer[i][j] == '0'){
                    colorValue++;
                    colorToPass = colorValue+'0';
                }else {
                    colorToPass = answer[i][j];
                }
                dfs(colorToPass, i, j, n, m, grid, answer);
            }else
                answer[i][j] = '.';
        }
    }
    
    printf("%d\n", colorValue);
    
    
    return 0;
}