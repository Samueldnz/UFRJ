#include <stdio.h>
#include <stdlib.h>

typedef struct inner_node {
    int value;
    struct inner_node* next;
} InnerNode;

typedef struct node {
    struct node* next;
    struct inner_node* head;
} Node;

void add_to_inner_list(int value, InnerNode** head) {
    InnerNode* new_node = (InnerNode*) malloc(sizeof(InnerNode));
    new_node->value = value;
    new_node->next = (*head);
    (*head) = new_node;
}

void add_to_list(Node** head, InnerNode* inner_head) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->head = inner_head;
    new_node->next = (*head);
    (*head) = new_node;
}

int main() {
    Node* list_head = NULL;
    InnerNode* inner_list_head = NULL;
    int value, n, i;

    while (scanf("%d", &n) == 1) {
        inner_list_head = NULL;

        for (i = 0; i < n; i++) {
            scanf("%d", &value);
            add_to_inner_list(value, &inner_list_head);
        }

        add_to_list(&list_head, inner_list_head);
    }

    return 0;
}

