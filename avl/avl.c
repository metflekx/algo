/* avl.h: Self Balancing Binary Search Tree implementation.
 * Author: Metflex
 * An implementation according to the following book 
 * MIT's "Introduction to Algorithms"
 * 
 * todo:
 *  [*] implement delete
 *  [ ] implement rebalancing 
 *  [ ] fix rotate to rebalance
 *  [ ] implement error handling and make sure 
 *      only unique keys can be inserted.
 *  [ ] write a utility function that walks 
 *      the tree and free() each node, remember to
 *      free badnode.
 *
 * References:
 * ------------------------------------------------------------
 *  @header:
 *    AvlNode *avl_make_AvlNode(int key)
 *  @brief:
 *    Creates and returns a AvlNode n.
 *  @param key:
 *    The key of that gets assigned to the 
 *    newly created AvlNode.
 *  @ret:
 *    A ptr to the newly created AvlNode.
 * ------------------------------------------------------------
 *  @header:
 *    AvlNode *avl_min(AvlNode *root)
 *  @brief:
 *    Returns a ptr to the minimum element int the tree.
 *  @param root:
 *    A ptr to the root of tree or sub-tree. 
 *  @ret:
 *    A ptr to the AvlNode with minimum key in the tree.
 * ------------------------------------------------------------
 *  @header:
 *    AvlNode *avl_max(AvlNode *root)
 *  @brief:
 *    Returns a ptr to the maximum element int the tree.
 *  @param root:
 *    A ptr to the root of tree or sub-tree. 
 *  @ret:
 *    A ptr to the AvlNode with maximum key in the tree.
 * ------------------------------------------------------------
 *  @header:
 *    AvlNode *avl_successor(AvlNode *n)
 *  @brief:
 *    Returns AvlNode with smallest key greater than n;
 *    returns bad_avlnode_ptr if n.key > all 
 *  @param n:
 *    A ptr to the target AvlNode for the successor operatoin.
 *  @ret:
 *    A ptr to the successor of AvlNode n.
 * ------------------------------------------------------------
 *  @header:
 *    AvlNode *avl_search(AvlNode *root, int key)
 *  @brief:
 *    Looks for AvlNode with key in the tree by 
 *    iterating in O(h).
 *  @param root:
 *    A ptr to the root of tree or sub-tree. 
 *  @param key:
 *    The key associated with the target AvlNode.
 *  @ret:
 *    A ptr to a avlnode with key if found, bad_avlnode_ptr if
 *    the desired node is not found.
 * ------------------------------------------------------------
 *  @header:
 *   void *avl_left_rotate(AvlNode **root, AvlNode *x)
 *  @brief:
 *    Perfroms avlrotate left operation wrt. AvlNode x, aims to
 *    maintain the avl property. resets the root reference if
 *    neccessary.
 *  @param root:
 *    Reference too the root of the the tree.
 *  @param x:
 *    The target of rotate operation.
 * ------------------------------------------------------------
 *  @header:
 *   void *avl_right_rotate(AvlNode **root, AvlNode *x)
 *  @brief:
 *    Perfroms avlrotate right operation wrt. AvlNode x, aims to
 *    maintain the avl property. resets the root reference if
 *    neccessary.
 *  @param root:
 *    Reference to the root of the the tree.
 *  @param x:
 *    The target of rotate operation.
 * ------------------------------------------------------------
 *  @header:
 *    void avl_insert(AvlNode **root, AvlNode *n)
 *  @brief:
 *    Inserts AvlNode n into avl. resets the root reference if
 *    neccessary.
 *  @param:
 *    Reference to the root of the the tree. 
 * ------------------------------------------------------------
 *  @header:
 *    AvlNode *avl_delete(AvlNode **root, AvlNode *n) {
 *  @brief:
 *    Deletes a AvlNode n from tree and returns it, returns
 *    bad_avl_node_ptr if n DNE. in tree..
 *  @param root:
 *    Reference to the root of the the tree. 
 *  @param n:
 *    Target avlnode for delete operation.
 *  @ret:
 *    The deleted AvlNode. 
 * ------------------------------------------------------------
 *  @header:
 *    int avl_rank(AvlNode *root, int t)
 *  @brief:
 *    counts the number keys <= t in given tree (rank of t).
 *  @param root:
 *    A ptr to the root of the the tree or sub-tree. 
 *  @param t:
 *    The key t, we wish to count the # of keys <= t in tree.
 *  @ret:
 *    The number keys <= t in given tree.
 * ------------------------------------------------------------
 * */

#ifndef avl_H
#define avl_H

#include <stdlib.h> // for malloc

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
AvlNode *avl_search(AvlNode *root, intkey );
void *avl_left_rotate(AvlNode **root, AvlNode *x);
void *avl_right_rotate(AvlNode **root, AvlNode *x);
void avl_insert(AvlNode **root, AvlNode *n);
AvlNode *avl_delete(AvlNode **root, AvlNode *n);
int avl_rank(AvlNode *root, int t);

