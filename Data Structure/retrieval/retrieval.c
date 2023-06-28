#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define CHARACTERS_IN_ALPHABET 26

typedef struct _NODE{
    struct _NODE* children[CHARACTERS_IN_ALPHABET];
    bool isWord;
}Node;

Node* createNode(void){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) exit(1);

    newNode->isWord = false;

    int i;
    for(i = 0; i < CHARACTERS_IN_ALPHABET; i++){newNode->children[i] = NULL;}
    return newNode;
}

Node* initializeNode(void){
    return createNode();
}

int mapIndex(char c){
    return ((int)c - (int)'a');
}

void addNode(Node** root, char* keyWord){
    int keyWordIndex;
    int wordLength = strlen(keyWord);
    int i;

    Node* currentNode = (*root);
    for(keyWordIndex = 0; keyWordIndex < wordLength; keyWordIndex++){
        i = mapIndex(keyWord[keyWordIndex]); 
        if(currentNode->children[i] == NULL){
            currentNode->children[i] = createNode();
        }
        currentNode = currentNode->children[i];
    }
    currentNode->isWord = true;
}


bool searchNode(Node* root, char* keyWord){
    int keyWordIndex;
    int wordLength = strlen(keyWord);
    int i;
    Node* currentNode = root;

    for(keyWordIndex = 0; keyWordIndex < wordLength; keyWordIndex++){
        i = mapIndex(keyWord[keyWordIndex]);
        if(currentNode->children[i] == NULL) return false;
        currentNode = currentNode->children[i];
    }
    return currentNode->isWord;
}

int main(void){
    return 0;
}