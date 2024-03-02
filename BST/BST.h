/* BST.h: Binary Search Tree implementation.
 * Author: Metflex
 * An implementation according to the following book 
 * MIT's "Introduction to Algorithms"
 * */

#ifndef BST_H
#define BST_H

#include <stdlib.h> // for malloc

typedef struct node {
  int key;
  struct node *left;
  struct node *right;
  struct node *parent;
} Node;

Node *insert(int key);
Node *BSTsuccessor(Node *n);

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

/* returns node with smallest key greater than n */
Node *BSTsuccessor(Node *n) {
  if (n->right != NULL)
    return n->right;
  
  Node *p;
  for (p = n->parent; p != NULL && n == p->right; n = p, p = p->parent)
    ;
  return (p == NULL)? (Node*)NO_MEMORY: p;
}

#include <stdio.h> // for printing
#include "BSTutils.h"

#endif
