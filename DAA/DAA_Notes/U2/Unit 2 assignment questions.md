### Brute force:
1. array comparisions in linear search
2. compute the value of a polynomial at a given point x0 and determine its worst case efficiency class. 
	p(x) = a,n * x^n + a,n-1 * x^(n-1) +.....+ a,1 * x + a,0
3. How many comparisions will be made in searching for each of hte following patterns in the binary text of one thousand zeros?
i) 00001
ii) 10000
iii) 01010
no of substrings = n - m + 1
	- compute the no of comparisions
	- verify using program

### Decrease and conquer:
1. implement insertion sort
2. insertion sort on array a[0...n] with a[0] being a free slot and the array elsments are in pos 1 to n (use sentinel)
3. min a[0 ... n-1] move it to the 0th position then use selsection sort. would this min val act as a sentinel? is this stable?
4. implement topological sort (any one of the algo)

------------------------------------------------------------------------
Algorithm PolynomialEval(P[0...n], x)
```C
// computes value of polynomial at a given point x
p <- 0.0
for i <- n down to 0 do
	power <- 1
	for j <- 1 to i do
		power <- power * x
	p <- p + P[i] * power
```