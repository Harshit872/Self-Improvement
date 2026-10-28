
#include <bits/stdc++.h>
using namespace std;

void maxheapify(int A[], int i, int n)
{
    while (true)
    {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && A[left] > A[largest])
        {
            largest = left;
        }

        if (right < n && A[right] > A[largest])
        {
            largest = right;
        }

        if (largest == i)
        {
            break;
        }

        swap(A[i], A[largest]);
        i = largest;
    }
}

int deletekthMaximum(int A[], int &n, int k)
{
    if (k < 1 || k > n)
    {
        cout << "Invalid rank!" << endl;
        return -1;
    }

    int deleted = -1;

    for (int i = 1; i <= k; i++)
    {
        deleted = A[0];
        A[0] = A[n - 1];
        n--;

        if (n > 0)
        {
            maxheapify(A, 0, n);
        }
    }

    return deleted;
}

int main()
{
    int A[] = {90, 70, 80, 40, 50, 60, 75};
    int n = 7;
    int k = 3;

    cout << "Before deletion heap is:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;

    int result = deletekthMaximum(A, n, k);

    if (result != -1)
    {
        cout << "Kth maximum deleted: " << result << endl;

        cout << "After deletion heap is:" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
