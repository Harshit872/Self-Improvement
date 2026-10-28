#include<bits/stdc++.h>
using namespace std;

void minHeapify(int A[], int i, int n) {
    while (true) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && A[left] < A[smallest]) {
            smallest = left;
        }

        if (right < n && A[right] < A[smallest]) {
            smallest = right;
        }

        if (smallest == i) {
            break;
        }

        swap(A[i], A[smallest]);
        i = smallest;
    }
}

int deleteMin(int A[] , int &n){
    if(n==0){
        cout<<"Heap is empty" <<;
        return -1;
    }
    int deleted =A[0];
    A[0] = A[n-1];
    n--;
    if(n>0){
        minHeapify(A,0,n);
    }
    return deleted;
}

int main() {
    int A[] = {10, 20, 15, 40, 50, 30, 35};
    int n = 7;

    

    int deleted = deleteMin(A, n);

    if (deleted != -1) {
        cout << "Deleted element: " << deleted << endl;
    }

    cout << "Min Heap after deletion: ";
   

    return 0;
}
