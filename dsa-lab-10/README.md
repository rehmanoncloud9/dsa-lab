# DSA Lab 10: BST Deletion and AVL Trees

**Name:** Abdul Rehman
**Registration Number:** 576841

## What this lab covers

Deletion in a binary search tree and self balancing AVL trees, all built from scratch with raw pointers and `new`/`delete`. The lab covers the three deletion cases (leaf, one child and two children), node heights and balance factors, the four rotation cases (LL, RR, LR and RL) and rebalancing after both insertion and deletion.

## Tasks

- **Q1.cpp (BST Deletion):** Recursive `deleteBST` that handles a leaf, a node with one child and a node with two children by copying the inorder successor up and deleting it from the right subtree. Traces deletion of 20, 60 and 50 from the lab tree and tests a missing key, an empty tree and a single node tree that returns `nullptr`.
- **Q2.cpp (AVL Insertion):** `insertAVL` with `rightRotate`, `leftRotate` and a `rebalance` helper that prints which case fired. Runs the four sequences (30 20 10, 10 20 30, 30 10 20 and 10 30 20) and checks that every node is balanced after each one.
- **Q3.cpp (AVL Insertion and Deletion):** `deleteAVL` does the BST deletion first then updates the height and rebalances at every ancestor on the way back up. Rotations are picked from child balance factors. Includes the 30 20 40 10 25 50 5 trace, edge cases, a heavy child balance 0 test (one rotation is enough) and extra LR and RL deletion tests. Prints key, height and balance factor for each node.