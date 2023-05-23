#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct _NODE
{
    int key;
    int suffixsum;
    struct _NODE* next;
    struct _NODE* previous;
}Node;

Node* createNode(int key);
void addNode(Node** head, int keyvalue);
void displayList(Node* head);

int main(void)
{
    Node* head = NULL;
    int element = 0;

    while(!feof(stdin)){
        int x;
        if(scanf("%d", &x) == 1){
            addNode(&head, x);
            element++; /*Not necessary, It`s here just in case I want to use in the future*/
        }
    }

    displayList(head);

    return 0;
}

/**
 * @brief Creates a new Node object with the given key value.
 * 
 * @param key The key value for the new Node.
 * @return Node* Pointer to the newly created Node.
 */
Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) exit(1);

    newNode->key = key;
    newNode->next = NULL;
    newNode->previous = NULL;
    return newNode;
}

/**
 * @brief Adds a node in an ordered way to a double linked list based on the node keys.
 *
 * @param head A pointer to the head node of the linked list.
 * @param keyvalue The key value of the node to be added.
 */
void addNode(Node** head, int keyvalue) {
    Node* newNode = createNode(keyvalue);
    if(newNode == NULL) exit(1);

    if((*head) == NULL){
        (*head) = newNode;

    }else if (keyvalue < (*head)->key)
    {
        newNode->next = (*head);
        (*head)->previous = newNode;
        (*head) = newNode;
    }else{
        Node* currentNode = (*head);

        while(currentNode->next != NULL && keyvalue > currentNode->next->key){
            currentNode = currentNode->next;
        }

        newNode->previous = currentNode;
        newNode->next = currentNode->next;
        
        if (currentNode->next != NULL) {
            currentNode->next->previous = newNode;
        }
        
        currentNode->next = newNode;
    }
}

/**
 * @brief Searches for a node with the specified key value in a linked list.
 *
 * @param head The head node of the linked list.
 * @param keyvalue The key value to search for.
 * @return Returns a pointer to the node if found; otherwise, returns NULL.
 */
Node* searchNode(Node* head, int keyvalue){
    Node* currentNode = head;

    while(currentNode != NULL){
        if(currentNode->key == keyvalue){
            return currentNode;
        }
        currentNode = currentNode->next;
    }

    return NULL;
}


/**
 * @brief Deletes a node with the specified key value from a linked list.
 *
 * @param head A pointer to the head node of the linked list.
 * @param keyvalue The key value of the node to be deleted.
 * @return true if the node is found and deleted successfully; false if the node is not found.
 */
bool deleteNode(Node** head, int keyvalue){
    Node* currentNode = (*head);

    while(currentNode != NULL){
        if(currentNode->key == keyvalue){
            if(currentNode->previous == NULL){
                (*head) = currentNode->next;
            }
            else{
                currentNode->previous->next = currentNode->next;
            }
            free(currentNode);
            return true; /*Node found and deleted successfully*/
        }
        currentNode = currentNode->next;
    }
    return false; /*Node not found*/
}

/**
 * @brief Displays the linked list by printing the key value and suffix sum of each node.
 * 
 * @param head Pointer to the head node of the linked list.
 */
void displayList(Node* head) {

    Node* current = head;
    while (current != NULL) {
        printf("Key: %d ", current->key);  
        current = current->next;  
    }
    printf("NULL\n");  
}

