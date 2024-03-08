/*
 * bst.c: Implementation of Augmented 
 * Binary Search Tree which nodes has
 * key of type char* .
 *
 * Author: Metflex
 *
 * Note: Was Inspired by MIT's book 
 * (Introduction To Algrorithms)
 *
 * todo:
 *  [ ] 3.implement insert, delete, max, min
 *  successor, search, rank, rotate functoins.
 *      [*] 1.make insert and print with all sizes = 0 
 *      [*] 2.implement the rotation
 *      [ ] 3.maintain balanced property at insert.
 *
 *  [ ] 4.make an error handling mechanism.
 *
 * References:
 * ------------------------------------------------------------
 *    @header:
 *      Node *bst_init_root(char *key)
 *    @brief:
 *      Creates and returns a ptr to root.
 *    @param key:
 *      the key to store in the node. 
 *    @ret:
 *      a ptr to the newly created node.
 * ------------------------------------------------------------
 *    @header:
 *      void left_rotate(Node **root, Node *x)
 *    @brief:
 *      Performs rotation operation to preserve AVL property
 *    @param root:
 *      ptr to root ptr, passed by reference.
 *    @param x:
 *      ptr to the target node.
 * ------------------------------------------------------------
 *    @header:
 *      void bst_insert(Node **root, char *key)
 *    @brief:
 *      Creates and inserts node n, updates sizeses.
 *    @param root:
 *      ptr to root ptr, passed by reference.
 *    @param key:
 *      the key to store in the node.
 */

#ifndef BTS_C
#define BTS_C

#include <stdlib.h>

/* Node structure holds char* key augmented 
 * too store size */
typedef struct node {
  char *key;
  struct node *left;
  struct node *right;
  struct node *parent;
  int size;
} Node;

// Declare a badnode for error
const Node badnode = {"badnode ;(", NULL, NULL, NULL, 0};
const Node const *badnode_ptr = &badnode;

// Function declaratinos
Node *bst_init_root(char *key);
int is_greater_than(char *a, char *b);
void left_rotate(Node **root, Node *x);
void bst_insert(Node **root, char *key);
// stdout utility, prints tree
void bst_stdout(Node *root, int treewalk);
#define INORDER 0
#define PREORDER 1
#define POSTORDER 2

/* Creates and returns a ptr to root of 
 * a tree or sub-tree */
Node *bst_init_root(char *key) {
  Node *root_ptr;
  root_ptr = (Node*) malloc(sizeof(Node));
  root_ptr->key = key;
  root_ptr->left = NULL;
  root_ptr->right = NULL;
  root_ptr->parent = NULL;
  root_ptr->size = 0;

  return root_ptr;
}

void bst_stdout(Node *root, int treewalk) {
  Node *n;
  
  // empty tree 
  if (!root) {
    return;
  }

  switch (treewalk) {
  case INORDER:
    bst_stdout(root->left, treewalk);    
    printf("%s, ", root->key);
    bst_stdout(root->right, treewalk);
    break;
  case PREORDER:
    bst_stdout(root->left, treewalk);    
    bst_stdout(root->right, treewalk);
    printf("%s, ", root->key);
    break;
  case POSTORDER:
    printf("%s, ", root->key);
    bst_stdout(root->left, treewalk);    
    bst_stdout(root->right, treewalk);
    break;
  }
}

// dummie compare
int is_greater_than(char *a, char *b) {
  return a[0] > b[0];
}

/* Performs rotation operation to preserve AVL property */
void left_rotate(Node **root, Node *x) {
  Node *y;
  y = x->right;

  x->right = y->left;
  if (y->left) {
    y->left->parent = x;
  }

  y->parent = x->parent;
  if (!x->parent)
    *root = y;
  else
    y = (x->parent->left == x)? x->parent->left: x->parent->right;

  y->left = x;
  x->parent = y;
}

/* Creates and inserts node n, updates sizeses */
void bst_insert(Node **root, char *key) {
  Node *n, *child_ptr, *parent_ptr;

  n = bst_init_root(key); // makes an empty node, with size 0
  
  child_ptr = *root;
  while (child_ptr) {
    // traverse
    parent_ptr = child_ptr;
    if (is_greater_than(child_ptr->key, n->key)) {
      child_ptr = child_ptr->left;
    }
    else {
      child_ptr = child_ptr->right;
    }
  }

  // insert
  n->parent = parent_ptr;
  if (!parent_ptr) {
    *root = n;
  }

  if (is_greater_than(parent_ptr->key, n->key)) {
    parent_ptr->left = n;
  }
  else {
    parent_ptr->right = n;
  }
}

#endif
