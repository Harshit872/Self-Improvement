#include<bits/stdc++.h>
using namespace std;

void insertionmaxheap(vector<int> &heap,int value){
    heap.push_back(value);
    int i = heap.size() -1;
    
    while(i>0){
        int p = (i-1)/2;
        if(heap[i] <=heap[p]) break;
        else
        {
            swap(heap[p],heap[i]);
        }
        i=p;
        
    }
}

int main()
{
    vector<int> heap = {25, 13, 16, 12, 10, 8, 14};

    int value = 20;

    insertionmaxheap(heap, value);

    cout << "Max Heap after insertion: ";

    for (int x : heap)
    {
        cout << x << " ";
    }

    return 0;
}