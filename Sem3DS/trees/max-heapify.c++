#include <bits/stdc++.h>
using namespace std;

void maxHeapifyDown(vector<int>& arr, int n, int i)
{
    while (true)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        // Step 4: Check the left child
        if (left < n && arr[left] > arr[largest])
        {
            largest = left;
        }

        // Step 5: Check the right child
        if (right < n && arr[right] > arr[largest])
        {
            largest = right;
        }

        // Step 6: If the current node is the largest, stop
        if (largest == i)
        {
            break;
        }

        // Step 7: Swap with the largest child
        swap(arr[i], arr[largest]);

        // Step 8: Move down to the child's index
        i = largest;
    }
}

int main()
{
    vector<int> arr = {10, 20, 5, 30, 40, 15};
    int n = arr.size();

    maxHeapifyDown(arr, n, 0);

    cout << "Max-Heap after Heapify-Down: ";

    for (int x : arr)
    {
        cout << x << " ";
    }

    return 0;
}