/* Creates and returns a AvlNode n */
AvlNode *avl_make_AvlNode(int key) {
  // make a AvlNode using dynamic memory allocation
  AvlNode *n;
  n = (AvlNode *)malloc(sizeof(AvlNode));
  n->key = key;
  n->left = NULL;
  n->right = NULL;
  n->parent = NULL;
  n->size = 1; // each avlnode at init. only contains itslef

  return n;
}

/* Returns a ptr to the minimum element int the tree */
AvlNode *avl_min(AvlNode *root) {
  for (; root->left != NULL; root = root->left)
    ;
  return (root == NULL)? bad_avlnode_ptr: root;
}

/* Returns a ptr to the maximum element int the tree */
AvlNode *avl_max(AvlNode *root) {
  for (; root->left != NULL; root = root->right)
    ;
  return (root == NULL)? bad_avlnode_ptr: root;
}

/* Returns AvlNode with smallest key greater than n, 
 * returns bad_avlnode_ptr if n.key > all */
AvlNode *avl_successor(AvlNode *n) {
  if (n->right != NULL)
    return n->right;
  if (n->parent == NULL)
    return NULL;
  
  AvlNode *p;
  p = n->parent;
  while (p != NULL && n == p->right) {
    n = p;
    p = n->parent;
  }

  return p? p: bad_avlnode_ptr;
}

/* Returns a ptr to a AvlNode with key, 
 * returns bad_avlnode_ptr if not found. */
AvlNode *avl_search(AvlNode *root, int key) {
  if (root == NULL)
    return bad_avlnode_ptr;
  if (root->key == key)
    return root;

  if (key > root->key) 
    return avl_search(root->right, key);
  else
    avl_search(root->left, key);
}

/* Perfroms avl_rotate left operation wrt. AvlNode x */
void *avl_left_rotate(AvlNode **root, AvlNode *x) {
  AvlNode *y;

  y = x->right;
  x->right = y->left;
  if (y->left)
    y->left->parent = x;

  y->parent = x->parent;
  if (!x->parent)
    *root = y;
  else if (x == x->parent->left)
    x->parent->left = y;
  else
    x->parent->right = y;

  y->left = x;
  x->parent = y;
}

/* Perfroms avl_rotate right operation wrt. AvlNode x */
void *avl_right_rotate(AvlNode **root, AvlNode *x) {
  AvlNode *y;

  y = x->left;
  x->left = y->right;
  if (y->right)
    y->right->parent = x;

  y->parent = x->parent;
  if (!x->parent)
    *root = y; // root is now y

  else if (x == x->parent->right)
      x->parent->right = y;
  else
      x->parent->left = y;

  y->right = x;
  x->parent = y;
}

/* Inserts n into avl */
void avl_insert(AvlNode **root, AvlNode *n) {
  AvlNode *parent_ptr, *child_ptr = NULL; // iterator and parent
  
  child_ptr = *root;
  while (child_ptr) {
    parent_ptr = child_ptr; // maintain a ptr to parent
    
    // traverse and inc. size of visited avlnodes
    if (child_ptr->key > n->key) {
      child_ptr->size++;
      child_ptr = child_ptr->left;
    }
    else {
      child_ptr->size++;
      child_ptr = child_ptr->right;
    } 
  }
  
  n->parent = parent_ptr;
  if (!parent_ptr) // tree was empty
    *root = n;
  else if (parent_ptr->key > n->key)
    parent_ptr->left = n;
  else
    parent_ptr->right = n;
}

/* deletes a AvlNode n from tree and returns it, returns
 * bad_avl_node_ptr if n DNE. in tree. */
AvlNode *avl_delete(AvlNode **root, AvlNode *n) {
  AvlNode *successor, *child, *current;
  int tmp;

  if (!n->left || !n->right) { // base case
    // fix pointers
    if ((child = n->left? n->left: n->right)) {
      child->parent = n->parent;
    }

    if (!n->parent) {
      *root = child;
    }
    else if (n == n->parent->left) {
      n->parent->left = child;
    }
    else {
      n->parent->right = child;
    }

    // while trace to route dec. sizes of visited
    while ((current = current->parent)) {
      current->size--;
    }

    return n;
  }

  // exchange keys and recurse
  successor = avl_successor(n);
  tmp = n->key;
  n->key = successor->key;
  successor->key = tmp;

  return avl_delete(root, successor);
}

/* Returns the number keys <= t in given tree */
int avl_rank(AvlNode *root, int t) {
  if (!root)
    return 0;
  if (t == root->key)
    return root->left? root->left->size + 1: 1;
  if (t > root->key)
    return root->left? \
      root->left->size + avl_rank(root->right, t) + 1: \
      avl_rank(root->right, t) + 1;
  else
    return avl_rank(root->left, t);
}

#include <stdio.h> // for printing
#include "avl-utils.h"

#endif
