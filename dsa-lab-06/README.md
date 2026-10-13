# DSA Lab 06: Stacks and Queues

**Name:** Abdul Rehman
**Registration Number:** 576841

## What this lab covers

This lab explores two fundamental abstract data types (ADTs) in C++: Stacks (LIFO) and Queues (FIFO).

1. **Stack Implementation (LIFO - Last In, First Out):**
   - **Array-Based Stack:** Fixed-size array tracking the `top` index, complete with boundary checking for stack overflow (`top == SIZE - 1`) and stack underflow (`top == -1`).
   - **Linked List-Based Stack:** Dynamic node-based stack supporting O(1) insertions (`push`) and deletions (`pop`) at the head without fixed size limitations, paired with safe heap memory cleanup (`clearStack`).
   - **Stack Applications:** Using LIFO characteristics to reverse strings and characters.

2. **Linear Queue Implementation (FIFO - First In, First Out):**
   - **Array-Based Linear Queue:** Sequential queue managing `front` and `rear` pointers for enqueue and dequeue operations.
   - **Boundary Handling & Lifecycle:** Identifying when the queue is empty (`front == -1`), managing first element insertion (`front = 0`), resetting pointers when the queue drains (`front == rear`), and observing the linear queue limitation when `rear` reaches capacity.
   - **Interactive Menu-Driven Application:** A customer service token management system simulating real-world ticketing.

## Tasks

- **Q1.cpp (Stack using an array):** Fixed-capacity array stack of size 5 with top initialized to -1. Implements `push(int value)` with overflow detection, `pop()` and `peek()` with underflow protection, and `display()` printing elements from top to bottom. Fully tests normal operations, overflow on a full stack, complete draining, and underflow on an empty stack.
- **Q2.cpp (Stack using a singly linked list):** Dynamic node-based stack allocating nodes on the heap. Implements `push(int value)` inserting at the head, `pop()` safely deallocating the top node, `peek()` inspecting top data, `display()` traversing from top to bottom, and `clearStack()` freeing all heap memory. Tests pop and peek on an empty stack.
- **Q3.cpp (Reversing a word using a stack):** Character array stack of size 20. Reads a single word from user input, validates string length against maximum capacity, pushes every character onto the stack, and pops each character in LIFO order to output the reversed word.
- **Q4.cpp (Inserting values into a linear array queue):** Array-based linear queue of capacity 5 tracking `front` and `rear`. Implements `enqueue(int value)` setting `front = 0` on first insert and advancing `rear`, blocking when `rear == SIZE - 1`. Implements `display()` printing from `front` to `rear`. Tests empty display, step-by-step insertions, full queue, and overflow blocking.
- **Q5.cpp (Removing values from a linear array queue):** Expands the linear queue with `dequeue()` and `peekFront()`. `dequeue()` removes the item at `front`, resetting `front = rear = -1` when the last element is removed, or incrementing `front++`. Demonstrates FIFO removals, front inspection, draining to empty, underflow handling, and reinserting after reset.
- **Q6.cpp (Customer service queue application):** Menu-driven CLI customer service ticketing application using a 5-slot linear array queue. Provides an interactive menu with options to add customer (enqueue token), serve next customer (dequeue), view next customer (peek front), display queue, and exit cleanly.
