#include <stdio.h>
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
    int a[] = {1,2,3,5,7,8,9};
    int k = 7;
    printf("index of element is : %d\n", SequentialSearch2(a,k,7));
    k = 10;
    printf("index of element is : %d\n", SequentialSearch2(a,k,7));
    return 0;
}
