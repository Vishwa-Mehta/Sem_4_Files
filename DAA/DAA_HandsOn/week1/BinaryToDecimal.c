#include <stdio.h>
#include <math.h>
int BinToDec(int n) {
	int d = 0;
	int dec = 0;
	double i = 0;
	while (n > 0) {
		d = n % 10;
		dec = dec + d*(pow(2.0, i));
		n = n / 10;
		i++;
	}
	return dec;
}
int main() {
	int n;
	printf("enter n: ");
	scanf("%d", &n);
	printf("decimal of %d is : %d\n", n, BinToDec(n));
	return 0;
}
