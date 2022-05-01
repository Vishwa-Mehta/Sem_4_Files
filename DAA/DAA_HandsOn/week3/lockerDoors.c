#include <stdio.h>
int* lockerDoors(int n, int a[]) {
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j = j + i) {
			if (a[j] == 0)
				a[j] = 1;
			else
				a[j] = 0;		
		}
	}
	return a;
}
int noOfOpenDoors(int n, int a[]) {
	int o = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == 1)
			o++;
	}
	return o;
}
int main() {
	int n;
	printf("enter number of doors: ");
	scanf("%d", &n);
	int a[] = {0};
	int *b;
    b = lockerDoors(n, a);
	int c = noOfOpenDoors(n, b);
	printf("number of doors open: %d\n", c);
	printf("number of doors closed: %d\n", n - c);
	return 0;
}
