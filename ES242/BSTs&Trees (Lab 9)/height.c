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

void inorder(struct node* root){
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

int maxDepth(struct node* node){
    if (node == NULL) {
        return 0;
    }else {
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);
        
        if (lDepth > rDepth) {
            return  lDepth+1;
        }else {
            return rDepth+1;
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        int value;
         
        int rootVal; scanf("%d", &rootVal);
        struct node* root = NULL;
        root = insert(root, rootVal);
         
        for (int i=1; i < n; i++) {
            scanf("%d", &value);
            insert(root, value);
        }
        
        //inorder(root);
        printf("%d\n", maxDepth(root));
        
    }
    return 0;
}