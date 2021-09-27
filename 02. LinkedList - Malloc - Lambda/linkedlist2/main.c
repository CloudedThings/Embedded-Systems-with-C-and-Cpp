#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
    int data;
    struct node_t *next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
    int length;
} LinkedList;


void init_list(LinkedList *list) {
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
}

void print_list(LinkedList *list) {
    Node *node = list->head;
    while(node != NULL) {
        printf("%d", node->data);
        if(node->next == NULL) {
            printf(" -| ");
        }
        else {
            printf(" -> ");
        }

        node = node->next;
    }
    printf("\nList length: %d\n", list->length);
}

Node *push_tail(LinkedList *list, int data) {
    if (list->tail == NULL) {
        // List is empty
        list->tail = (Node *)malloc(sizeof(Node));
        if(list->tail == NULL) {
            printf("Memery error!\n");
            return list->tail;
        }
        list->tail->data = data;
        list->tail->next = NULL;
        list->head = list->tail;
        list->length++;
        return list->tail;
    }

    // We have something in the list
    list->tail->next = (Node *)malloc(sizeof(Node));
    if(list->tail == NULL) {
        printf("Memory error!\n");
        return list->tail;
    }
    list->tail = list->tail->next;
    list->tail->data = data;
    list->tail->next = NULL;
    list->length++;
    printf("Added new node at tail, with value of: %d\n", data);
    return list->tail;
}

void pushHead(LinkedList *list, int val) {
    Node *temp = list->head;
    if (list->head == NULL) {
        // list is empty
        list->head = (Node*) malloc(sizeof (Node));
        if(list->head == NULL) {
            printf("Memory not allocated");
        }
        list->head->data = val;
        list->head->next = NULL;
        list->tail = list->head;
        list->length++;
    }
    else {
        list->head = (Node*)malloc(sizeof(Node));
        list->head->next = temp;
        list->head->data = val;
        list->length++;
    }
}

int popTail(LinkedList *list) {
    int val;
    Node *ptr = list->head;
    Node *temp = list->head;
    if (list->head == NULL) {
        printf("The list is empty.");
    }
    while (ptr->next != NULL) {
        temp = ptr;
        ptr = ptr->next;
    }
    temp->next = NULL;
    ptr->data = val;
    free(ptr);
    list->length--;
    return val;
}

// push head
// pop head
// push tail
// pop tail
// push at
// pop at
// pop value
// peek at
// Alla pop skall returna datat i den poppade noden

// Gör om listan till en dubbellänkad lista

int main() {
    int n;

    LinkedList list;
    init_list(&list);

    printf("Adding values at the tail:\n");
    push_tail(&list, 1);
    push_tail(&list, 2);
    push_tail(&list, 3);
    push_tail(&list, 4);
    printf("%d\n", list.length);
    print_list(&list);
    printf("------------------------------------\n");
    printf("Pushing new value at the head. Type your value: ");
    scanf("%d", &n);
    pushHead(&list, n);
    printf("Pushing new value at the head. Type your value: ");
    scanf("%d", &n);
    pushHead(&list, n);
    print_list(&list);
    printf("\nPopping tail node with value: %d\n", popTail(&list));
    print_list(&list);

    Node *current = list.head;
    while(list.head != NULL) {
        list.head = list.head->next;
        free(current);
        list.length--;
        current = list.head;
    }
    list.tail = NULL;
    if(list.head == NULL) {
        printf("List is empty!\n");
    }
    printf("List length: %d\n", list.length);
    return 0;
}