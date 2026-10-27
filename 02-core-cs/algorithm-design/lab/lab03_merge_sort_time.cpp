/* Lab Program 3
   Sort a set of n integers using merge sort and measure the time taken for
   increasing values of n on random input. Print an n vs time table.
   merge sort  T(n) = 2T(n/2) + n  => O(n log n) */
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

int tmp[1000000];

void merge(int a[], int lo, int mid, int hi)
{
    int i = lo, j = mid+1, k = lo;
    while (i <= mid && j <= hi)
        tmp[k++] = (a[i] <= a[j]) ? a[i++] : a[j++];
    while (i <= mid) tmp[k++] = a[i++];
    while (j <= hi)  tmp[k++] = a[j++];
    for (int t = lo; t <= hi; t++) a[t] = tmp[t];
}

void mergeSort(int a[], int lo, int hi)
{
    if (lo >= hi) return;
    int mid = (lo + hi) / 2;
    mergeSort(a, lo, mid);
    mergeSort(a, mid+1, hi);
    merge(a, lo, mid, hi);
}

int main()
{
    srand(time(0));

    int demo[] = {29, 10, 14, 37, 13, 5};
    cout << "before: ";
    for (int i = 0; i < 6; i++) cout << demo[i] << " ";
    mergeSort(demo, 0, 5);
    cout << "\nafter:  ";
    for (int i = 0; i < 6; i++) cout << demo[i] << " ";
    cout << "\n\n";

    int sizes[] = {10000, 50000, 100000, 500000, 1000000};
    cout << "       n     time(ms)\n";
    for (int s = 0; s < 5; s++) {
        int n = sizes[s];
        int *a = new int[n];
        for (int i = 0; i < n; i++) a[i] = rand();

        clock_t start = clock();
        mergeSort(a, 0, n-1);
        clock_t end = clock();
        double ms = (double)(end - start) / CLOCKS_PER_SEC * 1000;

        cout << setw(9) << n << setw(12) << fixed << setprecision(2) << ms << "\n";
        delete[] a;
    }
    return 0;
}
