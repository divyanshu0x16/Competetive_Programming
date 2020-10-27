#include <stdio.h>
#include <stdlib.h>

//We define the node
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

//Function to create the node
struct node* create_node(int data){
    //First we allocate the memory
    struct node* new_node = (struct node*)malloc(sizeof(struct node));

    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

//In-order traversal
void printInorder(struct node* node/*Pointer to the root of the tree)*/ ){
    
    if (node == NULL){
        return;
    }

    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);

}

//Pre-order traversal
void printPreorder(struct node* node/*Pointer to the root of the tree)*/ ){
    
    if (node == NULL){
        return;
    }

    printf("%d ", node->data);
    printPreorder(node->left);
    printPreorder(node->right);
}

//Post-order traversal
void printPostorder(struct node* node/*Pointer to the root of the tree)*/ ){
    
    if (node == NULL){
        return;
    }

    printPostorder(node->left);
    printPostorder(node->right);
    printf("%d ", node->data);
}

int main(void){

    //Create the root with the value one
    struct node* root = create_node(1);
    root->left = create_node(3);
    root->right = create_node(10);

    printf("\nInorder Traversal: \n");
    printInorder(root);

    printf("\nPreorder Traversal: \n");
    printPreorder(root);

    printf("\nPostorder Traversal: \n");
    printPostorder(root);

    return 0;
}