#include <bits/stdc++.h>
using namespace std;

int deleteMin(vector<int>& heap, int& size)
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

    // Step 4-6: Restore min-heap property
    int i = 0;

    while (true)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < size &&
            heap[left] < heap[smallest])
        {
            smallest = left;
        }

        if (right < size &&
            heap[right] < heap[smallest])
        {
            smallest = right;
        }

        if (smallest == i)
            break;

        swap(heap[i], heap[smallest]);
        i = smallest;
    }

    // Step 7: Return deleted value
    return deleted;
}

int main()
{
    vector<int> heap = {2, 5, 8, 10, 12, 15};
    int size = heap.size();

    cout << "Deleted minimum: "
         << deleteMin(heap, size) << endl;

    cout << "Heap after deletion: ";
    for (int i = 0; i < size; i++)
        cout << heap[i] << " ";

    return 0;
}