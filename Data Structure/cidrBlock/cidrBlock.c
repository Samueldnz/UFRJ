#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_MASK_SIZE 32
#define MAX_STRING_SIZE 50
#define CHARACTERS_IN_ALPHABET 2

typedef struct _NODE {
    struct _NODE* children[CHARACTERS_IN_ALPHABET];
    bool isIP;
    char* address;
} Node;


void decimalToBinary(
                    int decimal1, 
                    int decimal2, 
                    int decimal3, 
                    int decimal4, 
                    int *binaryArray);

char* searchTrie(Node* root, int* binaryArray, int mask);
void addNode(Node** root, int* binaryArray, int mask, char* address);
Node* createNode(void);

int main(void){
    int lines, i;
    int decimal1, decimal2, decimal3, decimal4, mask;
    char* address = (char *)malloc(MAX_STRING_SIZE * sizeof(char));
    int IPinBinary[MAX_MASK_SIZE];

    Node* root = createNode();
    scanf("%d", &lines);

    for(i = 0; i < lines; i++){
        scanf("%d.%d.%d.%d/%d %[^\n]%*c", &decimal1, &decimal2, &decimal3, &decimal4, &mask, address);
        decimalToBinary(decimal1, decimal2, decimal3, decimal4, IPinBinary);
        addNode(&root, IPinBinary, mask, address);

    }

    scanf("%d.%d.%d.%d", &decimal1, &decimal2,&decimal3,&decimal4);
    decimalToBinary(decimal1, decimal2, decimal3, decimal4, IPinBinary);
    char* foundAddress1 = searchTrie(root, IPinBinary, MAX_MASK_SIZE);
    printf("%d.%d.%d.%d %s\n", decimal1, decimal2, decimal3, decimal4, foundAddress1);

    scanf("%d.%d.%d.%d", &decimal1, &decimal2,&decimal3,&decimal4);
    decimalToBinary(decimal1, decimal2, decimal3, decimal4, IPinBinary);
    char* foundAddress2 = searchTrie(root, IPinBinary, MAX_MASK_SIZE);
    printf("%d.%d.%d.%d %s\n", decimal1, decimal2, decimal3, decimal4, foundAddress2);

    scanf("%d.%d.%d.%d", &decimal1, &decimal2,&decimal3,&decimal4);
    decimalToBinary(decimal1, decimal2, decimal3, decimal4, IPinBinary);
    char* foundAddress3 = searchTrie(root, IPinBinary, MAX_MASK_SIZE);
    printf("%d.%d.%d.%d %s\n", decimal1, decimal2, decimal3, decimal4, foundAddress3);

    return 0;
}

void decimalToBinary(
                    int decimal1, 
                    int decimal2, 
                    int decimal3, 
                    int decimal4, 
                    int *binaryArray) 
{
    int i;
    for (i = 7; i >= 0; i--) {
        binaryArray[i] = decimal1 & 1;
        decimal1 >>= 1;
    }
    for (i = 15; i >= 8; i--) {
        binaryArray[i] = decimal2 & 1;
        decimal2 >>= 1;
    }
    for (i = 23; i >= 16; i--) {
        binaryArray[i] = decimal3 & 1;
        decimal3 >>= 1;
    }
    for (i = 31; i >= 24; i--) {
        binaryArray[i] = decimal4 & 1;
        decimal4 >>= 1;
    }
}

Node* createNode(void) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) exit(1);

    newNode->isIP = false;
    newNode->address = "N/A";

    int i;
    for (i = 0; i < CHARACTERS_IN_ALPHABET; i++) {
        newNode->children[i] = NULL;
    }
    return newNode;
}

void addNode(Node** root, int* binaryArray, int mask, char* address) {
    Node* currentNode = *root;
    int i;
    for (i = 0; i < mask; i++) {
        int key = binaryArray[i];
        if (currentNode->children[key] == NULL) {
            currentNode->children[key] = createNode();
        }
        currentNode = currentNode->children[key];
    }
    currentNode->isIP = true;
    currentNode->address = (char*)malloc((strlen(address) + 1) * sizeof(char));
    strcpy(currentNode->address, address);
}

char* searchTrie(Node* root, int* binaryArray, int mask) {
    Node* currentNode = root;
    char* lastAddress = NULL;
    int i;
    for (i = 0; i < mask; i++) {
        int key = binaryArray[i];
        if (currentNode->children[key] == NULL) {
            break;
        }
        currentNode = currentNode->children[key];
        if (currentNode->isIP) {
            lastAddress = currentNode->address;
        }
    }
    if (lastAddress == NULL) {
        lastAddress = currentNode->address;
    }
    return lastAddress;
}



