# Linked List Tutorial (Static Memory)

This example demonstrates how to implement a simple linked list in C using static memory allocation. The linked list is built using an array of nodes, and nodes are managed using a free list.

## Concepts Covered

- **Linked List Structure:** Each node contains an integer value and a pointer to the next node.
- **Static Memory:** The list uses a fixed-size array of nodes, so its capacity is determined at compile time.
- **Free List Management:** Unused nodes are kept in a free list. Adding a node takes one from the free list; removing a node returns it to the free list.
- **Basic Operations:**
  - Create a new list
  - Add a new element
  - Remove an element (by value)
  - Count the number of elements
  - Print the list

## Data Structures

```c
struct Node {
    int value;
    struct Node* next;
};

struct LinkedList {
    struct Node* head;    // First node in the list
    struct Node* free;    // First free node
    int capacity;         // Total number of nodes
    int freeCount;        // Number of free nodes
};
```

## Functions

- `initializeList`: Sets up the linked list and free list.
- `addNode`: Adds a node with a given value to the list (to be implemented).
- `removeNode`: Removes the first node with a given value (to be implemented).
- `countNodes`: Returns the number of nodes in the list (to be implemented).
- `printList`: Prints the contents of the list (to be implemented).

## Example Usage

```c
const int MAX_NODES = 100;
struct Node nodes[MAX_NODES];
struct LinkedList list;
initializeList(&list, nodes, MAX_NODES);

// Use addNode, removeNode, countNodes, printList as needed
```

## Output Example

If the list contains values 1, 2, 3, the output will be:
```
[1] -> [2] -> [3] -> NULL
```

## Edge Cases to Consider

- Adding to an empty list
- Adding when the list is full
- Removing from an empty list
- Removing a value not present in the list
- Removing the only node in the list

---

See `main.c` for implementation details and comments.

## Challenges
1) Implement all the functions in main.c (See answers in main_solved.c)
2) Update main.c to make the linked list a doubly linked list where each element are linked to the previous and next element. (See answers in main_doubly.c)
3) Update main.c to return the newly added node. Create function to add a remove an element based on the node (and not its value)