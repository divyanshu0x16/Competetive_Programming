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
    int freq;
    char c;
};


struct Node *newNode(char x){
    struct Node *root = NULL;
    root = (struct Node *)malloc(sizeof(struct Node));
    root->c = x;
    
    for (int i = 0; i < ALPHABETSIZE; i++) {
        root->children[i] = NULL;
    }
    
    numberOfNodes++;
    return root;
}

struct Node* insert(struct Node *root, char *word){
   
    int length = strlen(word);
    struct Node *curr = root;
    
    for (int i = 0; i < length; i++) {
        int j = charIndex(word[i]);
        
        if (curr -> children[j] == NULL) {
            struct Node *p = newNode(word[i]);
            curr -> children[j] = p;   
            p->freq = 0;
        }
        curr->children[j]->freq++;
        curr = curr->children[j];
    }
    return root;
}

int find(char *word, struct Node* root){
    int count = 0;
    struct Node* cur = root;
    
    int length = strlen(word);
    
    for (int i = 0; i < length; i++) {
        int j = charIndex(word[i]);
        
        if (cur->children[j] == NULL) 
            return 0;
        
        cur = cur->children[j];
        
        count++;
        
        if (count == length)
            return cur->freq;
    }
    return 0;
}

int main() {
    int n; scanf("%d", &n);
    
    char operation[5];
    char second[22];
    
    int answer;
    
    struct Node *root = newNode('\0');
    
    for (int i = 0; i < n; i++) {
        scanf("%s %s", operation, second);
        if (operation[0] == 'a') {
            
            insert(root, second);
        }else {
            answer = find(second, root);
            printf("%d\n", answer);
        }
    }
    return 0;
}

