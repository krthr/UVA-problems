/**
* 11462 - Age Sort
* https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2457
*/


#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i) {
    int largest = i;  // Initialize largest as root
    int l = 2*i + 1;  // left = 2*i + 1
    int r = 2*i + 2;  // right = 2*i + 2

    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

/**
* I used HeapSort. Its O(nlogn) ;)
*/
void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);

    for (int i=n-1; i>=0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// Imprimir un array
void printArr(int arr[], int n) {
    cout << arr[0];
    for (int i = 1; i < n; i++)
        cout << " " << arr[i];

    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    while (true) {
        cin >> n;
        if (n == 0) break;
        
        int vect[n];
        for (int i = 0; i < n; i++) cin >> vect[i];

        heapSort(vect, n);
        printArr(vect, n);
    }

  return 0;
}
