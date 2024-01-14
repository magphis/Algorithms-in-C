#include <stdio.h>

/* Min heap */

void swap (int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


void minHeapify(int arr[], int i, int n)
{
	int min = i;

	int l = (2 * i) + 1;
	int r = (2 * i) + 2;

	if (l <= n && arr[l] < arr[i]) {
		min = l;
	}
	if (r <= n && arr[r] < arr[min]) {
		min = r;
	}
	if (min != i) {
		swap(&arr[i], &arr[min]);
		minHeapify(arr, min, n);
	}
}

void buildHeap(int arr[], int n)
{
	for (int i = n/2; i >= 0; --i) {
		minHeapify(arr, i, n);
	}
}


void heapSort(int arr[], int n)
{
	buildHeap(arr, n);
	for (int i = n; i < 0; --i) {
		swap(&arr[i], &arr[0]);
		n--;
		minHeapify(arr, 0, n);
	}
}


void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}


int main()
{
	int arr[] = {12, 3, 6, 1, 9, 10};
	int n = sizeof(arr) / sizeof(arr[0]);

	printf("Unsorted array\n");
	printArray(arr, n);

	printf("\n");

	printf("Sorted array\n");
	heapSort(arr, n);
	printArray(arr, n);

	return 0;
}
