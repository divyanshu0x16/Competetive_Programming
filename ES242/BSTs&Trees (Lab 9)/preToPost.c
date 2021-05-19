#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

struct node{
    int key;
    struct node *left, *right;
};

struct node* newNode(int item){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    
    temp->key=item;
    temp->left = temp-> right = NULL;
    return temp;    
}

struct node* insert(struct node* node, int key){
    if (node == NULL) {
        return newNode(key);
    }
    
    if (key < node->key) {
        node-> left = insert(node->left, key);
    }else if (key > node ->key) {
        node->right = insert(node->right, key);
    }
    
    return node;
}

void postorder(struct node* root){
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->key);
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n; scanf("%d", &n);
    int value;
         
    int rootVal; scanf("%d", &rootVal);
    struct node* root = NULL;
    root = insert(root, rootVal);
         
    for (int i=1; i < n; i++) {
        scanf("%d", &value);
        insert(root, value);
    }
    
    postorder(root);
    
    return 0;
}