#include <bits/stdc++.h>
using namespace std;

int deleteMax(vector<int>& heap, int& size)
{
    if (size == 0)
    {
        cout << "Heap is empty!" << endl;
        return -1;
    }

    // Step 1: Store the root value
    int deleted = heap[0];

    // Step 2: Replace root with last element
    heap[0] = heap[size - 1];

    // Step 3: Reduce heap size
    size--;

    // Step 4-6: Restore max-heap property
    int i = 0;

    while (true)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (left < size &&
            heap[left] > heap[largest])
        {
            largest = left;
        }

        if (right < size &&
            heap[right] > heap[largest])
        {
            largest = right;
        }

        if (largest == i)
            break;

        swap(heap[i], heap[largest]);
        i = largest;
    }

    // Step 7: Return deleted value
    return deleted;
}

int main()
{
    vector<int> heap = {20, 15, 18, 8, 10, 12};
    int size = heap.size();

    cout << "Deleted maximum: "
         << deleteMax(heap, size) << endl;

    cout << "Heap after deletion: ";
    for (int i = 0; i < size; i++)
        cout << heap[i] << " ";

    return 0;
}