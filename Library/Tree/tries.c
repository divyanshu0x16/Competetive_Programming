#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define ALPHABETSIZE 26
// a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z
int number_of_nodes = 0;

int charindex(char c){
  return (int)c - 97;
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

  for(int i = 0; i < ALPHABETSIZE; i++){
    root->children[i] = NULL;
  }

  number_of_nodes++;

  //root->data = key;
  //root->left = NULL;
  //root->right = NULL;
  return root;
}

struct Node *insert(struct Node *root, char *word){
  // insert bear 
  
  int length = strlen(word);
  // length = 4

  struct Node *curr = root;

  for(int i = 0; i < length; i++){
      // word[0] = 'b', word[1] = 'e', word[2] = 'a', word[3] = 'r'
      
      int j = charindex(word[i]);
      // i = 0 -> j = 2; i = 1 -> 4; i = 2 -> j = 0; i = 3 -> 17
      
      if(curr->children[j]){
        curr = curr->children[j];
        // printf("%c exists already, moving along\n",word[i]);
      }
      else{
        struct Node *p = newNode(word[i]);
        curr->children[j] = p;
        p->parent = curr;
        // printf("%c does not exist, creating a new node \n",word[i]);
        curr = curr->children[j];
      }
  }

  curr->isend = true;
  // printf("\n----\n\n"); 
  return root;

}

bool hasOnechild(struct Node *somenode){
  int no_of_children = 0;
  for(int i = 0; i < ALPHABETSIZE; i++){
    if(somenode->children[i]){
      no_of_children++; 
    }
  }
  if(no_of_children == 1)
    return true;  
  else  
    return false;
}


bool isDeadend(struct Node *somenode){
  for(int i = 0; i < ALPHABETSIZE; i++){
    if(somenode->children[i])
      return false; 
  }
  return true;
}

struct Node *delete(struct Node *root, char *word){

  int length = strlen(word);

  struct Node *curr = root;

  for(int i = 0; i < length; i++){
      // word[0] = 'b', word[1] = 'e', word[2] = 'a', word[3] = 'r'
      
      int j = charindex(word[i]);
      // i = 0 -> j = 2; i = 1 -> 4; i = 2 -> j = 0; i = 3 -> 17
      
      if(curr->children[j]){
        curr = curr->children[j];
      }
      else{
        return root;
        //word does not exist in the trie. don't do anything.
      }
  }

  if(!curr->isend)
    return root; 
    //word does not exist in the trie. don't do anything.

  if(curr->isend){
    if(!isDeadend(curr))
      curr->isend = false;
      // word exists but is a prefix of another word, so just reset the flag
    else{
      
      // word exists and ends at a deadend. so we need to
      // walk up the tree till we find a node that is either not a deadend
      // or is the root, and keep deleting nodes on the way
      // also note that we are not freeing up allocated space in this code
      // and this is not ideal... 

      int d = 1;
      if(curr->parent)
      {
        printf("going to delete node: %c\n",curr->c);
        curr = curr->parent;
        while(hasOnechild(curr)){
          printf("going to delete node: %c\n",curr->c);
          curr->children[charindex(word[length-d])] = NULL;
          number_of_nodes--;
          if(curr->parent)
            curr = curr->parent;
          else
            break;
          d++;
        }
      }

      // exit the while loop implies that
      // curr has at least two children OR is root
      // we need to make sure that the relevant child is deleted
      
      // printf("going to delete node: %c\n",curr->c);
      curr->children[charindex(word[length-d])] = NULL;
      number_of_nodes--;
    }
      
  }

  return root;

}

bool search(struct Node *root, char *word){

  int length = strlen(word);
  // length = 4

  struct Node *curr = root;

  for(int i = 0; i < length; i++){
      // word[0] = 'b', word[1] = 'e', word[2] = 'a', word[3] = 'r'
      
      int j = charindex(word[i]);
      // i = 0 -> j = 2; i = 1 -> 4; i = 2 -> j = 0; i = 3 -> 17
      
      if(curr->children[j]){
        curr = curr->children[j];
        // printf("%c exists already, moving along\n",word[i]);
      }
      else{
        return false;
      }
  }
  if(curr->isend)
    return true;
  else
    return false; 

}

int main(void) {
  
  char words[][32] = {"bear","buy","stock","sell","share","stack","store","bully"};
  // The first dimension is the #words.
  // The second dimension is the maximum length of each word.

  struct Node *root = newNode('\0');

  for(int i = 0; i < 8; i++)
    root = insert(root,words[i]);

  printf("\nCreated a tree with %d nodes.\n\n",number_of_nodes);

  // printf("%d",charindex('r'));

  printf("Searching for bear: %d\n",search(root,"bear"));
  printf("Searching for beer: %d\n",search(root,"beer"));
  printf("Searching for share: %d\n",search(root,"share"));
  printf("Searching for bully: %d\n",search(root,"bully"));
  printf("Searching for bull: %d\n",search(root,"bull"));
  printf("Searching for be: %d\n",search(root,"be"));

  root = delete(root,"share");
  printf("Searching for share: %d\n",search(root,"share"));

  printf("\nThe tree currently has %d nodes.\n\n",number_of_nodes);
  

  return 0;
}