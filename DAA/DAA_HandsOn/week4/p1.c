//array of n integers in the range 0 to 2n-1
//search function to report no. of comparisions
//search array for random inputs m times and try to arrive at an avg case comparision
//rand() ; n = 1000; range = 0 - 1999

#include <stdio.h>
#include <stdlib.h>
int* gen_array(int n, int a[]) {
	for (int i = 0; i < n; i++) {
		a[i] = rand()%(2*n);
	}
	return a;
}
int linearSearch(int a[], int key, int n, int *count) {
	for (int i = 0; i < n; i++) {
		if (a[i] == key) {
			count++;
			return i;
		}
	}
	return -1;
}
int main() {
	int n;
	int m;
	int result;
	int count;
	printf("enter n and m: ");
	scanf("%d %d", &n, &m);
	int a[n];
	gen_array(n, a);
	int key;
	for (int i = 0; i < m; i++) {
		count = 0;
		key = rand()%(2*n);
		result = linearSearch(a, key, n, &count);
		if (result == -1) {
			printf("%d is not found after %d comparisions :(\n", key, count);
		}
		else {
			printf("%d is found at position %d after %d comparisions :)\n", key, result, count);
		}
	}
	return 0;
}
