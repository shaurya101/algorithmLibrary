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

void preOrder(struct Node* root){
    if(root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct Node *root){
    if(root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

void inOrder(struct Node* root){
    if(root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int isBST(struct Node *root){
    struct Node *prev = NULL;
    if(root != NULL){
        if(!isBST(root->left))
            return 0;
        if(prev != NULL && root->data <= prev->data)  // prev will not be there for first run and if it is there we will compare prev' data to root's data
            return 0;
        prev = root;  // prev will be set before going into right tree the first time. In a subtree, prev will be the root of that subtree. This subtree's root could further be the left or right node of parent subtree. So prev will also travel in inorder way one step behind root.
        return isBST(root->right); // the subtree will finish and this result will be redirected to parent's root left or right subtree call. 
    }
    return 1;  // if no tree then we consider it as BST
}

struct Node* search(struct Node *root, int key){  // in BST we can search in binary fashion
    if(root == NULL)
    return NULL;
    if(key == root->data)
    return root;
    if(key < root->data)
    return search(root->left, key);
    else 
    return search(root->right, key);
}// recursive search

/*
iterative search

struct Node* search(struct Node *root, int key){  // in BST we can search in binary fashion
    while(root != NULL){
        if(key == root->data)
            return root;
        if(key < root->data)
            root = root->left;
        else 
            root = root->right;
    }
    return NULL;
}
*/

void insertBST(struct Node *root, int key){
    struct Node *prev = NULL;
    while(root != NULL){
        prev = root;
        if(root->data == key)
        return;
        if(key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    struct Node *ptr = createNode(key); // create node
    if(key < prev->data)
        prev->left = ptr;
    else
        prev->right = ptr;
}

struct Node* findMIN(struct Node* root){
    while(root->left != NULL)
        root = root->left;
    return root;
}
struct Node* delete(struct Node *root, int key){
    if(root == NULL)
        return NULL;
    if(key < root->data)
        root->left = delete(root->left, key);
    else if(key > root->data)
        root->right = delete(root->right, key);
    else // we found the node
    {
        // case 1 : No child ie leaf node
        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        // case 2 : 1 child, left or right
        else if(root->left == NULL) // no left child
        {
            struct Node *temp = root;
            free(root);
            return temp->right;
        }
        else if(root->right == NULL) //no right child
        {
            struct Node *temp = root;
            free(root);
            return temp->left;
        }
        // case 3 : both children present
        else
        {
            struct Node *temp = findMin(root->right); // we take min of right subtree or max of left subtree and put it's data in root's place.
            root->data = temp->data;
            delete(root->right, temp->data);
            return root;
        }
    }
}


int main(){
    struct Node* root = createNode(4);
    struct Node* p1 = createNode(1);
    struct Node* p2 = createNode(6);
    struct Node* p3 = createNode(5);
    struct Node* p4 = createNode(2);

    // linking
    root->left = p1;
    root->right = p2;
    p1->left = p3;
    p1->right = p4;

    /*

    Tree looks like - 
                4
               / \
              1   6
             / \
            5   2
    */

    preOrder(root);
    printf("\n");
    postOrder(root);
    printf("\n");
    inOrder(root);
    printf("\n");

   return 0;

}
