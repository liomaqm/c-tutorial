#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/**
 * A linked list is a linear collection of data elements.
 * Each element points to the next element in the sequence
 *  and hold a value. The last element points to NULL so we
 * know we reached the end of the list.
 * 
 * Linked list can be implemented in C using structures
 * and pointers.
 * 
 * Linked list can be implemented using static or dynamic memory.
 * When using static memory, the size of the list is fixed at compile time.
 * When using dynamic memory, the size of the list can grow and shrink.
 * 
 * Linked list have the following functions:
 * - Create a new list
 * - Add a new element to the list
 * - Remove an element from the list
 * - Count the number of elements in the list
 * 
 * 
 * In this example, we will implement a simple linked list
 * using static memory.
 * 
 * One way to do so is to create a linked list of un-used nodes
 * and then use them as needed:
 * - adding a new element will take a node from the un-used list
 *  and add it to the used list
 * - removing an element will take a node from the used list
 *  and add it to the un-used list
 */

// Define the base structure for a node in the linked list
// holding an integer value and a pointer to the next node
struct Node {
    int value;
    struct Node* next;
};


// Define the structure for the linked list
struct LinkedList {
    // Pointer to the first node in the list
    struct Node* head;
    // Pointer to available nodes 
    struct Node* free;
    // Total number of nodes in the list
    int capacity;
    // Number of used nodes in the list
    int freeCount;
};

void initializeList(struct LinkedList* list, struct Node* nodes, int capacity) {
    // Do some basic error checking to prevent invalid parameters
    if (list == NULL || nodes == NULL || capacity <= 0) return;

    // head points to NULL (empty list)
    list->head = NULL;
    // free points to the first node in the array
    list->free = &nodes[0];
    // list start empty so all nodes are free
    list->capacity = capacity;
    list->freeCount = capacity;

    // Link all nodes in the free list
    // nodes[0] -> nodes[1] -> nodes[2] -> ... -> nodes[capacity-1] -> NULL
    for (int i = 0; i < capacity - 1; i++) {
        nodes[i].next = &nodes[i + 1];
    }
    // Last node points to NULL
    nodes[capacity - 1].next = NULL; 
}


/**
 * @brief Add a new node to the linked list with the given value.
 * 
 * @param list 
 * @param value 
 */
void addNode(struct LinkedList* list, int value) {
    // Validate input
    if (list == NULL) return;

    // No free nodes available
    if (list->free == NULL || list->freeCount <= 0) {
        fprintf(stderr, "addNode: list is full, cannot add %d\n", value);
        return;
    }

    // Pop a node from the free list
    struct Node* node = list->free;
    list->free = node->next;

    // Initialize the node and push it to the front of the used list (head)
    node->value = value;
    node->next = list->head;
    list->head = node;

    // Update free count
    list->freeCount--;
}

/**
 * @brief Remove a node from the linked list based on its value.
 * 
 * @param list 
 * @param value 
 */
void removeNode(struct LinkedList* list, int value) {
    if (list == NULL) return;

    struct Node* prev = NULL;
    struct Node* curr = list->head;

    // Search for the first node with matching value
    while (curr != NULL && curr->value != value) {
        prev = curr;
        curr = curr->next;
    }

    // Not found
    if (curr == NULL) return;

    // Unlink from used list
    if (prev == NULL) {
        // Removing head
        list->head = curr->next;
    } else {
        prev->next = curr->next;
    }

    // Push the node back to the free list
    curr->next = list->free;
    list->free = curr;
    curr->value = 0;

    // Update free count (ensure it doesn't exceed capacity)
    if (list->freeCount < list->capacity) {
        list->freeCount++;
    }
}

/**
 * @brief Count the number of nodes in the linked list
 * 
 * @param list 
 * @return int number of nodes in the list
 */
int countNodes(const struct LinkedList* list) {
    if (list == NULL) return 0;

    int count = 0;
    const struct Node* curr = list->head;
    while (curr != NULL) {
        count++;
        curr = curr->next;
    }
    return count;
}


/**
 * @brief Print the list on the screen
 * 
 * Given a linked list with (1, 2, 3),
 * this function should display:
 * [1] -> [2] -> [3] -> NULL
 * 
 * @param list 
 */
void printList(const struct LinkedList* list) {
    if (list == NULL) {
        printf("NULL\n");
        return;
    }

    const struct Node* curr = list->head;
    if (curr == NULL) {
        // empty list
        printf("NULL\n");
        return;
    }

    size_t lineLen = 0;
    char token[64];

    while (curr != NULL) {
        int n = snprintf(token, sizeof(token), "[%d] -> ", curr->value);
        if (n < 0) n = 0;

        // wrap line if it would exceed ~78 characters
        if (lineLen + (size_t)n > 78) {
            printf("\n");
            lineLen = 0;
        }

        printf("%s", token);
        lineLen += (size_t)n;
        curr = curr->next;
    }

    // print terminator, wrap if needed
    const char* terminator = "NULL\n";
    if (lineLen + strlen(terminator) > 78) {
        printf("\n");
    }
    printf("%s", terminator);
}

int main(int argc, char **argv)
{
    printf("Welcome to linked list tutorial!\n\n");

    // Create a static array of nodes to be used in the linked list
    const int MAX_NODES = 100;
    struct Node nodes[MAX_NODES];
    struct LinkedList list;
    initializeList(&list, nodes, MAX_NODES);

    // Demonstrate addNode
    printf("Adding nodes: 1, 2, 3\n");
    addNode(&list, 1);
    addNode(&list, 2);
    addNode(&list, 3);
    printf("List after adds:\n");
    printList(&list);
    printf("countNodes = %d, freeCount = %d\n\n", countNodes(&list), list.freeCount);

    // Demonstrate removeNode (remove head, middle, non-existing)
    printf("Removing value 3 (head)\n");
    removeNode(&list, 3);
    printList(&list);
    printf("countNodes = %d, freeCount = %d\n\n", countNodes(&list), list.freeCount);

    printf("Removing value 1 (middle)\n");
    removeNode(&list, 1);
    printList(&list);
    printf("countNodes = %d, freeCount = %d\n\n", countNodes(&list), list.freeCount);

    printf("Attempting to remove non-existing value 99\n");
    removeNode(&list, 99);
    printList(&list);
    printf("countNodes = %d, freeCount = %d\n\n", countNodes(&list), list.freeCount);

    // Reuse freed nodes
    printf("Adding nodes: 42, 99\n");
    addNode(&list, 42);
    addNode(&list, 99);
    printList(&list);
    printf("countNodes = %d, freeCount = %d\n\n", countNodes(&list), list.freeCount);

    // Add a few more to show ordering (new nodes are pushed to head)
    printf("Adding nodes: 7, 8\n");
    addNode(&list, 7);
    addNode(&list, 8);
    printList(&list);
    printf("countNodes = %d, freeCount = %d\n\n", countNodes(&list), list.freeCount);

    return 0;
}