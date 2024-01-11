#include <stdio.h>

void merge(int arr[], int p, int q, int r)
{
	int nl = q - p + 1;
	int nr = r - q;
	int L[nl], R[nr];

	for (int i = 0; i < nl; ++i) {
		L[i] = arr[p + i];
	}
	for (int j = 0; j < nr; ++j) {
		R[j] = arr[q + 1 + j];
	}

	int i, j, k;
	i = j = 0;
	k = p;

	while (i < nl && j < nr) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/* add remainder */
	while (i < nl) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < nr) {
		arr[k] = R[j];
		j++;
		k++;
	}
}


void mergeSort(int arr[], int p, int r)
{
	if (p < r) {
		int q = (p + r)  / 2;

		mergeSort(arr, p, q);
		mergeSort(arr, q + 1, r);
		merge(arr, p, q, r);
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

	printf("Unsorted array\n");
	printArray(arr, n);

	printf("\n");
	mergeSort(arr, 0, n - 1);

	printf("Sorted array\n");
	printArray(arr, n);

	return 0;
}














