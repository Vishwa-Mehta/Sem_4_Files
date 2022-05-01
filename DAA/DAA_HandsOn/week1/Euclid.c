#include <stdio.h>
int GCD(int m, int n) {
	int r = 0;
	while (n != 0) {
		r = m % n;
		m = n;
		n = r;
	}
	return m;
}
int main() {
	int m = 60;
	int n = 24;
	printf("GCD(%d,%d) = %d\n", m, n, GCD(m,n));
	return 0;
}
