#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node{
    int valueKey;
    struct Node* rightSubTree;
    struct Node* leftSubTree;
}Node;

void addNode(Node** root, int key);
Node* createNode(int key);
void printInOrder(Node* root);
bool searchNode(Node* root, int keyToSearch);
bool deleteNode(Node** root, int keyToDelete);
Node* findMinimumValueNode(Node* root);

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

    if(searchNode(root, 4) == true){
        printf("encontrado\n");
    }else{
        printf("não existe\n");
    }

    if(deleteNode(&root, 3) == true){
        printf("encontrado\n");
    }else{
        printf("não existe\n");
    }
    
    printInOrder(root);

    return 0;
}

bool deleteNode(Node** root, int keyToDelete){
    if((*root) == NULL) return false;

    if(keyToDelete < (*root)->valueKey){
        return deleteNode(&((*root)->leftSubTree), keyToDelete);
    }else if(keyToDelete > (*root)->valueKey){
        return deleteNode(&((*root)->rightSubTree), keyToDelete);
    }
    else{ /*It`s equal*/
        if((*root)->leftSubTree == NULL){
            Node* temp = (*root);
            (*root) = (*root)->rightSubTree;
            free(temp);
        }
        else if((*root)->rightSubTree == NULL){
            Node* temp = (*root);
            (*root) = (*root)->leftSubTree;
            free(temp);
        }
        else{
            Node* temp = findMinimumValueNode((*root)->rightSubTree); 
            (*root)->valueKey = temp->valueKey;
            deleteNode(&((*root)->rightSubTree), keyToDelete);
        }

        return true;
    }
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

bool searchNode(Node* root, int keyToSearch){
    if(root == NULL) return false;
    if(root->valueKey == keyToSearch ) return true;

    if(keyToSearch < root->valueKey){
        return searchNode(root->leftSubTree, keyToSearch);
    }else{
        return searchNode(root->rightSubTree, keyToSearch);
    }

    return false;
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

Node* findMinimumValueNode(Node* root){
    if(root == NULL) return NULL;

    while(root->leftSubTree != NULL){
        root = root->leftSubTree;
    }
    return root;
}