# DSA Lab 04: Singly Linked Lists

**Name:** Abdul Rehman
**Registration Number:** 576841

## What this lab covers

Implementation of a singly linked list in C++ using a custom `node` structure and a `List` class with private `head` pointer. Covers dynamic node allocation with `new`, traversal using local pointers without modifying `head`, insertion at the head and tail, linear search with 1-based indexing, second-node access, safe node deletion across all boundary cases, and full heap cleanup with `delete` to prevent memory leaks.

## Tasks

- **Q1.cpp (Creating and Traversing a List):** Defines the `node` structure inside the `List` class. Implements `CreateThreeNodes()` to read three values and chain three dynamic nodes in input order, `PrintList()` to traverse and display elements with arrows, and `ClearList()` to deallocate all nodes safely.
- **Q2.cpp (Appending Nodes Using a Loop):** Adds `AddNode(int newValue)` to append nodes to the end of the list and `CountNodes()` to return the total node count. In `main()`, reads `n` integers in a loop and prints the resulting list and its size (tested with n = 0, 1, 5).
- **Q3.cpp (Searching and Accessing the Second Node):** Implements `SearchNode(int target)` which performs a linear search returning the 1-based position of the first occurrence (or prints "Value not found"), and `PrintSecondNode()` which safely checks list length and displays the second element.
- **Q4.cpp (Inserting at the Beginning):** Implements `InsertAtBeginning(int newValue)` to push elements to the head of the list in O(1) time by rewiring `fresh->next = head` and updating `head`. Demonstrates step-by-step insertions at the head and tail.
- **Q5.cpp (Deleting a Node by Value):** Implements `DeleteNode(int target)` to remove the first matching node while safely handling all boundary conditions: empty list, deleting the head node, deleting a middle node, deleting the tail node, value not found, and deleting the single remaining node.
- **Q6.cpp (Menu-Driven Linked List Application):** Combines all core operations into an interactive, loop-driven CLI application with options for insertion at head/tail, search, deletion, full display, node count, second-node inspection, input validation, and automatic memory deallocation on exit.
