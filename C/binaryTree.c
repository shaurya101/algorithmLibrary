#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int data){
    struct Node *n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

int main(){
    // creating nodes
    struct Node *root = createNode(20);
    struct Node *p1 = createNode(30);
    struct Node *p2 = createNode(40);

    // linking nodes
    root->left = p1;
    root->right = p2;

    return 0;
}
