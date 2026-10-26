#include <bits/stdc++.h>
using namespace std;

void maxheapifydown(vector<int> &heap, int n, int i) {
    while (true) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && heap[left] > heap[largest]) largest = left;
        if (right < n && heap[right] > heap[largest]) largest = right;
        if (largest == i) break;

        swap(heap[i], heap[largest]);
        i = largest;
    }
}

void heapsort(vector<int> &arr) {
    int n = arr.size();

    // 1. Build max-heap (bottom-up to root)
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxheapifydown(arr, n, i);
    }

    // 2. Extract elements one by one
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        maxheapifydown(arr, i, 0);
    }
}

void printVector(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << "\n";
}

int main() {
    vector<int> arr = {41, 12, 34, 10, 6, 4, 18, 55};

    cout << "Original array:\n";
    printVector(arr);

    heapsort(arr);

    cout << "Sorted array (Ascending Order):\n";
    printVector(arr);

    return 0;
}