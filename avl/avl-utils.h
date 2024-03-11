/* avl-utils.h
 * Self Balancing Binary Tree Search utilities
 * Author: Metflekx
 */

// tree-walks
#ifndef INORDER 
#define INORDER 0 
#endif
#ifndef PREORDER 
#define PREORDER 1
#endif
#ifndef POSTORDER 
#define POSTORDER 2
#endif

// directions
#ifndef DIR_RIGHT
#endif
#define DIR_RIGHT 0

#ifndef DIR_LEFT
#define DIR_LEFT 1
#endif

#ifndef VERBOSE
#define NOVERBOSE 0
#endif

#ifndef VERBOSE
#define VERBOSE 1
#endif

void avl_print_trace_root(AvlNode *n, int verbose);
void avl_print_trace_leaf(AvlNode *n, int direction, int verbose);
void avl_print(AvlNode *root, int tree_walk, int verbose);

void avl_print_trace_root(AvlNode *n, int verbose) {
  while (n != NULL) {
    printf("%i -> ", n->key);
    n = n->parent;
  }
  printf("Null\n");
}

void avl_print_trace_leaf(AvlNode *n, int direction, int verbose) {
  if (direction == DIR_RIGHT) {
    while (n != NULL) {
      if(verbose) {
        printf("<[%i](%i)>, ", n->key, n->size);
      }
      else {
        printf("%i, ", n->key);
      }
      n = n->right;
    }
  }
  else if (direction == DIR_LEFT) {
    while (n != NULL) {
      if(verbose) {
        printf("<[%i](%i)>, ", n->key, n->size);
      }
      else {
        printf("%i, ", n->key);
      }
      n = n->left;
    }
  }
  printf("Null\n");
}

void avl_print(AvlNode *root, int tree_walk, int verbose) {
  if (tree_walk == INORDER) { // inorder tree walk
    // walk
    if (root->left) avl_print(root->left, tree_walk, verbose);
    // print
    if(verbose) {
      printf("<[%i](%i)>, ", root->key, root->size);
    }
    else {
      printf("%i, ", root->key);
    }
    if (root->right) avl_print(root->right, tree_walk, verbose);
  }
  if (tree_walk == PREORDER) { // pre-order tree walk
    // print
    if(verbose) {
      printf("<[%i](%i)>, ", root->key, root->size);
    }
    else {
      printf("%i, ", root->key);
    }
    // walk 
    if (root->left) avl_print(root->left, tree_walk, verbose);
    if (root->right) avl_print(root->right, tree_walk, verbose);
  }
  if (tree_walk == POSTORDER) { // post-order tree walk
    // walk 
    if (root->left) avl_print(root->left, tree_walk, verbose);
    if (root->right) avl_print(root->right, tree_walk, verbose);
    // print
    if(verbose) {
      printf("<[%i](%i)>, ", root->key, root->size);
    }
    else {
      printf("%i, ", root->key);
    }
  }
}
