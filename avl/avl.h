#ifndef avl_H
#define avl_H

#include <stdlib.h> // for malloc
#include <stdio.h>

// Structure of a AvlNode
typedef struct avlnode {
  int key;
  struct avlnode *left;
  struct avlnode *right;
  struct avlnode *parent;
  int size;
} AvlNode;

// Empty AvlNode by convention
AvlNode *bad_avlnode_ptr = NULL;

// Function Declarations
AvlNode *avl_make_AvlNode(int key);
AvlNode *avl_min(AvlNode *root);
AvlNode *avl_max(AvlNode *root);
AvlNode *avl_successor(AvlNode *n);
AvlNode *avl_search(AvlNode *root, int key);
void *avl_left_rotate(AvlNode **root, AvlNode *x);
void *avl_right_rotate(AvlNode **root, AvlNode *x);
void avl_insert(AvlNode **root, AvlNode *n);
AvlNode *avl_delete(AvlNode **root, AvlNode *n);
int avl_rank(AvlNode *root, int t);

 /*------------------------------------*/
#define INORDER 0 
#define PREORDER 1
#define POSTORDER 2

// directions
#define DIR_RIGHT 0
#define DIR_LEFT 1

// printing 
#define NOVERBOSE 0
#define VERBOSE 1

void avl_print_trace_root(AvlNode *n, int verbose);
void avl_print_trace_leaf(AvlNode *n, int direction, int verbose);
void avl_print(AvlNode *root, int tree_walk, int verbose);

#endif
