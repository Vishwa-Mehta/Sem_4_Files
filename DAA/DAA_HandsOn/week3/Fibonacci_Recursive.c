#include <stdio.h>
int Fib(int n) {
	if (n == 1) {
		return 1;
	}
	else if (n == 0) {
		return 0;
	}
	else {
		return Fib(n - 1) + Fib(n - 2);
	}
}
int main() {
	int n;
	printf("enter n: ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		printf("%d\t", Fib(i));
	}
	printf("\n");
	return 0;
}
