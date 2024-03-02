#include "../algo.h"
#include <stdio.h>
#include <time.h>

#define N 10
#define CEIL 1000

/* 
 * Drawing of the tree: (from the book)
 *        15
 *        /\
 *      6   18
 *     /\   /\
 *    3  7 17 20
 *   /\   \ 
 *  2  4   13
 *        /
 *       9
 */
void testBST(void) {
  Node *root = insert(15);
  root->left = insert(6);
  root->right = insert(18);
  root->left->left = insert(3);
  root->left->right = insert(7);
  root->right->left = insert(17);
  root->right->right = insert(20);
  root->left->left->left = insert(2);
  root->left->left->right = insert(4);
  root->left->right->right = insert(13);
  root->left->right->right->left = insert(9);

  Node *bst_successor = BSTsuccessor(root->right);
  if (bst_successor == (Node *)NO_MEMORY) {
    printf("Error::Failed to allocate memory for successor!\n");
  }
  else {
    printf("%d\n", bst_successor->key); // 20
  }
}

void testHeapsort(void) {
  int a[N], i; // declare

  // seed random generator
  srand(time(0));

  // populate array
  for (i = 0; i < N; i++) {
    a[i] = rand() % CEIL;
  }
  // print sorted array
  printf("unsorted ->\t");
  for (i = 0; i < N; i++)
    printf("%i, ", a[i]);
  printf("\n");

  // call sort
  heapSort(a, N);

  printf("sorted ->\t");
  // print sorted array
  for (i = 0; i < N; i++)
    printf("%i, ", a[i]);
  printf("\n");
}

int main(void) {
  testBST();
  testHeapsort();
  printf("finished testing.\n");

  return 0;
}
