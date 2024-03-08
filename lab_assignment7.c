// lab_assignment7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>

void swap(int* arr, int x, int y) {
	int temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}

void copy(int* x, int* y, int n) {
	for (int i = 0; i < n; i++) {
		y[i] = x[i];
	}
}

void bubbleSort(int arr[], int n)
{
	int i, j, totalSwaps = 0;
	int copiedArr[9];
	int swapsArr[9] = { 0,0,0,0,0,0,0,0,0 };

	copy(arr, copiedArr, n);
	
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (copiedArr[j] > copiedArr[j + 1])
			{
				swapsArr[j]++;
				swapsArr[j + 1]++;
				
				swap(copiedArr, j, j + 1);
				swap(swapsArr, j, j+1);
				totalSwaps++;
			}
		}
	}
	for (i = 0; i < n; i++) {
		printf("%d: %d\n", copiedArr[i], swapsArr[i]);
	}
	printf("%d", totalSwaps);
}

void selectionSort(int arr[], int n)
{
	int i, j, min, totalSwaps = 0;
	int copiedArr[9];
	int swapsArr[9] = { 0,0,0,0,0,0,0,0,0 };

	copy(arr, copiedArr, n);

	for (i = 0; i < n - 1; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)
			if (copiedArr[j] < copiedArr[min])
				min = j;
		
		if (i != min) {
			swapsArr[i]++;
			swapsArr[min]++;

			swap(copiedArr, i, min);
			swap(swapsArr, i, min);
			totalSwaps++;
		}
	}

	for (i = 0; i < n; i++) {
		printf("%d: %d\n", copiedArr[i], swapsArr[i]);
	}
	printf("%d", totalSwaps);
}

int main() {
	int array1[] = { 97, 16, 45, 63, 13, 22, 7, 58, 72 };
	int array2[] = { 90, 80, 70, 60, 50, 40, 30, 20 ,10 };

	printf("array1 bubble sort:\n");
	bubbleSort(array1, 9);
	printf("\n\narray2 bubble sort:\n");
	bubbleSort(array2, 9);
	printf("\n\narray1 selection sort:\n");
	selectionSort(array1, 9);
	printf("\n\narray2 selection sort:\n");
	selectionSort(array2, 9);
}
