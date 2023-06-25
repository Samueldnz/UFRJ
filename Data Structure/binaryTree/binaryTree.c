#include<stdio.h>
#include<stdlib.h>

typedef struct _NODE{
    int valueKey;
    struct _Node* rightSubTree;
    struct _Node* leftSubTree;
}Node;

int main(void)
{
    int keyAmount, treeHeight, i, key;
    Node binaryTree;

    scanf("%d %d", keyAmount, treeHeight);

    for(i = 0; i < keyAmount; i++){
        scanf("%d", key);
        addNode(key, binaryTree);
    }
    
    return 0;
}