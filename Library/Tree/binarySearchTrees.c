#include <stdio.h>
#include <stdlib.h>

//Binary Search Trees

struct  node{
    int data;
    struct node *right_child;
    struct node *left_child;
};

struct node* new_node(int x){
    struct node *p;
    p = malloc(sizeof(struct node));

    p -> data = x;
    p -> left_child = NULL;
    p -> right_child = NULL;

    return p;
}

//Returning node because we want to find the leaf to insert into
struct node* insert(int x, struct node *root){
    if (root == NULL)
        return new_node(x);
    else if (x > root->data)
        root->right_child = insert(x, root -> right_child);
    else if (x < root->data)
        root->left_child = insert(x, root->left_child);
    return root;
}

void inOrder(struct node *root){
    if (root != NULL)
    {
        inOrder(root->left_child);
        printf("%d\t", root->data);
        inOrder(root->right_child);
    } 
}

//Keep going left, till there is no more left 
int find_min(struct node *root){
    if (root == NULL)
        return -1;
    else if( root -> left_child != NULL)
        return find_min(root -> left_child);
    return root -> data;
}

struct node* delete(int x, struct node *root){
    if (root == NULL)
        return NULL;
    else if (x < root -> data)
        root -> left_child = delete(x, root -> left_child);
    else if (x > root -> data)
        root -> right_child = delete(x, root -> right_child);
    else
    {
        if (root -> left_child == NULL && root -> right_child == NULL){
            //Node to be deleted is a leaf
            free(root);
            return NULL;
        }else if (root -> left_child == NULL || root -> right_child == NULL)
        {
            struct node *tmp;
            //Node to be deleted has a left child or a right child but not both.
            if (root -> left_child == NULL) //no elft child; parent should pint to right child
                tmp = root -> right_child;
            else//no right subtree; parent should point to the right child
                tmp = root -> left_child;
            free(root);
            return tmp;
        }else
        {
            //Node to be deleted has both a left child and a right child
            int tmp = find_min(root -> right_child);
            root -> data = tmp;
            root -> right_child = delete(tmp, root -> right_child);
        }  
    }
    return root;
}

int main(void){

    struct node *root;
    root = new_node(50);

    insert(40, root);
    insert(60, root);
    insert(100, root);
    insert(25, root);
    insert(42, root);
    insert(95, root);

    inOrder(root);
    printf("\nMin: %d", find_min(root));

    delete(60, root);
    printf("\n");
    inOrder(root);
    printf("\n");

    return 0;
}