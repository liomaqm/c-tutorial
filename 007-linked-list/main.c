#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    // Try to implement this.

    /*
        First, think about the state of the list before adding a node.
        Then, think about the state of the list after adding a node.
        
        When doing this, it is easy to focus on the usual case (list is not empty and has more than a few node 
        already used).
        You also need to think about the edge cases:
        - adding a node to an empty list
        - adding a node to a full list (no more free nodes)
        - adding a node to a list with only one node used
    */ 
    
}

/**
 * @brief Remove a node from the linked list based on its value.
 * 
 * @param list 
 * @param value 
 */
void removeNode(struct LinkedList* list, int value) {
    // Try to implement this.

    /*
        First, think about the state of the list before removing a node.
        Then, think about the state of the list after removing a node.
        
        When doing this, it is easy to focus on the usual case (list has more than a few node 
        already used).
        You also need to think about the edge cases:
        - removing a node from an empty list
        - removing a node that does not exist in the list
        - removing a node from a list with only one node used

        Notice how we remove a node based on its value.
        The simple approach is to remove the first node with the matching value.
        A more complex approach is to remove all nodes with the matching value.
        You can choose either approach.

        You should update the documentation of this function to specify which approach you chose.
    */ 
}

/**
 * @brief Count the number of nodes in the linked list
 * 
 * @param list 
 * @return int number of nodes in the list
 */
int countNodes(const struct LinkedList* list) {
    // Try to implement this.
    return 0;
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
    // Try to implement this. Think about all the use case we need to handle.
    // including edge cases like empty list.
    // You can use printf to display the list on the screen.
    // Challenge: use the newline character '\n' to limit the length of each line to around 80 characters.
}

int main(int argc, char **argv)
{
    printf("Welcome to linked list tutorial!\n\n");

    // Create a static array of nodes to be used in the linked list
    const int MAX_NODES = 100;
    struct Node nodes[MAX_NODES];
    struct LinkedList list;
    initializeList(&list, nodes, MAX_NODES);

    // use the linked list function here to see if everything works as expected

    

    return 0;
}