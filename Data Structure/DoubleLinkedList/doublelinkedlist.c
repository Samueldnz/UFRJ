#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct _NODE
{
    int key;
    int suffixsum;
    bool isSuffixSumPerformed;
    struct _NODE* next;
    struct _NODE* previous;
}Node;

Node* createNode(int key);
void addNode(Node** head, int keyvalue);
void displayList(Node* head);
bool deleteNode(Node** head, int keyvalue);
Node* searchNode(Node* head, int keyvalue);
int main_menu(void);
void input_flush();
int get_int(int min, int max, char * prompt);
void displayNode(Node* nodeFound);
int suffixsum(Node* head);

/*FIRST MAIN
int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Use: ./program <file>\n");
        return 1;
    }

    Node* head = NULL;
    int x = 0;
    system("clear");
    FILE *inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        printf("It wasn`t possible to open the file.\n");
        return 1;
    }
    
    while (fscanf(inputFile, "%d", &x) == 1) {
        addNode(&head, x);
    } printf("All the numbers was added successfully!\n");
    
    fclose(inputFile);

    while(1){
        
        switch (main_menu())
        {
        case 1:
            printf("Enter with the new Node key to add: ");
            scanf("%d", &x);
            getchar();
            addNode(&head, x);
            printf("The new Node was added successfully!\n");
            break;
        
        case 2:
            printf("Enter with the Node key to delete: ");
            scanf("%d", &x);
            getchar();
            if(deleteNode(&head, x)){
                printf("The Node was deleted successfully!\n");
            }else{
                printf("A Node with this key doesn`t exist!\n");
            }
            break;
        
        case 3:
            printf("Enter with the Node key to search: ");
            scanf("%d", &x);
            getchar();
            Node* found = searchNode(head, x);
            if(found == NULL){
                printf("A Node with this key doesn`t exist!\n");
            }else{
                if(head->isSuffixSumPerformed){
                    head->suffixsum = suffixsum(head);
                }
                displayNode(found);
            }
            break;
        
        case 4:
            printf("Double Linked List\n\n");
            displayList(head);
            break;
        
        case 5:
            head->suffixsum = suffixsum(head);
            printf("Suffix sum performed successfully\n");
            break;

        case 6:
            return 0;
        }
        printf("\nClick 'ENTER' to back to menu!\n");
        input_flush();
        system("clear");
    }
}*/

/* SECOND MAIN*/
int main(void) {
    Node* head = NULL;
    int x;
    system("clear");
    while (!feof(stdin)) {
        if (scanf("%d", &x) == 1) {
            addNode(&head, x);
        }
    }printf("\nAll the numbers were added successfully!\n");

    freopen("/dev/tty", "r", stdin); 

    while (1) {
        switch (main_menu())
        {
        case 1:
            printf("Enter with the new Node key to add: ");
            scanf("%d", &x);
            getchar();
            addNode(&head, x);
            printf("The new Node was added successfully!\n");
            break;
        
        case 2:
            printf("Enter with the Node key to delete: ");
            scanf("%d", &x);
            getchar();
            if(deleteNode(&head, x)){
                printf("The Node was deleted successfully!\n");
            }else{
                printf("Node wasn`t found!\n");
            }
            break;
        
        case 3:
            printf("Enter with the Node key to search: ");
            scanf("%d", &x);
            getchar();
            Node* found = searchNode(head, x);
            if(found == NULL){
                printf("A Node with this key doesn`t exist!\n");
            }else{
                if(head->isSuffixSumPerformed){
                    head->suffixsum = suffixsum(head);
                }
                displayNode(found);
            }
            break;
        
        case 4:
            printf("Double Linked List\n\n");
            displayList(head);
            break;
        
        case 5:
            head->suffixsum = suffixsum(head);
            printf("Suffix sum performed successfully\n");
            break;

        case 6:
            return 0;
        }
        printf("\nClick 'ENTER' to back to menu!\n");
        input_flush();
        system("clear");
    }
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
    newNode->isSuffixSumPerformed = false;
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
        printf("Key: %d ->", current->key);   
        current = current->next;  
    }
    printf("NULL\n");  
}

/**
 * @brief Display the menu options and prompts the use to choose an option
 * 
 * @return int The selected menu option
 */
int main_menu(void)
{
    int i; 

    char *title = "\nMain Menu\n\n";
    char *a = "(1) Add a new Node\n";
    char *b = "(2) Delete a Node\n";
    char *c = "(3) Search a Node\n";
    char *d = "(4) Display the List\n";
    char *e = "(5) Do the Suffix Sum\n";
    char *f = "(6) Exit\n";

    printf("%s%s%s%s%s%s%s\n", title, a, b, c, d, e, f);

    return get_int(1,6, "Choose an Option: ");
}

/**
 * @brief Clear the input buffer by consuming and discarding all characters
 * from the standard input until a newline character is encountered
 * 
 */
void input_flush()
{
	char c;
	c = fgetc(stdin);
	while(c != '\n') c = fgetc(stdin);
}

/**
 * @brief Get an integer value within a specified range
 * 
 * @param min The minimum allowable value
 * @param max The maximum allowable value
 * @param prompt The prompt to display to the user 
 * @return int The valid value entered by the user
 */
int get_int(int min, int max, char * prompt)
{
	int i;
	do
	{
		printf("%s", prompt);
		if(!(scanf("%d", &i)))
		{
			input_flush();
			continue;
		}
	}
	while(i < min || i > max);

    input_flush();

	return i;
}

/**
 * @brief Displays the information of a found node.
 * 
 * @param nodeFound Pointer to the node to be displayed.
 */
void displayNode(Node* nodeFound) {
    printf("\nNode { \n");
    printf("    key: %d\n", nodeFound->key);
    printf("    Suffixsum: %d\n", nodeFound->suffixsum);
    printf("}\n\n");
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
    head->isSuffixSumPerformed = true;

    return head->suffixsum;
}


