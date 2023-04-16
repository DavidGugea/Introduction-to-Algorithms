#include <iostream>
#include <vector>

using namespace std;

void merge(int A[], int begin, int end, int middle) {
	int left_array_size = middle-begin + 1;
	int right_array_size = end-middle;

	int left_array[left_array_size];
	int right_array[right_array_size];

	for (int i = 0; i < left_array_size; ++i) {
		left_array[i] = A[begin+i];
	}

	for (int j = 0; j < right_array_size; ++j) {
		right_array[j] = A[middle+j+1];
	}

	int l_merge_index = 0;
	int r_merge_index = 0;
	int org_merge_index = begin;

	while (l_merge_index < left_array_size && r_merge_index < right_array_size) {
		if (left_array[l_merge_index] < right_array[r_merge_index]) {
			A[org_merge_index] = left_array[l_merge_index];
			l_merge_index++;
		} else {
			A[org_merge_index] = right_array[r_merge_index];
			r_merge_index++;
		}

		org_merge_index++;
	}

	while (l_merge_index < left_array_size) {
		A[org_merge_index] = left_array[l_merge_index];
		l_merge_index++;
		org_merge_index++;
	}

	while (r_merge_index < right_array_size) {
		A[org_merge_index] = right_array[r_merge_index];
		r_merge_index++;
		org_merge_index++;
	}
}

void mergeSort(int A[], int begin, int end) {
	if (begin >= end)
		return;

	int middle = begin + (end-begin) / 2;

	mergeSort(A, begin, middle);
	mergeSort(A, middle+1, end);

	merge(A, begin, end, middle);
}

void printArray(int A[], int size) {
	for (int i = 0 ; i < size; ++i) {
		cout << A[i] << " - ";
	}

	cout << "\n";
}

int main() {
	int arr[] = { 12, 11, 13, 5, 6, 7};
	int arr_size = sizeof(arr)/sizeof(arr[0]);

	printArray(arr, arr_size);
	mergeSort(arr, 0, arr_size - 1);
	printArray(arr, arr_size);

	return 0;
}
