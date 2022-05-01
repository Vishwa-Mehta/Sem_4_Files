#include <stdio.h>
#include <stdlib.h>
#include <time.h>
double time_elapsed(struct timespec start, struct timespec end) {
  double t;
  t = (end.tv_sec - start.tv_sec);
  t += (end.tv_nsec - start.tv_nsec) * 0.000000001;
  return t;
}
int SequentialSearch2(int a[], int k, int n) {
    int i = 0;
	a[n] = k;
    while (a[i] != k) {
        i++;
    }
    if (i < n) {
        return i;
    }
    else {
        return -1;
    }
}

int main() {
	struct timespec start;
	struct timespec end;
	clock_gettime(CLOCK_REALTIME, &start);
	int n;
	n = 1000000;
	printf("%d", n);
    int a[n];
	for (int i = 0; i < n; i++) {
		a[i] = rand();
	}
    int k = rand();
	clock_gettime(CLOCK_REALTIME, &end);
    printf("%lf\n", time_elapsed(start, end));

	// printf("index of element is : %d\n", SequentialSearch2(a,k,7));
    return 0;
}
