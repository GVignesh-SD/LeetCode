#include <stdio.h>
#include <stdlib.h>

// Define a structure for the min-heap
typedef struct {
    int* heap;
    int size;
    int capacity;
} MinHeap;

// Function to create a new min-heap
MinHeap* createMinHeap(int capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->heap = (int*)malloc(sizeof(int) * capacity);
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

// Function to swap two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Helper function to heapify (min-heapify) a subtree with the root at given index
void minHeapify(MinHeap* heap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->heap[left] < heap->heap[smallest])
        smallest = left;

    if (right < heap->size && heap->heap[right] < heap->heap[smallest])
        smallest = right;

    if (smallest != index) {
        swap(&heap->heap[index], &heap->heap[smallest]);
        minHeapify(heap, smallest);
    }
}

// Function to insert an element into the min-heap
void insert(MinHeap* heap, int val) {
    if (heap->size == heap->capacity) {
        if (val <= heap->heap[0])
            return;
        heap->heap[0] = val;
        minHeapify(heap, 0);
    } else {
        int i = heap->size;
        heap->size++;
        heap->heap[i] = val;
        while (i > 0 && heap->heap[i] < heap->heap[(i - 1) / 2]) {
            swap(&heap->heap[i], &heap->heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }
}

// KthLargest structure
typedef struct {
    int k;
    MinHeap* minHeap;
} KthLargest;

KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    KthLargest* obj = (KthLargest*)malloc(sizeof(KthLargest));
    obj->k = k;
    obj->minHeap = createMinHeap(k);

    // Insert the initial values from nums into the min-heap
    for (int i = 0; i < numsSize; i++) {
        insert(obj->minHeap, nums[i]);
    }

    return obj;
}

int kthLargestAdd(KthLargest* obj, int val) {
    insert(obj->minHeap, val);
    return obj->minHeap->heap[0];
}

void kthLargestFree(KthLargest* obj) {
    free(obj->minHeap->heap);
    free(obj->minHeap);
    free(obj);
}

int main() {
    int k = 3;
    int nums[] = {4, 5, 8, 2};
    int numsSize = 4;

    KthLargest* obj = kthLargestCreate(k, nums, numsSize);
    printf("%d\n", kthLargestAdd(obj, 3));   // return 4
    printf("%d\n", kthLargestAdd(obj, 5));   // return 5
    printf("%d\n", kthLargestAdd(obj, 10));  // return 5
    printf("%d\n", kthLargestAdd(obj, 9));   // return 8
    printf("%d\n", kthLargestAdd(obj, 4));   // return 8

    kthLargestFree(obj);
    return 0;
}
