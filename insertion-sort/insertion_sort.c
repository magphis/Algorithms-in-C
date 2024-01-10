#include <stdio.h>

void insertionSort(int arr[], int n)
{
	int i, j, key;

	for (j = 1; j < n; ++j) {
		key = arr[j];
		i = j - 1;
		while (i >= 0 && arr[i] > key) {
			arr[i + 1] = arr[i];
			--i;
		}
		arr[i + 1] = key;
	}
}

void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int arr[] = {12, 3, 6, 1, 9, 10};
	int n = sizeof(arr) / sizeof(arr[0]);

	printf("Before sorting\n");
	printArray(arr, n);
	printf("\nAfter sorting\n");
	insertionSort(arr, n);
	printArray(arr, n);

	return 0;
}
