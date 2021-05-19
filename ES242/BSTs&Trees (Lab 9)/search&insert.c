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

struct node* search(struct node* root, int key){
    if (root == NULL || root->key == key)
        return root;
        
    if (root -> key < key) 
        return search(root->right, key);
        
    return search(root->left, key);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t; scanf("%d", &t);
    while (t--) {
        int n, m; 
        scanf("%d", &n); scanf("%d", &m);
        
        int arrayM[m];
        
        int rootVal; scanf("%d", &rootVal); int value;
        struct node* root = NULL;
        root = insert(root, rootVal);
        
        for (int i = 1; i < n; i++) {
            scanf("%d", &value);
            insert(root, value);
        }
        
        for (int i = 0; i < m; i++) {
            scanf("%d", &value);
            if (search(root, value) == NULL) {
                printf("NO\n");
                insert(root,value);
            }else {
                printf("YES\n");  
            }
        }
        


    }
    return 0;
}