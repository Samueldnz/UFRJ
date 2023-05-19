#include<stdio.h>
#include<stdlib.h>

typedef struct _NODE
{
    int key;
    int suffixsum;
    struct _NODE* next;
}Node;

Node* createNode(int key);
int suffixsum(Node* head);
void insertNode(Node** head, int keyvalue);
void displayList(Node* head);

/*To run this code, use the following command: "./linkedlist.exe < "in.txt" > "out.txt""*/

int main(void)
{
    Node* head = NULL;
    int element = 0;

    while(!feof(stdin)){
        int x;
        if(scanf("%d", &x) == 1){
            insertNode(&head, x);
            element++; /*Not necessary, It`s here just in case I want to use in the future*/
        }
    }

    head->suffixsum = suffixsum(head);

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
    newNode->suffixsum = 0;
    return newNode;
}

/**
 * @brief Calculates the suffix sum of the linked list recursively.
 * 
 * This function computes the suffix sum of the linked list by recursively summing up the key 
 * values of the nodes starting from the current node and updating the suffixsum field of 
 * each node accordingly.
 * 
 * @param head Pointer to the head node of the linked list.
 * @return int The suffix sum of the linked list.
 */
int suffixsum(Node* head)
{
    int total;

    if(head == NULL){
        return 0;
    }

    total = suffixsum(head->next);
    head->suffixsum = head->key + total;

    return head->suffixsum;
}

/**
 * @brief Inserts a new node with the given key value at the beginning of the linked list.
 * 
 * @param head Pointer to the pointer of the head node of the linked list.
 * @param keyvalue The key value of the new node to be inserted.
 */
void insertNode(Node** head, int keyvalue) {
    Node* newNode = createNode(keyvalue);
    if(newNode == NULL) exit(1);
    newNode->next = *head;
    *head = newNode;
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
        printf("SuffixSum: %d -> ", current->suffixsum);  
        current = current->next;  
    }
    printf("NULL\n");  
}


