# Brute Force:
-> Slow for very high value of 'n'
-> Straight forward approach to solving a problem 
-> Directly based on problem statement and definition involved
-> One of the easiest method to apply
-> Brute force search AKA **Exhaustive Search**.
	-> enumerates all possible candidates for solutions.
-> Ex:
- Brute force method to find divisors for a natural number 'n' will be:
	- enumerate all numbers from 1 - n
	- check wether each of them divides n without a ramainder.
- 8 queens puzzle:
	- examine all enumerations (possibilities) of the 8 queens
	- (8x8)<sup>8</sup> possibilities, very inefficient
- Brute force search -> linear search
-> Used when:
- Problem size is limited
-> Brute forse SORTING ALGORITHMS: 
O(n<sup>2</sup>)
- Selection Sort
- Bubble Sort
### Selection Sort:
#### Idea:
- Scan the array -> find its smallest element -> swap it with the first element
- Starting with second element -> scan the elements to the right of it -> find
the smallest among them -> swap it with the second element
#### Algorithm:
```c
ALGORITHM Selection Sort(A[0...n-1])
// Sorts a given array by selection sort
// Input: array of sortable elements A[0...n-1]
// Output: array of sorted elements in ascending order
for i <- 0 to n - 2 do
	min <- i
	for j <- i + 1 to n - 1 do
		if A[j] < A[min]
			min <- j
	swap A[i] and A[min]
```
#### Analysis:
- Main operation: Comparision
- Input size: n
![[Pasted image 20220208085933.png]]
(n-1) - (i+1) - 1 = (n - 1 - i) = n(n-2 - 0 + 1) - (n - 2 - 0 + 1) - ((n - 2)<sup>2</sup> / 2) = n<sup>2</sup> - n - n + 1 -     n<sup>2</sup>/2 + 2n + 1 = n<sup>2</sup>/2 + 2
#### Example:
1. 8,4,6,9,2,3,1
	1 4 6 9 2 3 8 : swap = 1
	1 2 6 9 4 3 8 : swap = 2
	1 2 3 9 4 6 8 : swap = 3
	1 2 3 4 9 6 8 : swap = 4
	1 2 3 4 6 9 8 : swap = 5
	1 2 3 4 6 8 9 : swap = 6
	Total Swaps = 6
- Sorting algorithm is stable if it preserves the positions/order of the original (equal) elements
- Swaps = order(n)
2. 8,4,6,6,2,3,1 (repeating elements)