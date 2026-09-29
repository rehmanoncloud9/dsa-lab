# DSA Lab Work - Semester 3

**Student:** Abdul Rehman
**Registration Number:** 576841
**Course:** Data Structures and Algorithms
**Section:** BSCS-15E

---

This repo has all my lab submissions for the DSA course. Each folder is one lab session. Click any lab below to open its folder and see the task files and description.

---

## Labs

| Lab | Topic | Tasks |
|-----|-------|-------|
| [Lab 01](./dsa-lab01/) | Arrays, Basic OOP, and Git | 7 tasks |
| [Lab 02](./dsa-lab-02/) | Pointers and Dynamic Memory | 6 tasks |
| [Lab 03](./dsa-lab-03/) | Structs and Pointer-to-Struct | 6 tasks |
| [Lab 04](./dsa-lab-04/) | Singly Linked Lists | 6 tasks |


---

## Lab 01 - Arrays, Basic OOP, and Git

**Folder:** [`dsa-lab01/`](./dsa-lab01/)

Covers declaring and modifying arrays, reading user input into arrays, the Student class, detecting duplicates, finding min/max with indices, reversing an array in place, and extracting unique values.

| File | What it does |
|------|--------------|
| [task1.cpp](./dsa-lab01/task1.cpp) | Declares an integer array, changes one element, prints before and after |
| [task2.cpp](./dsa-lab01/task2.cpp) | Reads 5 integers and prints their total |
| [task3.cpp](./dsa-lab01/task3.cpp) | Creates two Student objects, shows changes to one don't affect the other |
| [task4.cpp](./dsa-lab01/task4.cpp) | Reads 8 integers, finds and reports duplicates at first occurrence |
| [task5.cpp](./dsa-lab01/task5.cpp) | Same array, finds the largest and smallest values with their indices |
| [task6.cpp](./dsa-lab01/task6.cpp) | Reads 6 integers and reverses them in place without a second array |
| [task7.cpp](./dsa-lab01/task7.cpp) | Reads 10 integers, moves unique values to the front, prints them |

---

## Lab 02 - Pointers and Dynamic Memory

**Folder:** [`dsa-lab-02/`](./dsa-lab-02/)

Covers pointer arithmetic, dynamic arrays with `new`/`delete`, 2D arrays via pointer-to-row and double pointers, and resizing a dynamic array at runtime.

| File | What it does |
|------|--------------|
| [task1.cpp](./dsa-lab-02/task1.cpp) | Pointer to 1D array, computes sum, updates one element, shows new total |
| [task2.cpp](./dsa-lab-02/task2.cpp) | Dynamic array of marks, prints total, average, and pass count |
| [task3.cpp](./dsa-lab-02/task3.cpp) | 2D array (2 branches x 3 days), branch totals and day totals using row pointer |
| [task4.cpp](./dsa-lab-02/task4.cpp) | Double pointer 2D array (students x subjects), finds the top student |
| [task5.cpp](./dsa-lab-02/task5.cpp) | Resizes a dynamic array by copying into a larger block and adding a new element |
| [task6.cpp](./dsa-lab-02/task6.cpp) | Basic dynamic array: allocate, fill, print, free |

---

## Lab 03 - Structs and Pointer-to-Struct

**Folder:** [`dsa-lab-03/`](./dsa-lab-03/)

Covers defining `struct`, stack vs heap allocation, the arrow operator, passing struct pointers to functions (const and non-const), null pointer checks, and a full menu-driven CRUD program.

| File | What it does |
|------|--------------|
| [task1.cpp](./dsa-lab-03/task1.cpp) | Student struct on the stack, dot operator for input and display |
| [task2.cpp](./dsa-lab-03/task2.cpp) | Student struct on the heap with `new`, arrow operator, `delete` at end |
| [task3.cpp](./dsa-lab-03/task3.cpp) | Pointer to a stack struct, updates marks through pointer, shows before/after |
| [task4.cpp](./dsa-lab-03/task4.cpp) | `displayStudent(const Student*)` and `updateMarks(Student*)` function pair |
| [task5.cpp](./dsa-lab-03/task5.cpp) | nullptr lifecycle: shows record state before alloc, after alloc, after delete |
| [task6.cpp](./dsa-lab-03/task6.cpp) | Menu-driven program: create, display, update marks, delete, exit |

---

## Lab 04 - Singly Linked Lists

**Folder:** [`dsa-lab-04/`](./dsa-lab-04/)

Covers singly linked list implementation with dynamic node allocation, traversal, insertion at head and tail, 1-based linear search, boundary-safe deletion, node counting, second node access, and a full menu-driven application.

| File | What it does |
|------|--------------|
| [Q1.cpp](./dsa-lab-04/Q1.cpp) | Custom `node` and `List` class, allocates and links 3 nodes, traverses and prints |
| [Q2.cpp](./dsa-lab-04/Q2.cpp) | Appends `n` nodes via loop using `AddNode()`, counts total nodes |
| [Q3.cpp](./dsa-lab-04/Q3.cpp) | Searches for values returning 1-based position, accesses and displays the 2nd node |
| [Q4.cpp](./dsa-lab-04/Q4.cpp) | Inserts nodes at the beginning in O(1) time and at the end, tracking list order |
| [Q5.cpp](./dsa-lab-04/Q5.cpp) | Deletes node by value with complete boundary handling (head, middle, tail, single node) |
| [Q6.cpp](./dsa-lab-04/Q6.cpp) | Interactive menu-driven application integrating all list operations with safe memory cleanup |

---

*New labs will be added here as the semester progresses.*

