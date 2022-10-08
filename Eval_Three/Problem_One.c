/*
Ashvin Ganesan
Charlie McGuffey
CSCI 221
Friday October 7th 2022
Evaluation Three
*/

//Problem 1
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


struct Node {
    struct Node *left;
    struct Node *right;
    uint32_t val;
};

typedef struct Node Node;

struct BST  {
    struct Node *root;
    int size;
};
typedef struct BST BST;

Node* newNode(int value) {
    Node *n = (Node *)(malloc(sizeof(struct Node)));
    n->val = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}

BST* newBST() {
    BST* bst;
    bst = (BST*)malloc(sizeof(struct BST));
    bst->root = NULL;
    bst->size = 0;
    return bst;
}

Node* addrec(struct Node *root, struct Node *n) {
    
    if(root == NULL) {
        return n;
    }
    if(root->val > n->val) {
        root->left = addrec(root->left, n);
        return root;
    }
    else if(root->val < n->val) {
        root->right = addrec(root->right, n);
        return root;
    }

    else {
        printf("SOMETHING WENT VERY WRONG");
        return root;
    }
        
    
}


void add(BST* bst, int n) {
    Node* node = newNode(n);
    bst->size = (bst->size + 1);
    if(bst->root == NULL) {
        bst->root = node;
        return;
    }
    addrec(bst->root, node);
}

BST* createBSTFromArr(int arr[], int size) {
    BST* bst = newBST();
    for(int i = 0; i < size; i++) {
        add(bst, arr[i]);
    }
    return bst;
}


Node* Max(Node *root) {
    if(root == NULL) {
        return NULL;
    } else if(root->right != NULL) {
        return Max(root->right); 
    }
    return root;
}

Node* delete(Node* root, int v) {
    Node *temp = NULL;
    if(root == NULL) {
        return NULL;
    }
    else if(root->val > v) {
        root->left = delete(root->left, v);
    }
    else if(root-> val < v) {
        root->right = delete(root->right, v);
    }
    else {
        if((root->left == NULL) && (root->right == NULL)) {
            free(root);
            return temp;
        }
        else if(root->left == NULL){
            temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL) {
            temp = root->left;
            free(root);
            return temp;
        }
        else {
            temp = Max(root->left);
            root->val = temp-> val;
            root->left = delete(root->left, temp->val);
        }
    }
    return temp;
    // while(1 == 1) {
    //     if(current == NULL) {
    //         return;
    //     }
    //     else if(current->val > v) {
    //         current = current->left;
    //     }
    //     else if(current->val < v) {
    //         current = current->right;
    //     }
    //     else if(current->val == v){
    //         bst->size = bst->size -1;
    //         fix(current);
    //         return;
    //     }
    //     else {
    //         return;
    //     }
        
    // }
}
void deleteValFromBST(BST* bst, int v) {
    bst->size = bst->size -1;
    Node* root = bst->root;
    delete(root, v);
}


void freeNodes(Node* n) {
    if(n->left != NULL) {
        freeNodes(n->left);
    }
    if(n->right != NULL) {
        freeNodes(n->right);
    }
    free(n);
    return;
}

void freeTree(BST* bst) {
    if(bst->root == NULL) {
        return;
    }
    freeNodes(bst->root);
    bst->root = NULL;
    bst->size = 0;
    free(bst);
}


int main(int argc, char *argv[]) {
    int arr[3] = {2,1,3};
    BST* bst = createBSTFromArr(arr, 3);
    printf("Size:%d\n",bst->size);
    printf("First child:%d\n",bst->root->val);
    printf("Left child:%d\n",bst->root->left->val);
    printf("Right child:%d\n",bst->root->right->val);
    deleteValFromBST(bst, 2);
    printf("Size:%d\n",bst->size);
    printf("First child:%d\n",bst->root->val);
    //printf("Left child:%d\n",bst->root->left->val);
    printf("Right child:%d\n",bst->root->right->val);
    freeTree(bst);
    return 0;
}
