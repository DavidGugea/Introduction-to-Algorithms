void insertion_sort(int[] a, int n) {
    for (int j = 2; j < n; ++j) {
        int key = A[j];

        i = j - 1;

        while( i > 0 && A[i] > key) {
            a[i+1] = A[i]
            i -= 1
        }

        A[i+1] = key;
    }
}