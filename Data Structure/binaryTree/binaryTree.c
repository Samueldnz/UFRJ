#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int valueKey;
    struct Node* rightSubTree;
    struct Node* leftSubTree;
}Node;

void addNode(Node** root, int key);
Node* createNode(int key);
void printInOrder(Node* root);

int main(void)
{
    int keyAmount, treeHeight, i, key;
    Node* root = NULL;

    scanf("%d %d", &keyAmount, &treeHeight);

    for(i = 0; i < keyAmount; i++){
        scanf("%d", &key);
        addNode(&root, key);
    }

    printInOrder(root);
    
    return 0;
}

void addNode(Node** root, int key){
    if((*root) == NULL){
        (*root) = createNode(key);
    }else{
        if(key <= (*root)->valueKey){
            addNode(&((*root)->leftSubTree), key);
        }else{
            addNode(&((*root)->rightSubTree), key);
        }
    }
}

Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) exit(1);

    newNode->valueKey = key;
    newNode->leftSubTree = NULL;
    newNode->rightSubTree = NULL;

    return newNode;
}

void printInOrder(Node* root){
    if (root != NULL) {
        printInOrder(root->leftSubTree);
        printf("%d ", root->valueKey);
        printInOrder(root->rightSubTree);
    }
}
