/* BST.h: Binary Search Tree implementation.
 * Author: Metflex
 * An implementation according to the following book 
 * MIT's "Introduction to Algorithms"
 * */

#ifndef BST_H
#define BST_H

#include <stdlib.h> // for malloc

#define NODE_NOT_FOUND -1

typedef struct node {
  int key;
  struct node *left;
  struct node *right;
  struct node *parent;
} Node;

Node *insert(int);
Node *BSTMin(Node*);
Node *BSTMax(Node*);
Node *BSTSuccessor(Node*);
Node *BSTSearch(Node*, int);

/* Creates and returns a node n */
Node *insert(int key) {
  Node *n;
  n = (Node *)malloc(sizeof(Node));

  n->key = key;
  n->left = NULL;
  n->right = NULL;
  n->parent = NULL;

  return n;
}

/* Returns a ptr to the minimum element int the tree */
Node *BSTMin(Node *root) {
  for (; root->left != NULL; root = root->left)
    ;
  return (root == NULL)? (Node *)NODE_NOT_FOUND: root;
}

/* Returns a ptr to the maximum element int the tree */
Node *BSTMax(Node *root) {
  for (; root->left != NULL; root = root->right)
    ;
  return (root == NULL)? (Node *)NODE_NOT_FOUND: root;
}

/* Returns node with smallest key greater than n */
Node *BSTSuccessor(Node *n) {
  if (n->right != NULL)
    return n->right;
  
  Node *p;
  for (p = n->parent; p != NULL && n == p->right; n = p, p = p->parent)
    ;
  return (p == NULL)? (Node*)NODE_NOT_FOUND: p;
}

/* Returns a ptr to a node with key */
Node *BSTSearch(Node *root, int key) {
  if (root == NULL)
    return (Node*)NODE_NOT_FOUND;
  if (root->key == key)
    return root;

  if (key > root->key) 
    return BSTSearch(root->right, key);
  else
    BSTSearch(root->left, key);
}

#include <stdio.h> // for printing
#include "BSTutils.h"

#endif
