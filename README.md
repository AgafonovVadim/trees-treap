# Cartesian Tree with Random Priorities

## Search Trees

In this task, you need to implement a balanced binary search tree – a hierarchical data structure in the pointer machine model, where nodes contain values, and some have a left and/or right child, each of which is the root of the left and right subtrees, respectively. Nodes without children are called leaves, and the rest are internal nodes. The node located at the highest level (not a descendant of any node) is called the root (there is always only one root in a tree).

All values in the left subtree of a node are smaller than the value in the node itself. Similarly, all values in the right subtree are greater than the value in the node.

Let’s define the height of a node:
* The height of a leaf is zero
* The height of an internal node is the maximum of the heights of its children, incremented by one

The height of a tree is determined by the height of its root.

A tree is called balanced if its height does not exceed \(C \cdot \log(n)\) for some constant \(C\), where \(n\) is the number of elements in the tree.

## Modification
Your modification is a Cartesian tree with manual memory management (without using smart pointers) over a set of integers (`int`).

The main feature of this modification is that a Cartesian tree combines both a binary search tree and a binary heap (tree + heap = treap). Each node is assigned a priority, and you need to implement a Treap with random priorities.

In this task, the main focus is on avoiding memory leaks and properly extracting common code. You can find hints for implementing your structure on [Wikiconcepts](https://neerc.ifmo.ru/wiki/index.php?title=%D0%94%D0%B5%D0%BA%D0%B0%D1%80%D1%82%D0%BE%D0%B2%D0%BE_%D0%B4%D0%B5%D1%80%D0%B5%D0%B2%D0%BE) or in the [lecture video on Algorithms and Data Structures](https://www.youtube.com/watch?v=pSariokaWUA&list=PLrS21S1jm43gVKLfBnBW4Ig3SEinCD96n&index=6).
