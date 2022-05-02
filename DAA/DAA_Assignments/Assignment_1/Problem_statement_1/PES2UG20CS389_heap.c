// Name: Vishwa Mehul Mehta
// SRN: PES2UG20CS389
#include "heap.h"
#include <stdlib.h>

/*
 ** Do not use global variables.
 ** Mark any functions that you declare in this file that are not in the header
 *as static
 ** Do not use static variables
 ** All occurences of count_ptr indicate that the number of comparison
 ** operations need to be stored in the location pointed by it
 ** The implementation can assume it is initialized to 0.
 */

// static funtions added : swap(), max_heapify()

// swap() used in insert()
static void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
    *y = temp;
}

// max_heapify() is the function that actually implements the heapification
static void max_heapify(heap_t *heap, int i, int size, int *count_ptr) {
	int left = 2*i + 1;
	int right = 2*i + 2;
	int largest = i;
	if (++*count_ptr && left <= size && heap -> arr[left] > heap -> arr[largest]) {
        largest = left;
    }
	if (++*count_ptr && right <= size && heap -> arr[right] > heap -> arr[largest]) {
        largest = right;
    }
	if (++*count_ptr && largest != i) {
        int temp = heap -> arr[i];
        heap -> arr[i] = heap -> arr[largest];
        heap -> arr[largest] = temp;
        max_heapify(heap, largest, size, count_ptr);
    }
}


// Initialise heap
// Set heap size to 0
// Set heap max_size to paramter max_size
// Allocate memory of max_size to the array
void init_heap(heap_t *heap, int max_size) {
	heap -> size = 0;
	heap -> max_size = max_size;
	heap -> arr = (int*)malloc((max_size)*sizeof(int));
}

// Insert element "key" to heap "heap"
// and store the number of key comparisons made in the
// location pointed to by count_ptr.
void insert(heap_t *heap, int key, int *count_ptr) {

	if (heap -> size >= heap -> max_size) {
		return;
	}
	heap -> arr[heap -> size] = key;
	heap -> size++;

	int i = heap -> size - 1;
	while (++*count_ptr && i != 0 && heap -> arr[(i - 1) / 2] < heap -> arr[i]) {
		swap(&(heap -> arr[(i - 1) / 2]), &(heap -> arr[i]));
		i = (i - 1)/ 2;
	}
}

// *Removes and Returns* the maximum element in the heap
// and store the number of key comparisons made in the
// location pointed to by count_ptr.
int extract_max(heap_t *heap, int *count_ptr) {
    int max = heap -> arr[0];
	heap -> arr[0] = heap -> arr[(heap -> size) - 1];
	heap -> size = heap -> size - 1;
	max_heapify(heap, 0, heap -> size, count_ptr);
	return max;
}

// Searches for the element key in the heap
// Returns the element if found, else -1
int search(const heap_t *heap, int key, int *count_ptr) {
	for (int i = 0; i < heap -> size; i++) {
		if (++*count_ptr && heap -> arr[i] == key) {
			return heap -> arr[i];
		}
	}
	return -1;
}

// Returns the maximum value of the element in the heap
// and store the number of key comparisons made in the
// location pointed to by count_ptr.
int find_max(const heap_t *heap, int *count_ptr) {
	*count_ptr = 0;
	return heap -> arr[0];
}

// Returns the minimum value in the heap
int find_min(const heap_t *heap, int *count_ptr) {
	int min = heap -> arr[heap -> size / 2];
	for (int i = (heap -> size / 2) + 1; i < heap -> size; i++) {
		if (++*count_ptr && heap -> arr[i] < min) {
			min = heap -> arr[i];
		}
	}
	return min;
}

// Clears the heap for reuse
void clear_heap(heap_t *heap) {
	for (int i = 0; i < heap -> max_size; i++) {
		heap -> arr[i] = 0;
	}
	heap -> size = 0;
}

// Frees all resources acquired to initialize heap
void free_heap(heap_t *heap) {
	heap -> size = 0;
	heap -> max_size = 0;
	free(heap -> arr);
}
