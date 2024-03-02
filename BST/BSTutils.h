/* BSTutils.h
 * Binary Tree Search utilities
 * Author: Metflekx
 */

#define INORDER 0
#define PREORDER 1
#define POSTORDER 2


void printBT(Node *root, int tree_walk);

void printBT(Node *root, int tree_walk) {
  if (tree_walk == INORDER) { // inorder tree walk
    if (root->left) printBT(root->left, INORDER);
    printf("%i, ", root->key);
    if (root->right) printBT(root->right, INORDER);
  }
  if (tree_walk == PREORDER) { // pre-order tree walk
    printf("%i, ", root->key);
    if (root->left) printBT(root->left, PREORDER);
    if (root->right) printBT(root->right, PREORDER);
  }
  if (tree_walk == POSTORDER) { // post-order tree walk
    if (root->left) printBT(root->left, POSTORDER);
    if (root->right) printBT(root->right, POSTORDER);
    printf("%i, ", root->key);
  }
  else {
    printf("Error: arg %i is not a valid tree_walk\n", tree_walk);
  }
}
