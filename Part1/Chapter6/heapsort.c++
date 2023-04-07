#include<iostream>
#include<cmath>

using namespace std;

// max-heap -> parent > children
// min-heap -> parent < children

inline void parent(int i) {
    return floor(i/2);
}

inline void left(int i) {
    return 2*i;
}

inline void right(int i) {
    return 2*i + 1;
}

/*
inputs -> an array A and an index i int o the array
When it's called, max-heapify assumes that the binary trees rooted as left(i) and right(i) are max-heaps, but that A[i] might be smaller than its children, thus violating the max-heap proeprty. Max-hpeaify lets the value at A[i] "float down" in the max-heap so that the subtree rooted at index i obeys the max-heap property.
*/
void max_heapify(int a[], int i) {
    int heap_size = sizeof(a) / sizeof(a[0]);
    int l = left(i);
    int r = right(i);
    int largest;

    if (l <= heap_size && A[l] > A[i])
        largest = l
    else
        largest = i

    if (r <= heap_size && A[r] > A[largest])
        largest = r

    if (largest != i) {
        swap(a, i, largest);
        max_heapify(a, largest)
    }
}

void swap(int a[], int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void build_max_heap(int[] a) {
    int heap_size = sizeof(a) / sizeof(a[0]);
    for (int i = floor(heap_size/2); i >= 1; --i)
        max_heapify(a, i);
}

void heapsort(int[] a) {
    int heap_size = sizeof(a) / sizeof(a[0]);
    build_max_heap(a);
    for (int i = heap_size; i >= 2; --i) {
        swap(a, 1, i);
        heap_size -= 1;
        max_heapify(a, 1);
    }
}

void heap_maximum(int[] a) {
    return a[1];
}

void heap_extract_max(int[] a) {
    int heap_size = sizeof(a) / sizeof(a[0]);

    if heap_size < 1
        return;

    max = a[1];

    a[1] = a[heap_size-1];
    a.heap_size -= 1;
    max_heapify(a, 1);

    return max;
}

void heap_increase_key(int [], int i, int key) {
    A[i] = key

    // key increased, we must go upwards to rebuild the heap properly
    while(i > 1 and a[parent(i)] < a[i]) {
        swap(a, i, parent(i));
        i = parent(i);
    }
}

void max_heap_insert(int[] a, int key) {
    int heap_size = sizeof(a) / sizeof(a[0]);

    a[heap_size] = -INFINITY;
    heap_increase_key(a, heap_size, key);
}
