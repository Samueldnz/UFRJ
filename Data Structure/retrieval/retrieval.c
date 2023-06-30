#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define CHARACTERS_IN_ALPHABET 26

typedef struct _NODE{
    struct _NODE* children[CHARACTERS_IN_ALPHABET];
    bool isWord;
}Node;

Node* createNode(void);
Node* initializeNode(void);
int mapIndex(char c);
void addNode(Node** root, char* keyWord);
bool searchNode(Node* root, char* keyWord);

int main(int argc, char* argv[]){
    
    if(argc != 2){
        printf("Run the code with the following command: ./retrieval.c input.txt\n");
        return 1;
    }

    Node* root = initializeNode();
    FILE* file;
    char* fileName = argv[1];
    int i;

    int numberOfWordsIntheFile;
    char word[100];

    file = fopen(fileName, "r");
    if(file == NULL){
        printf("ERROR! It was not possible open the file!\n");
        return 1;
    }

    fscanf(file, "%d", &numberOfWordsIntheFile);

    for(i = 0; i < numberOfWordsIntheFile; i++){
        fscanf(file, "%s", word);
        addNode(&root, word);
    }printf("All words were added successfully!\n");

    fclose(file);

    printf("Choose an word to search: \n");
    scanf("%s", word);

    if(searchNode(root, word)){
        printf("encontrei!\n");
    }else{printf("ficarei devendo\n");}
    
    return 0;
}

/**
 * @brief Create a Node object
 * 
 * @return Node* 
 */
Node* createNode(void){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) exit(1);

    newNode->isWord = false;

    int i;
    for(i = 0; i < CHARACTERS_IN_ALPHABET; i++){newNode->children[i] = NULL;}
    return newNode;
}

/**
 * @brief Initialize a Node object
 * 
 * @return Node* 
 */
Node* initializeNode(void){
    return createNode();
}

/**
 * @brief Map a character to an index
 * 
 * @param c The character to map
 * @return int The index mapped to the character
 */
int mapIndex(char c){
    return ((int)c - (int)'a');
}

/**
 * @brief Add a Node to the trie
 * 
 * @param root The root of the trie
 * @param keyWord The word to be added
 */
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

/**
 * @brief Search for a word in the trie
 * 
 * @param root The root of the trie
 * @param keyWord The word to search for
 * @return true if the word is found, false otherwise
 */
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