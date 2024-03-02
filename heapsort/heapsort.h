/* heapsort.h: Heap and Heapsort implementation.
 * Author: Metflex
 * An implementation according to the following book
 * MIT's "Introduction to Algorithms"
 */

#ifndef HEAPSORT_H
#define HEAPSORT_H

#define LEFT(i) (i * 2) + 1
#define RIGHT(i) (i * 2) + 2

int heapsize;

void maxHeapify(int [], int);
void buildHeap(int [], int);
void heapSort(int [], int);

/* makes sure parrent node is greater than it's children */
void maxHeapify(int a[], int i) {
  int l, r, max, tmp;

  l = LEFT(i);
  r = RIGHT(i);
  
  max = (l <= heapsize && a[l] > a[i])? l: i;
  max = (r <= heapsize && a[r] > a[max])? r: max;

  if (max != i) {
    tmp = a[i];
    a[i] = a[max];
    a[max] = tmp; 

    maxHeapify(a, max);
  }
}

/* builds a max-heap in a */
void buildHeap(int a[], int len) {
  int i;
  heapsize = len - 1;
  for (i = len / 2 - 1; i >= 0; i--)
    maxHeapify(a, i);
}

/* sorts an array of integers using a heap */
void heapSort(int a[], int len) {
  int i, tmp;

  buildHeap(a, len);

  for (i = len - 1; i > 0; i--) {
    tmp = a[i];
    a[i] = a[0];
    a[0] = tmp;

    heapsize --;

    maxHeapify(a, 0);
  }
}

#endif
