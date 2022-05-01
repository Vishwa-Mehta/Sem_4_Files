#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 50
int main() {
	char text[MAX], pat[MAX];
	printf("enter the text: ");
	scanf("%[^\n]s", text);
	printf("enter the pattern: ");
	scanf("%s", pat);
	int n = strlen(text);
	int m = strlen(pat);
	for (int i = 0; i < n; i++) {
		int j = 0;
		while (j < m && pat[j] == text[i + j]) {
			j++;
		}
		if (j == m) {
			printf("pattern found in text at index: %d\n", i);
			exit(0);
		}
	}
	printf("pattern not found in text. :(\n");
	return 0;
}
