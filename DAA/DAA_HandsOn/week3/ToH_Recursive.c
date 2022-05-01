#include <stdio.h>
#include <stdlib.h>

int count;

void toh(int n, int A, int B, int C) {
	if (n == 1) {
		count = count + 1;
        // printf("move disk from %d to %d.\n", A, C);
    }
	else {
        toh(n - 1, A, C, B);
        toh(1, A, B, C);
        toh(n - 1, B, A, C);
    }
}

int main() {
    int n;
    printf("enter number of disks: ");
    scanf("%d", &n);
    int A = 1;
    int B = 2;
    int C = 3;
    toh(n, A, B, C);
    printf("total count is %d\n", count);
    return 0;
}
