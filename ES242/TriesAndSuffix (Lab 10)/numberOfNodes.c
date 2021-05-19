#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

#define ALPHABETSIZE 26

int numberOfNodes = 0;

int charIndex(char c){
    return (int)c-97;
}

struct Node{
    struct Node *children[ALPHABETSIZE];
    struct Node *parent;
    bool isend;
    char c;
};

struct Node *newNode(char x){
    struct Node *root = NULL;
    root = (struct Node *)malloc(sizeof(struct Node));
    root->isend = false;
    root->c = x;
    root->parent = NULL;
    
    for (int i = 0; i < ALPHABETSIZE; i++) {
        root->children[i] = NULL;
    }
    
    numberOfNodes++;
    return root;
}

struct Node *insert(struct Node *root, char *word){
    int length = strlen(word);
    
    struct Node *curr = root;
    
    for (int i = 0; i < length; i++) {
        int j = charIndex(word[i]);
        
        if (curr->children[j]) {
            curr = curr->children[j];
        }else {
            struct Node *p = newNode(word[i]);
            curr->children[j] = p;
            p->parent = curr;
            curr = curr->children[j];
        }
    }
    
    curr ->isend = true;
    return root;
}

int main() {
    int n; scanf("%d", &n);
    
    char string[100001];
    
    struct Node *root = newNode('\0');
    
    for (int i = 0; i < n; i++) {
        scanf("%s", string);
        insert(root, string);
    }
    
    printf("%d", numberOfNodes);
    
    return 0;
}