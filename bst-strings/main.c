#include <stdio.h>
#include "bst/bst.h"

int main(void) {
  Node *root = NULL;

  root = bst_init_root("BB");
  bst_insert(&root, "AA");
  bst_insert(&root, "CC");

  bst_stdout(root, INORDER);
  printf("\n");


  printf("root: %s\n", root->key);
  left_rotate(&root, root);
  printf("root: %s\n", root->key);

  bst_stdout(root, INORDER);
  printf("\n");

  return 0;
}

/*
bst implementation software.
Author: Metflex

api: 
 ---------------------------------
  f: 
    Node *bst_make_node(int k);
  usage:
    - Creates and returns a node n.
 ---------------------------------
  f:
    void bst_insert(Node*, Node*);
  usage:
    - Inserts n into BST.
 ---------------------------------
  f:
    Node *bst_max(Node* root);
 usage:
    - Returns a ptr to the maximum 
    element in the tree.
 ---------------------------------
  f:
    Node *bst_successor(Node* n);
  usage:
    - returns node with smallest key
    greater than n, returns badnode
    if n.key is greatest in tree.
 ---------------------------------
  f:
    Node *bst_search(Node* root, int key);
  usage"
    - Returns a ptr to a node 
    with key.
 ---------------------------------
  f:
    Node *bst_min(Node* root);
  usage:
    - Returns a ptr to the minimum
    element in the tree.
 ---------------------------------
 */
