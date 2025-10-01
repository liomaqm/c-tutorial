#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*
  Doubly-linked version of main_solved.c
  - Nodes have prev and next
  - LinkedList keeps head and tail
  - Free list is still a singly-linked chain using the next pointer
*/

struct Node {
    int value;
    struct Node* prev;
    struct Node* next;
};

struct LinkedList {
    struct Node* head;
    struct Node* tail;
    struct Node* free;
    int capacity;
    int freeCount;
};

void initializeList(struct LinkedList* list, struct Node* nodes, int capacity) {
    if (list == NULL || nodes == NULL || capacity <= 0) return;

    list->head = NULL;
    list->tail = NULL;
    list->free = &nodes[0];
    list->capacity = capacity;
    list->freeCount = capacity;

    for (int i = 0; i < capacity; i++) {
        nodes[i].value = 0;
        nodes[i].prev = NULL;
        nodes[i].next = (i < capacity - 1) ? &nodes[i + 1] : NULL; // free-list uses next
    }
}

void addNode(struct LinkedList* list, int value) {
    if (list == NULL) return;
    if (list->free == NULL || list->freeCount <= 0) {
        fprintf(stderr, "addNode: list is full, cannot add %d\n", value);
        return;
    }

    // Pop from free list
    struct Node* node = list->free;
    list->free = node->next;

    // Initialize and insert at tail (instead of head)
    node->value = value;
    node->next = NULL;
    node->prev = list->tail;

    if (list->tail != NULL) {
        list->tail->next = node;
    } else {
        // list was empty, set head
        list->head = node;
    }
    list->tail = node;

    list->freeCount--;
}

void removeNode(struct LinkedList* list, int value) {
    if (list == NULL) return;
    struct Node* curr = list->head;

    // find first match
    while (curr != NULL && curr->value != value) {
        curr = curr->next;
    }
    if (curr == NULL) return; // not found

    // unlink from used list
    if (curr->prev != NULL) {
        curr->prev->next = curr->next;
    } else {
        // removing head
        list->head = curr->next;
    }

    if (curr->next != NULL) {
        curr->next->prev = curr->prev;
    } else {
        // removing tail
        list->tail = curr->prev;
    }

    // push back to free list (use next for free chain)
    curr->prev = NULL;
    curr->next = list->free;
    list->free = curr;
    curr->value = 0;

    if (list->freeCount < list->capacity) list->freeCount++;
}

int countNodes(const struct LinkedList* list) {
    if (list == NULL) return 0;
    int count = 0;
    const struct Node* cur = list->head;
    while (cur != NULL) {
        count++;
        cur = cur->next;
    }
    return count;
}

void printList(const struct LinkedList* list) {
    if (list == NULL) {
        printf("NULL\n");
        return;
    }
    const struct Node* cur = list->head;
    if (cur == NULL) {
        printf("NULL\n");
        return;
    }

    size_t lineLen = 0;
    char token[64];

    while (cur != NULL) {
        int n = snprintf(token, sizeof(token), "[%d] <-> ", cur->value);
        if (n < 0) n = 0;

        if (lineLen + (size_t)n > 78) {
            printf("\n");
            lineLen = 0;
        }

        printf("%s", token);
        lineLen += (size_t)n;
        cur = cur->next;
    }

    const char* terminator = "NULL\n";
    if (lineLen + strlen(terminator) > 78) printf("\n");
    printf("%s", terminator);
}

int main(int argc, char **argv)
{
    printf("Welcome to doubly-linked list tutorial!\n\n");

    const int MAX_NODES = 100;
    struct Node nodes[MAX_NODES];
    struct LinkedList list;
    initializeList(&list, nodes, MAX_NODES);

    printf("Adding nodes: 1, 2, 3\n");
    addNode(&list, 1);
    addNode(&list, 2);
    addNode(&list, 3);
    printf("List after adds:\n");
    printList(&list);
    printf("countNodes = %d, freeCount = %d\n\n", countNodes(&list), list.freeCount);

    printf("Removing value 3 (tail)\n");
    removeNode(&list, 3);
    printList(&list);
    printf("countNodes = %d, freeCount = %d\n\n", countNodes(&list), list.freeCount);

    printf("Removing value 2 (middle)\n");
    removeNode(&list, 2);
    printList(&list);
    printf("countNodes = %d, freeCount = %d\n\n", countNodes(&list), list.freeCount);

    printf("Attempting to remove non-existing value 99\n");
    removeNode(&list, 99);
    printList(&list);
    printf("countNodes = %d, freeCount = %d\n\n", countNodes(&list), list.freeCount);

    printf("Adding nodes: 42, 99\n");
    addNode(&list, 42);
    addNode(&list, 99);
    printList(&list);
    printf("countNodes = %d, freeCount = %d\n\n", countNodes(&list), list.freeCount);

    printf("Adding nodes: 7, 8\n");
    addNode(&list, 7);
    addNode(&list, 8);
    printList(&list);
    printf("countNodes = %d, freeCount = %d\n\n", countNodes(&list), list.freeCount);

    return 0;
}
