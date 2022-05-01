### Bubble Sort:
#### Idea:
- Compare adjacent elements -> swap if they're out of order
- bubble the larger elements to the end of the list
#### Algorithm:
```C
ALGORITHM BubbleSort(A[0..n - 1])
//Sorts a given array by bubble sort in their final positions
//Input: An array A[0..n - 1] of orderable elements
//Output: Array A[0 .. n- 1] sorted in ascending order
for i <- 0 to n - 2 do
	for j <- 0 to n - 2 - i do
		if A[j + 1] < A[j]
			swap A[j] and A[j + 1]
```
#### Analysis:
- Main Operation: Comparision
- Input Size: n
![[Pasted image 20220209083730.png]]
#### Example:
1. 89 45 68 90 29 34 17
	**45 89** 68 90 29 34 17 : swap = 1
	45 **68 89** 90 29 34 17 : swap = 2
	45 68 89 90 29 34 17
	45 68 89 **29 90** 34 17 : swap = 3
	45 68 89 29 **34 90** 17 : swap = 4
	45 68 89 29 34 **17 90** : swap = 5

	45 68 89 29 34 17 90
	45 68 89 29 34 17 90
	45 68 **29 89** 34 17 90 : swap = 6
	45 68 29 **34 89** 17 90 : swap = 7
	45 68 29 34 **17 89** 90 : swap = 8
	45 68 29 34 17 89 90

	45 68 29 34 17 89 90
	45 **29 68** 34 17 89 90 : swap = 9
	45 29 **34 68** 17 89 90 : swap = 10
	45 29 34 **17 68** 89 90 : swap = 11
	45 29 34 17 68 89 90
	45 29 34 17 68 89 90

	**29 45** 34 17 68 89 90 : swap = 12
	29 **34 45** 17 68 89 90 : swap = 13
	29 34 **17 45** 68 89 90 : swap = 14
	29 34 17 45 68 89 90
	29 34 17 45 68 89 90
	29 34 17 45 68 89 90

	29 34 17 45 68 89 90
	29 **17 34** 45 68 89 90 : swap = 15
	29 17 34 45 68 89 90
	29 17 34 45 68 89 90
	29 17 34 45 68 89 90
	29 17 34 45 68 89 90

	**17 29** 34 45 68 89 90 : swap = 16
	17 29 34 45 68 89 90
	17 29 34 45 68 89 90
	17 29 34 45 68 89 90
	17 29 34 45 68 89 90
	17 29 34 45 68 89 90
	
	- Swaps = order(n<sup>2</sup>)
	- Sorting is Stable
	- Algorithm is said to be **in-place** if it doesn't require extra memory except possibly for few more memory units
##### Sequential Search (Done before)
### String Matching:
- Pattern : string to be searched
- Text : entire string to be searched in 
- Problem : find pattern in text
#### Idea:
- Align the pattern at starting of the text
- Move left to right and compare each character of the pattern to the text till *all characters match* or till we *find a mismatch*
- Repeat till text is not exhausted and pattern not found
#### Algorithm:
```C
ALGORITHM BruteForceStringMatch(T[0..n -1], P[0..m -1])
//Implements brute-force string matching
//Input: An array T[0..n - 1] of n characters representing a text
//and an array P[0..m - 1] of m characters representing a pattern
//Output: The index of the first character in the text that starts a
//matching substring or -1 if the search is unsuccessful
for i <- 0 to n-m do
	j <- 0
	while j < m and P[j] = T[i + j] do
		j <- j+1
	if j = m 
		return i
return -1
```
#### Worst Case:
- O(nm)
#### Code:
```C
//first occurrence only
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
```
```C
//multiple occurrences
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
        int count = 0;
        for (int i = 0; i < n; i++) {
                int j = 0;
                while (j < m && pat[j] == text[i + j]) {
                        j++;
                }
                if (j == m) {
                        printf("pattern found in text at index: %d\n", i);
                        count++;
                }
        }
        if (count == 0) {
                printf("pattern not found in text. :(\n");
        }
        return 0;
}
```
### Travelling Salesman Problem:
- Exhaustive Search: 
	- generating each and every element of the problem domain -> selecting those that satisfy all the constraints -> finding a desired element
#### Idea:
- n cities
- possible number of paths: (n - 1)!
- find shortest path to cover all cites without visitng a city more than once.
- find all paths -> remove least optimal paths
- not efficient for large n values
- Example for an **NP Hard Problem** -> no polynomial solution for it.
- **Hamiltonian Circuit : a cycle that passes through a city only once.**
