# DSA Lab 03: Structs and Pointer-to-Struct

**Name:** Abdul Rehman
**Registration Number:** 576841

## What this lab covers

Defining and using `struct` in C++, creating struct variables on the stack and heap, accessing members through the dot operator and the arrow operator, and managing heap-allocated structs with `new` and `delete`.

## Tasks

- **Task 1:** Declares a `Student` struct (roll number, name, marks), creates one on the stack, takes input, and displays the record.
- **Task 2:** Same struct but allocated on the heap using `new`. Accesses members through the arrow operator and frees memory at the end.
- **Task 3:** Creates a struct on the stack and points a pointer at it. Takes input and updates marks through the pointer, then shows both the original and updated records.
- **Task 4:** Adds two helper functions: `displayStudent` (takes a `const Student*`) and `updateMarks` (takes a `Student*`). Shows how const vs non-const pointers control what you can and cannot modify.
- **Task 5:** Starts with a `nullptr`, demonstrates what happens before allocation, after allocation, and after deletion by checking the pointer state each time before displaying.
- **Task 6:** Full menu-driven program combining all of the above. Lets the user create, display, update marks, and delete a student record in a loop until they choose to exit.
