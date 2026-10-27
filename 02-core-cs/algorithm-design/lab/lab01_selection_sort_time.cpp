/* Lab Program 1
   Sort a set of n integers using selection sort and measure the time taken for
   increasing values of n on random input. Print an n vs time table so the
   O(n^2) order of growth shows. */
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

void selectionSort(int a[], int n)
{
    for (int i = 0; i < n-1; i++) {
        int minPos = i;
        for (int j = i+1; j < n; j++)
            if (a[j] < a[minPos])
                minPos = j;
        int t = a[i]; a[i] = a[minPos]; a[minPos] = t;
    }
}

int main()
{
    srand(time(0));

    int demo[] = {29, 10, 14, 37, 13, 5};
    cout << "before: ";
    for (int i = 0; i < 6; i++) cout << demo[i] << " ";
    selectionSort(demo, 6);
    cout << "\nafter:  ";
    for (int i = 0; i < 6; i++) cout << demo[i] << " ";
    cout << "\n\n";

    int sizes[] = {2000, 4000, 8000, 16000, 32000};
    cout << "      n     time(ms)\n";
    for (int s = 0; s < 5; s++) {
        int n = sizes[s];
        int *a = new int[n];
        for (int i = 0; i < n; i++) a[i] = rand();

        clock_t start = clock();
        selectionSort(a, n);
        clock_t end = clock();
        double ms = (double)(end - start) / CLOCKS_PER_SEC * 1000;

        cout << setw(8) << n << setw(12) << fixed << setprecision(2) << ms << "\n";
        delete[] a;
    }
    return 0;
}
