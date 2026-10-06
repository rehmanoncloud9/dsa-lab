# DSA Lab 05: Doubly Linked Lists, Circular Linked Lists, and Stacks

**Name:** Abdul Rehman
**Registration Number:** 576841

## What this lab covers

Covers linear and circular dynamic data structures and the Last-In-First-Out (LIFO) stack abstract data type in C++:
1. **Doubly Linked Lists:** Two-way node navigation via `next` and `prev` pointers, O(1) tail insertion, forward and reverse traversal, positional insertion (`InsertBefore`), and complete boundary-safe node deletion.
2. **Circular Linked Lists:** Singly circular structures where the tail points back to `head`, loop traversal using `do-while` conditions to prevent infinite cycles, node counting, breaking circular references prior to destruction, and comprehensive deletion handling (head, tail, middle, and single remaining node).
3. **Stacks (Array & Linked List Implementations):** Fixed-capacity array stack with overflow and underflow detection, and dynamic node-based linked stack providing O(1) push, pop, and peek operations without size limitations, wrapped in an interactive menu-driven interface.

## Tasks

- **Q1.cpp (Doubly Linked List Creation and Bi-Directional Traversal):** Implements a `DoublyList` class with `node* head` and `node* tail`. Provides `AddNode(int value)` for O(1) tail appends, `PrintForward()` for head-to-tail traversal, `PrintReverse()` using `prev` links, and safe heap deallocation with `ClearList()`. Reads `count` user values and verifies both traversal directions.
- **Q2.cpp (Doubly Linked List Insertion and Deletion):** Extends the doubly linked list with `InsertBefore(int position, int value)` including 1-based index validation, and `DeleteNode(int value)` handling all boundary scenarios (empty list, value missing, deleting head, deleting tail, deleting middle, and shrinking to empty). Verifies bi-directional link integrity with `ShowBoth()` across 10 test cases.
- **Q3.cpp (Circular Linked List Creation and Traversal):** Implements a `CircularList` class where `tail->next` always links back to `head`. Features `AddNode(int value)` to maintain the circular chain, `PrintList()` and `CountNodes()` using `do-while` loops that terminate after one complete cycle, and `ClearList()` which safely breaks the circular link (`tail->next = nullptr`) before node deletion to prevent infinite deallocation loops.
- **Q4.cpp (Circular Linked List Deletion):** Implements robust node deletion in a singly circular list via `DeleteNode(int value)`. Explicitly handles all 6 boundary conditions: empty list, target not found, single-node list deletion (resetting `head` and `tail` to `nullptr`), deleting the `head` (updating `tail->next`), deleting the `tail` (updating `before->next = head`), and deleting an internal node.
- **Q5.cpp (Array-Based Stack):** Implements an `ArrayStack` with a fixed capacity of 5 integers. Tracks the top using an index integer `top` (initialized to -1). Implements `Push(int value)` with overflow detection, `Pop()` and `Peek()` with underflow protection, and `Display()` printing from top to bottom.
- **Q6.cpp (Linked List-Based Stack with Interactive Menu):** Implements a `LinkedStack` using dynamically allocated nodes adhering to LIFO principles. Supports O(1) `Push(int value)` at the head, O(1) `Pop()` deallocating the top node, `Peek()`, `Display()`, and total memory reclamation via `ClearStack()`. Provides an interactive menu-driven CLI with complete input validation and clean teardown upon exit.
