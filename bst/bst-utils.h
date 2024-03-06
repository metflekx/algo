/* BSTutils.h
 * Binary Tree Search utilities
 * Author: Metflekx
 */

// tree-walks
#define INORDER 0
#define PREORDER 1
#define POSTORDER 2

// directions
#define DIR_RIGHT 0
#define DIR_LEFT 1

void print_trace_root(Node *);
void print_trace_leaf(Node *, int);
void print_bt(Node *, int);

void print_trace_root(Node *n) {
  while (n != NULL) {
    printf("%i -> ", n->key);
    n = n->parent;
  }
  printf("Null\n");
}

void print_trace_leaf(Node *n, int direction) {
  if (direction == DIR_RIGHT) {
    while (n != NULL) {
      printf("%i -> ", n->key);
      n = n->right;
    }
  }
  else if (direction == DIR_LEFT) {
    while (n != NULL) {
      printf("%i -> ", n->key);
      n = n->left;
    }
  }
  printf("Null\n");
}

void print_bt(Node *root, int tree_walk) {
  if (tree_walk == INORDER) { // inorder tree walk
    if (root->left) print_bt(root->left, INORDER);
    printf("%i, ", root->key);
    if (root->right) print_bt(root->right, INORDER);
  }
  if (tree_walk == PREORDER) { // pre-order tree walk
    printf("%i, ", root->key);
    if (root->left) print_bt(root->left, PREORDER);
    if (root->right) print_bt(root->right, PREORDER);
  }
  if (tree_walk == POSTORDER) { // post-order tree walk
    if (root->left) print_bt(root->left, POSTORDER);
    if (root->right) print_bt(root->right, POSTORDER);
    printf("%i, ", root->key);
  }
  else {
    printf("Error: arg %i is not a valid tree_walk\n", tree_walk);
  }
}
