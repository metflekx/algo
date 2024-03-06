/* BST.h: Binary Search Tree implementation.
 * Author: Metflex
 * An implementation according to the following book 
 * MIT's "Introduction to Algorithms"
 * */

#ifndef BST_H
#define BST_H

#include <stdlib.h> // for malloc

// Structure of a node
typedef struct node {
  int key;
  struct node *left;
  struct node *right;
  struct node *parent;
} Node;

// Empty node by convention
Node tm = {-1, NULL, NULL, NULL};
Node *badnode = &tm;

// Function Declarations
Node *bst_make_node(int);
Node *bst_min(Node*);
Node *bst_max(Node*);
Node *bst_successor(Node*);
Node *bst_search(Node*, int);
void bst_insert(Node*, Node*);

/* Creates and returns a node n */
Node *bst_make_node(int key) {
  // make a node using dynamic memory allocation
  Node *n;
  n = (Node *)malloc(sizeof(Node));
  n->key = key;
  n->left = NULL;
  n->right = NULL;
  n->parent = NULL;

  return n;
}

/* Inserts n into BST */
void bst_insert(Node* root, Node* n) {
  Node *parent_ptr, *child_ptr = NULL; // iterator and parent

  child_ptr = root;
  while (child_ptr != NULL) {
    parent_ptr = child_ptr; // maintain a ptr to parent
    
    // traverse  
    child_ptr = (child_ptr->key > n->key)? child_ptr->left: child_ptr->right;
  }
  
  n->parent = parent_ptr;
  if (parent_ptr == NULL) // tree was empty
    root = n;
  else if (parent_ptr->key > n->key)
    parent_ptr->left = n;
  else
    parent_ptr->right = n;
}

/* Returns a ptr to the minimum element int the tree */
Node *bst_min(Node *root) {
  for (; root->left != NULL; root = root->left)
    ;
  return (root == NULL)? badnode: root;
}

/* Returns a ptr to the maximum element int the tree */
Node *bst_max(Node *root) {
  for (; root->left != NULL; root = root->right)
    ;
  return (root == NULL)? badnode: root;
}


/* Returns node with smallest key greater than n, 
 * returns badnode if n.key > all */
Node *bst_successor(Node *n) {
  if (n->right != NULL)
    return n->right;
  if (n->parent == NULL)
    return NULL;
  
  Node *p;
  p = n->parent;
  while (p != NULL && n == p->right) {
    n = p;
    p = n->parent;
  }

  return p? p: badnode;
}

/* Returns a ptr to a node with key */
Node *bst_search(Node *root, int key) {
  if (root == NULL)
    return badnode;
  if (root->key == key)
    return root;

  if (key > root->key) 
    return bst_search(root->right, key);
  else
    bst_search(root->left, key);
}

#include <stdio.h> // for printing
#include "BSTutils.h"

#endif
