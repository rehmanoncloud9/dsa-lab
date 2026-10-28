# DSA Lab 08: Binary Trees and Binary Search Trees

**Name:** Abdul Rehman
**Registration Number:** 576841

## What this lab covers

Binary trees and Binary Search Trees (BSTs) built from scratch using manually linked nodes and `new`/`delete` for dynamic memory. The lab covers all three classic depth-first traversal orders (inorder, preorder, postorder) done both recursively and iteratively using an explicit stack, breadth-first level-order traversal using a queue, recursive and iterative search in a BST exploiting the left-less / right-greater property, and recursive and iterative node insertion while handling duplicate values and the degenerate skewed-tree case.

## Tasks

- **Q1.cpp (Recursive DFS Traversals):** Builds a 7-node binary tree by linking nodes manually, then prints inorder (left-root-right), preorder (root-left-right), and postorder (left-right-root) using three recursive functions. Also tests the null tree and a single-node tree to verify the base case returns cleanly with no output.
- **Q2.cpp (Level Order Traversal):** Uses the STL `queue` to do a breadth-first traversal of the same tree, visiting every node level by level from top to bottom. Enqueues left and right children of each dequeued node; prints nothing for a null root.
- **Q3.cpp (Iterative DFS Traversals):** Reimplements preorder and inorder without recursion. Preorder uses a stack with the right child pushed first so the left comes off first. Inorder walks as far left as possible, stacking nodes along the way, then unwinds and pivots right. Compares output against the recursive versions to confirm correctness.
- **Q4.cpp (BST Search):** Searches a BST for a key using both a recursive and an iterative version, each exploiting the BST ordering to eliminate half the remaining tree at every step. A `showPath` helper prints every node visited so the O(log n) vs O(n) comparison is visible. Also verifies the empty-tree edge case.
- **Q5.cpp (Recursive BST Insertion):** Inserts values into a BST recursively by returning the (possibly new) root at each level so the parent's pointer is updated automatically. Duplicates are silently ignored. An inorder traversal after each insert confirms the BST stays sorted. Searches for a freshly inserted value to verify it is reachable.
- **Q6.cpp (Iterative BST Insertion):** Achieves the same result without recursion by walking parent and current pointers until a null slot is found, then attaching the new node to the correct side of the parent. Builds identical trees using both recursive and iterative insertion and confirms they match. Also inserts into a right-skewed chain to show that search in a skewed tree requires as many comparisons as there are nodes, demonstrating why tree balance matters.
