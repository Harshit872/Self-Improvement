#include<bits/stdc++.h>
using namespace std;

void insertionminheap(vector<int> &heap,int value){
    heap.push_back(value);
    int i = heap.size() -1;
    
    while(i>0){
        int p = (i-1)/2;
        if(heap[i] >=heap[p]) break;
        else
        {
            swap(heap[p],heap[i]);
        }
        i=p;
        
    }
}

int main()
{
    vector<int> heap =  {8, 10, 14, 12, 13, 16, 15};

    int value = 20;

    insertionminheap(heap, value);

    cout << "Max Heap after insertion: ";

    for (int x : heap)
    {
        cout << x << " ";
    }

    return 0;
}