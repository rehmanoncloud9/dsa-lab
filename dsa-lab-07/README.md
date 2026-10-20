# DSA Lab 07: Circular Queues and Deques (Double-Ended Queues)

**Name:** Abdul Rehman  
**Registration Number:** 576841  
**Section:** BSCS-15E  

## What this lab covers

This lab explores advanced linear queue variations, circular queues, and double-ended queues (deques) implemented through both static circular arrays and dynamic linked nodes in C++:

1. **Linear Queue Limitation (False Overflow):**
   - Examining how a linear array queue triggers overflow (`rear == SIZE - 1`) even after multiple dequeues leave vacant slots at the front.
   - Understanding index reset mechanics when the queue becomes completely empty (`front == rear`).

2. **Linked Queue Implementation (O(1) Enqueue & Dequeue):**
   - Dynamic node allocation using `front` (head for removals) and `rear` (tail for insertions) pointers.
   - Eliminating fixed capacity constraints while preventing memory leaks with a dedicated heap cleanup routine (`ClearQueue()`) and destructor.

3. **Circular Queue Implementation (Ring Buffer with Modulo Arithmetic):**
   - Reusing deallocated slots at the start of the array using modulo wrap-around: `rear = (rear + 1) % SIZE` and `front = (front + 1) % SIZE`.
   - Distinguishing empty state (`front == -1`) from full state (`(rear + 1) % SIZE == front`).
   - Circular display traversal that safely handles cases where `rear < front`.

4. **Circular Queue Real-World Application (Round-Robin Service Turns):**
   - Simulating fair scheduling where the front entity is dequeued, served, and re-enqueued to the tail (`RotateTurn()`), maintaining constant queue size.

5. **Double-Ended Queue (Deque) using Circular Array:**
   - Enabling O(1) insertions and deletions at both ends: `InsertFront`, `InsertRear`, `DeleteFront`, and `DeleteRear`.
   - Handling circular backward wrapping with offset arithmetic: `(index + SIZE - 1) % SIZE` to avoid negative index values in C++.

6. **Double-Ended Queue (Deque) using Doubly Linked Nodes:**
   - Bidirectional node linkage with `prev` and `next` pointers for true O(1) operations on both ends without fixed-capacity caps.
   - Menu-driven CLI interface with robust edge-case handling (empty checks, single-node resets, heap cleanup upon exit).

---

## Tasks

- **Q1.cpp (Linear Queue using an array):** Demonstrates a 5-element array linear queue. Showcases how dequeuing from a full queue frees slots at the front that cannot be reused due to `rear == SIZE - 1` (false overflow), and shows full pointer reset (`front = rear = -1`) once all elements are drained.
- **Q2.cpp (Queue using singly linked nodes):** Dynamic node-based queue with `front` and `rear` pointers. Implements O(1) `Enqueue(int value)` and `Dequeue()` without fixed capacity. Handles single-node removal edge case (resetting `rear = nullptr`), dynamic display traversal, and full memory deallocation via `ClearQueue()`.
- **Q3.cpp (Circular Queue using an array):** Implements a circular ring buffer of capacity 5 using modulo arithmetic `(index + 1) % SIZE`. Demonstrates wrap-around enqueues into slots vacated by previous dequeues, full detection (`(rear + 1) % SIZE == front`), and wrap-aware display traversal.
- **Q4.cpp (Rotating service turns using circular queue):** Models a round-robin rotation mechanism (`RotateTurn()`) where the front student ID is served and immediately appended to the rear of the queue. Tests multi-turn continuous rotation, turn count validation, single-student queue, and empty queue handling.
- **Q5.cpp (Deque using a circular array):** Implements a double-ended queue supporting `InsertFront()`, `InsertRear()`, `DeleteFront()`, and `DeleteRear()` on a 5-element circular array. Uses safe positive modulus formulas `(front + SIZE - 1) % SIZE` for front insertions and rear deletions, handling boundary transitions and index resets.
- **Q6.cpp (Menu-driven linked deque using doubly linked nodes):** Interactive console application implementing a dynamic double-ended queue using doubly linked nodes (`prev` and `next`). Provides a CLI menu for inserting and deleting from both front and rear, forward display traversal, and safe heap memory deallocation (`ClearDeque()`) on exit.
