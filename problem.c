#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int strength; // Number of soldiers in the row
    int index;    // Row index
} RowStrength;

void swap(RowStrength* a, RowStrength* b) {
    RowStrength temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(RowStrength* heap, int size, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left].strength < heap[smallest].strength)
        smallest = left;

    if (right < size && heap[right].strength < heap[smallest].strength)
        smallest = right;

    if (smallest != index) {
        swap(&heap[index], &heap[smallest]);
        minHeapify(heap, size, smallest);
    }
}

void insert(RowStrength* heap, int size, RowStrength value) {
    int i = size;
    heap[size] = value;

    while (i > 0 && heap[i].strength > heap[(i - 1) / 2].strength) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int* kWeakestRows(int** mat, int matSize, int* matColSize, int k, int* returnSize) {
    RowStrength* heap = (RowStrength*)malloc(matSize * sizeof(RowStrength));
    int size = 0;

    for (int i = 0; i < matSize; i++) {
        int strength = 0;
        for (int j = 0; j < matColSize[i]; j++) {
            strength += mat[i][j];
        }
        if (size < k) {
            insert(heap, size, (RowStrength){strength, i});
            size++;
        } else if (strength < heap[0].strength) {
            heap[0] = (RowStrength){strength, i};
            minHeapify(heap, k, 0);
        }
    }

    int* result = (int*)malloc(k * sizeof(int));
    for (int i = k - 1; i >= 0; i--) {
        result[i] = heap[0].index;
        swap(&heap[0], &heap[i]);
        minHeapify(heap, i, 0);
    }

    *returnSize = k;
    free(heap);

    return result;
}

int main() {
    int matSize = 5;
    int matColSize[] = {5, 5, 5, 5, 5};
    int k = 3;
    int* returnSize = (int*)malloc(sizeof(int));
    int* result;

    int mat[5][5] = {
        {1, 1, 0, 0, 0},
        {1, 1, 1, 1, 0},
        {1, 0, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {1, 1, 1, 1, 1}
    };

    int** matArray = (int**)malloc(matSize * sizeof(int*));
    for (int i = 0; i < matSize; i++) {
        matArray[i] = (int*)malloc(matColSize[i] * sizeof(int));
        for (int j = 0; j < matColSize[i]; j++) {
            matArray[i][j] = mat[i][j];
        }
    }

    result = kWeakestRows(matArray, matSize, matColSize, k, returnSize);

    for (int i = 0; i < k; i++) {
        printf("%d ", result[i]);
    }

    free(result);
    free(returnSize);

    return 0;
}
