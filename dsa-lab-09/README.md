# DSA Lab 09: Student Help Desk System

**Name:** Abdul Rehman
**Registration Number:** 576841

## What this lab covers

A help desk application combining two core data structures built using raw pointers and dynamic memory:

1. Singly linked list for registered students: Stores student roll numbers and names. New records are added at the tail. Linear search by roll number takes O(n) worst-case time, and displaying all records traverses from head to tail.
2. Singly linked queue for help requests: Tracks incoming help requests in FIFO (First In, First Out) order so students are served in the exact order they arrive. Both enqueue and dequeue run in O(1) time using front and rear pointers.
3. Safe memory management: Validates pointers before dereferencing, handles edge cases (empty list, empty queue, duplicate roll numbers, unregistered students requesting help), and frees all heap-allocated nodes before the program exits.

## Tasks

- **student_help_desk.cpp (Student Help Desk System):** Interactive console program that lets users register new students, search student records by roll number, print all registered students, enqueue help requests for registered students, serve the next student in line, view waiting requests, and deallocate all dynamic memory on exit.
