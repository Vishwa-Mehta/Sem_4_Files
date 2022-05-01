#include <stdio.h>

void display(int a[], int n){
	for(int i =0; i< n;i++)
		printf("%d\t", a[i]);
	printf("\n");
}

void merge(int a[], int low, int mid, int high) {
	int i,j,k;
	int temp[20];
	k = low;
	i = low;
	j = mid+1;
	while(i <= mid && j <= mid) {
		if (a[i] <= a[j])
			temp[k++] = a[i++];
		else
			temp[k++]=a[j++];
	}
	while(i<=mid)
		temp[k++] = a[i++];
	
	while(j<=high)
		temp[k++] = a[j++];

	for (k=low; k<= high; k++)
		a[k] = temp[k];
}

void mergesort(int a[], int high, int low) {
	int mid;
	if (low < high) {
		mid = (low+high)/2;
		mergesort(a,low,mid);
		mergesort(a,mid+1,high);
		merge(a,low,mid,high);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	int a[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int low = 0;
	int high = n - 1;
	mergesort(a,low,high);
	display(a,n);
	return 0;
}
