/* Lab Program 2
   Sort a set of n integers using quick sort and measure the time taken for
   increasing values of n on random input. Print an n vs time table; quick sort
   averages O(n log n). */
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

// partition around a random pivot (Lomuto) so sorted input is not the worst case
int partition(int a[], int lo, int hi)
{
    int p = lo + rand() % (hi - lo + 1);
    int t = a[p]; a[p] = a[hi]; a[hi] = t;
    int pivot = a[hi], i = lo - 1;
    for (int j = lo; j < hi; j++)
        if (a[j] < pivot) {
            i++;
            t = a[i]; a[i] = a[j]; a[j] = t;
        }
    t = a[i+1]; a[i+1] = a[hi]; a[hi] = t;
    return i + 1;
}

void quickSort(int a[], int lo, int hi)
{
    if (lo < hi) {
        int p = partition(a, lo, hi);
        quickSort(a, lo, p-1);
        quickSort(a, p+1, hi);
    }
}

int main()
{
    srand(time(0));

    int demo[] = {29, 10, 14, 37, 13, 5};
    cout << "before: ";
    for (int i = 0; i < 6; i++) cout << demo[i] << " ";
    quickSort(demo, 0, 5);
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
        quickSort(a, 0, n-1);
        clock_t end = clock();
        double ms = (double)(end - start) / CLOCKS_PER_SEC * 1000;

        cout << setw(9) << n << setw(12) << fixed << setprecision(2) << ms << "\n";
        delete[] a;
    }
    return 0;
}
