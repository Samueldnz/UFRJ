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
void printTreeInOrder(Node* root);
Node* searchNode(Node* root, int keyToSearch);
bool deleteNode(Node** root, int keyToDelete);
Node* findMinimumValueNode(Node* root);
int main_menu(void);
void input_flush();
int get_int(int min, int max, char * prompt);
void displayNode(Node* nodeFound);

int main(void)
{
    int keyAmount, i, key;
    Node* root = NULL;

    scanf("%d", &keyAmount);

    for(i = 0; i < keyAmount; i++){
        scanf("%d", &key);
        addNode(&root, key);
    }printf("\nAll the nodes were added successfully!\n");

    freopen("/dev/tty", "r", stdin); /*Redirects the stdin file*/

    while(1){
        switch(main_menu()){
            
            case 1:
                printf("Enter with the new Node key value to add: ");
                scanf("%d", &key);
                getchar();
                addNode(&root, key);
                printf("The new Node was added successfully!\n");
                break;

            case 2:
                printf("Enter with the Node key to delete: ");
                scanf("%d", &key);
                getchar();
                if(deleteNode(&root, key)){
                    printf("The Node was deleted successfully!\n");
                }else{
                    printf("A Node with this key doesn`t exist!\n");
                }
                break;

            case 3:
                printf("Enter with the Node key to search: ");
                scanf("%d", &key);
                getchar();
                Node* found = searchNode(root, key);
                if(found == NULL){
                    printf("A Node with this key value doesn`t exist!\n");
                }else{
                    displayNode(found);
                }
                break;

            case 4:
                printf("Binary Tree: \n\n");
                printTreeInOrder(root);
                break;

            case 5:
                printf("Exiting...\n");
                return 0;
        }
        printf("\nClick 'ENTER' to back to menu!\n");
        input_flush();
        system("clear");
    }
}

/**
 * @brief Displays the details of a node in the binary search tree.
 * 
 * @param nodeFound Pointer to the node to be displayed.
 */
void displayNode(Node* nodeFound){
    printf("\nNode { \n");
    printf("    key: %d\n", nodeFound->valueKey);

    if(nodeFound->leftSubTree == NULL){
        printf("    Left Subtree Root: NULL\n");
    }else{
        printf("    Left Subtree Root: %d\n", nodeFound->leftSubTree->valueKey);
    }

    if(nodeFound->rightSubTree == NULL){
        printf("    Right Subtree Root: NULL\n");
    }else{
        printf("    Right Subtree Root: %d\n", nodeFound->rightSubTree->valueKey);
    }
    printf("}\n\n");
}

/**
 * @brief Deletes a node with a given key from the binary search tree. 
 * 
 * @param root  Pointer to the root node of the binary search tree.
 * @param keyToDelete The key of the node to be deleted.
 * @return true if the node is deleted successfully.
 * @return false if the node with the given key does not exist in the tree.
 */
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

/**
 * @brief Adds a node with a given key to the binary search tree.
 * 
 * @param root Pointer to the root node of the binary search tree.
 * @param key The key of the node to be added.
 */
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

/**
 * @brief Searches for a node with a given key in the binary search tree.
 * 
 * @param root Pointer to the root node of the binary search tree.
 * @param keyToSearch The key to search for.
 * @return Node*  Pointer to the node with the given key if found, otherwise NULL.
 */
Node* searchNode(Node* root, int keyToSearch){
    if(root == NULL || root->valueKey == keyToSearch) return root;

    if(keyToSearch < root->valueKey){
        return searchNode(root->leftSubTree, keyToSearch);
    }else{
        return searchNode(root->rightSubTree, keyToSearch);
    }

    return false;
}

/**
 * @brief Create a Node object
 * 
 * @param key The key value for the new node.
 * @return Node*  Pointer to the newly created node.
 */
Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) exit(1);

    newNode->valueKey = key;
    newNode->leftSubTree = NULL;
    newNode->rightSubTree = NULL;

    return newNode;
}

/**
 * @brief Prints the elements of the binary search tree in ascending order.
 * 
 * @param root  Pointer to the root node of the binary search tree.
 */
void printTreeInOrder(Node* root){
    if (root != NULL) {
        printTreeInOrder(root->leftSubTree);
        printf("%d ", root->valueKey);
        printTreeInOrder(root->rightSubTree);
    }
}

/**
 * @brief Finds the node with the minimum value in the given binary search tree.
 * 
 * @param root  Pointer to the root node of the binary search tree.
 * @return Node* Pointer to the node with the minimum value.
 */
Node* findMinimumValueNode(Node* root){
    if(root == NULL) return NULL;

    while(root->leftSubTree != NULL){
        root = root->leftSubTree;
    }
    return root;
}

/**
 * @brief Display the menu options and prompts the use to choose an option
 * 
 * @return int The selected menu option
 */
int main_menu(void)
{
    char *title = "\nMain Menu\n\n";
    char *a = "(1) Add a new Node\n";
    char *b = "(2) Delete a Node\n";
    char *c = "(3) Search a Node\n";
    char *d = "(4) Display the Binary Tree\n";
    char *e = "(5) Exit\n";

    printf("%s%s%s%s%s%s\n", title, a, b, c, d, e);

    return get_int(1,5, "Choose an Option: ");
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